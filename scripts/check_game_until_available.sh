#!/usr/bin/env bash

set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
GAME_SPEC="${GAME_SPEC:-$ROOT_DIR/OxSdkForGames.podspec}"
GAME_NAME="${GAME_NAME:-}"
GAME_VERSION="${GAME_VERSION:-}"
POD="${POD:-pod}"
LOG_DIR="${LOG_DIR:-$ROOT_DIR/logs}"
CHECK_INTERVAL_SECONDS="${CHECK_INTERVAL_SECONDS:-60}"
MAX_CHECKS="${MAX_CHECKS:-0}"
CHECK_MODE="${CHECK_MODE:-search}"
UPDATE_REPO_BEFORE_CHECK="${UPDATE_REPO_BEFORE_CHECK:-1}"
REPO_UPDATE_CMD="${REPO_UPDATE_CMD:-$POD repo update}"
DRY_RUN="${DRY_RUN:-0}"
ONCE="${ONCE:-0}"

mkdir -p "$LOG_DIR"
LOG_FILE="$LOG_DIR/check_game_until_available_$(date '+%Y%m%d_%H%M%S').log"

usage() {
  cat <<EOF
Usage:
  scripts/check_game_until_available.sh VERSION [--dry-run] [--once] [--help]
  scripts/check_game_until_available.sh --version VERSION [--dry-run] [--once]

What it does:
  Check whether OxSdkForGames can be found/pulled. It checks immediately, then
  retries every 1 minute until it succeeds.

Environment variables:
  GAME_VERSION=...               Version to check if you do not pass VERSION.
  GAME_NAME=OxSdkForGames        Pod name to check. Defaults to podspec name.
  CHECK_INTERVAL_SECONDS=60      Seconds between checks.
  MAX_CHECKS=0                   0 means retry forever.
  CHECK_MODE=search              "search", "spec", or "install".
  UPDATE_REPO_BEFORE_CHECK=1     Run pod repo update before each check.
  REPO_UPDATE_CMD="pod repo update"
  GAME_CHECK_CMD=...             Override the check command completely.

Examples:
  scripts/check_game_until_available.sh 1.0-MO-ShowRateBooster-202608271301
  scripts/check_game_until_available.sh --version 1.0-MO-ShowRateBooster-202608271301
  scripts/check_game_until_available.sh 1.0-MO-ShowRateBooster-202608271301 --dry-run
  CHECK_MODE=install scripts/check_game_until_available.sh 1.0-MO-ShowRateBooster-202608271301
  CHECK_INTERVAL_SECONDS=600 MAX_CHECKS=12 scripts/check_game_until_available.sh 1.0-MO-ShowRateBooster-202608271301
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --version)
      [[ $# -ge 2 ]] || {
        printf 'Missing value for --version\n\n' >&2
        usage >&2
        exit 2
      }
      GAME_VERSION="$2"
      shift 2
      ;;
    --dry-run)
      DRY_RUN=1
      shift
      ;;
    --once)
      ONCE=1
      shift
      ;;
    --help|-h)
      usage
      exit 0
      ;;
    *)
      if [[ -z "$GAME_VERSION" ]]; then
        GAME_VERSION="$1"
        shift
      else
        printf 'Unexpected argument: %s\n\n' "$1" >&2
        usage >&2
        exit 2
      fi
      ;;
  esac
done

log() {
  local message="$1"
  printf '[%s] %s\n' "$(date '+%Y-%m-%d %H:%M:%S')" "$message" | tee -a "$LOG_FILE"
}

banner() {
  local message="$1"

  log "============================================================"
  log "$message"
  log "============================================================"
}

die() {
  log "ERROR: $1"
  exit 1
}

read_podspec_value() {
  local spec_file="$1"
  local key="$2"

  ruby - "$spec_file" "$key" <<'RUBY'
spec_file = ARGV.fetch(0)
key = ARGV.fetch(1)
content = File.read(spec_file)
match = content.match(/spec\.#{Regexp.escape(key)}\s*=\s*["']([^"']+)["']/)
abort "Cannot read spec.#{key} from #{spec_file}" unless match
puts match[1]
RUBY
}

build_check_command() {
  local pod_name="$1"
  local version="$2"

  if [[ -n "${GAME_CHECK_CMD:-}" ]]; then
    printf '%s' "$GAME_CHECK_CMD"
    return
  fi

  case "$CHECK_MODE" in
    search)
      printf '%q ' "$POD" search "$pod_name" --simple --no-ansi
      ;;
    spec)
      printf '%q ' "$POD" spec cat "$pod_name" "--version=$version" --no-ansi
      ;;
    install)
      local tmp_dir
      tmp_dir="$(mktemp -d)"
      printf 'cd %q && printf %%s\\\\n %q %q %q %q > Podfile && %q install --repo-update --no-ansi' \
        "$tmp_dir" \
        "platform :ios, '13.0'" \
        "target 'CheckPull' do" \
        "  pod '$pod_name', '$version'" \
        "end" \
        "$POD"
      ;;
    *)
      die "Unknown CHECK_MODE: $CHECK_MODE. Use search, spec, or install."
      ;;
  esac
}

notify_done() {
  local message="$1"

  printf '\a'
  log "$message"

  if command -v osascript >/dev/null 2>&1; then
    osascript -e "display notification \"${message//\"/\\\"}\" with title \"OxSDK Game 可以使用 pod 了\"" >/dev/null 2>&1 || true
  fi
}

update_repo() {
  local output_file

  if [[ "$UPDATE_REPO_BEFORE_CHECK" != "1" ]]; then
    return 0
  fi

  log "Updating CocoaPods repo before check..."
  log "Command: $REPO_UPDATE_CMD"

  output_file="$(mktemp)"

  if bash -lc "$REPO_UPDATE_CMD" >"$output_file" 2>&1; then
    cat "$output_file" >>"$LOG_FILE"
    rm -f "$output_file"
    log "CocoaPods repo update finished."
    return 0
  fi

  cat "$output_file" >>"$LOG_FILE"
  rm -f "$output_file"
  banner "更新 repo 失败，本次先不查询。"
  return 1
}

check_available() {
  local pod_name="$1"
  local version="$2"
  local command="$3"
  local output_file

  log "Checking $pod_name $version with CHECK_MODE=$CHECK_MODE..."
  log "Command: $command"

  if [[ "$DRY_RUN" == "1" ]]; then
    log "DRY_RUN=1, skipped actual check."
    return 0
  fi

  if ! update_repo; then
    return 1
  fi

  output_file="$(mktemp)"
  if bash -lc "$command" >"$output_file" 2>&1; then
    cat "$output_file" >>"$LOG_FILE"

    if [[ "$CHECK_MODE" == "search" || -n "${GAME_CHECK_CMD:-}" ]]; then
      if grep -F "$version" "$output_file" >/dev/null 2>&1; then
        banner "$pod_name $version 可以使用 pod 了。"
        rm -f "$output_file"
        return 0
      fi

      banner "没找到 $pod_name $version，继续等。"
      rm -f "$output_file"
      return 1
    fi

    banner "$pod_name $version 可以使用 pod 了。"
    rm -f "$output_file"
    return 0
  fi

  cat "$output_file" >>"$LOG_FILE"
  rm -f "$output_file"
  banner "没找到 $pod_name $version，继续等。"
  return 1
}

main() {
  [[ -f "$GAME_SPEC" ]] || die "Game podspec not found: $GAME_SPEC"
  [[ -n "$GAME_VERSION" ]] || {
    usage >&2
    die "Please pass the game version, for example: scripts/check_game_until_available.sh 1.0-MO-ShowRateBooster-202608271301"
  }

  local game_name
  local command
  local checks=0

  if [[ -n "$GAME_NAME" ]]; then
    game_name="$GAME_NAME"
  else
    game_name="$(read_podspec_value "$GAME_SPEC" "name")"
  fi

  command="$(build_check_command "$game_name" "$GAME_VERSION")"

  log "Game: $game_name $GAME_VERSION"
  log "Log file: $LOG_FILE"

  if [[ "$DRY_RUN" == "1" ]]; then
    if [[ "$UPDATE_REPO_BEFORE_CHECK" == "1" ]]; then
      log "DRY_RUN=1, repo update command preview:"
      log "Command: $REPO_UPDATE_CMD"
    fi
    log "DRY_RUN=1, check command preview:"
    log "Command: $command"
    return 0
  fi

  while true; do
    checks=$((checks + 1))

    if check_available "$game_name" "$GAME_VERSION" "$command"; then
      notify_done "$game_name $GAME_VERSION 可以使用 pod 了。"
      return 0
    fi

    if [[ "$ONCE" == "1" ]]; then
      die "没找到 $game_name $GAME_VERSION。"
    fi

    if [[ "$MAX_CHECKS" != "0" && "$checks" -ge "$MAX_CHECKS" ]]; then
      die "没找到 $game_name $GAME_VERSION，已经检查 $checks 次。"
    fi

    log "Next check in $CHECK_INTERVAL_SECONDS seconds."
    sleep "$CHECK_INTERVAL_SECONDS"
  done
}

main "$@"
