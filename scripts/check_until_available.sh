#!/usr/bin/env bash
#
# 使用方式：
#   scripts/check_game_until_available.sh Pod名 版本号
#
# 示例：
#   scripts/check_game_until_available.sh OxAdjustPlugin 4.0.1-202609021600
#   scripts/check_game_until_available.sh OxSdkCore 1.3.6 --once
#   CHECK_INTERVAL_SECONDS=600 MAX_CHECKS=12 scripts/check_game_until_available.sh OxSdkForGames 1.3.6.1-RC02-202608181200

set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
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
  scripts/check_game_until_available.sh POD_NAME VERSION [--dry-run] [--once] [--help]

What it does:
  Check whether a pod can be found/pulled. It checks immediately, then
  retries every 1 minute until it succeeds.

Environment variables:
  CHECK_INTERVAL_SECONDS=60      Seconds between checks.
  MAX_CHECKS=0                   0 means retry forever.
  CHECK_MODE=search              "search", "spec", or "install".
  UPDATE_REPO_BEFORE_CHECK=1     Run pod repo update before each check.
  REPO_UPDATE_CMD="pod repo update"

Examples:
  scripts/check_game_until_available.sh OxAdjustPlugin 4.0.1-202609021600
  scripts/check_game_until_available.sh OxSdkCore 1.3.6 --once
  scripts/check_game_until_available.sh OxAdjustPlugin 4.0.1-202609021600 --dry-run
  CHECK_MODE=install scripts/check_game_until_available.sh OxSdkForGames 1.3.6.1-RC02-202608181200
  CHECK_INTERVAL_SECONDS=600 MAX_CHECKS=12 scripts/check_game_until_available.sh OxSdkForGames 1.3.6.1-RC02-202608181200
EOF
}

POSITIONAL_ARGS=()

while [[ $# -gt 0 ]]; do
  case "$1" in
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
      POSITIONAL_ARGS+=("$1")
      shift
      ;;
  esac
done

if [[ "${#POSITIONAL_ARGS[@]}" -ne 2 ]]; then
  usage >&2
  exit 2
fi

TARGET_POD_NAME="${POSITIONAL_ARGS[0]}"
TARGET_POD_VERSION="${POSITIONAL_ARGS[1]}"

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

build_check_command() {
  local pod_name="$1"
  local version="$2"

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
    osascript -e "display notification \"${message//\"/\\\"}\" with title \"Pod 可以使用了\"" >/dev/null 2>&1 || true
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

    if [[ "$CHECK_MODE" == "search" ]]; then
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
  local command
  local checks=0

  command="$(build_check_command "$TARGET_POD_NAME" "$TARGET_POD_VERSION")"

  log "Pod: $TARGET_POD_NAME $TARGET_POD_VERSION"
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

    if check_available "$TARGET_POD_NAME" "$TARGET_POD_VERSION" "$command"; then
      notify_done "$TARGET_POD_NAME $TARGET_POD_VERSION 可以使用 pod 了。"
      return 0
    fi

    if [[ "$ONCE" == "1" ]]; then
      die "没找到 $TARGET_POD_NAME $TARGET_POD_VERSION。"
    fi

    if [[ "$MAX_CHECKS" != "0" && "$checks" -ge "$MAX_CHECKS" ]]; then
      die "没找到 $TARGET_POD_NAME $TARGET_POD_VERSION，已经检查 $checks 次。"
    fi

    log "Next check in $CHECK_INTERVAL_SECONDS seconds."
    sleep "$CHECK_INTERVAL_SECONDS"
  done
}

main "$@"
