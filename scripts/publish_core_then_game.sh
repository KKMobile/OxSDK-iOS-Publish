#!/usr/bin/env bash

set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
CORE_SPEC="${CORE_SPEC:-$ROOT_DIR/OxSdkCore.podspec}"
GAME_SPEC="${GAME_SPEC:-$ROOT_DIR/OxSdkForGames.podspec}"

INITIAL_WAIT_SECONDS="${INITIAL_WAIT_SECONDS:-1800}"
CHECK_INTERVAL_SECONDS="${CHECK_INTERVAL_SECONDS:-1800}"
MAX_CHECKS="${MAX_CHECKS:-0}"
POD="${POD:-pod}"
LOG_DIR="${LOG_DIR:-$ROOT_DIR/logs}"
DRY_RUN="${DRY_RUN:-0}"
CHECK_MODE="${CHECK_MODE:-spec}"
ALLOW_WARNINGS="${ALLOW_WARNINGS:-1}"

mkdir -p "$LOG_DIR"
LOG_FILE="$LOG_DIR/publish_core_then_game_$(date '+%Y%m%d_%H%M%S').log"

usage() {
  cat <<EOF
Usage:
  scripts/publish_core_then_game.sh [--dry-run] [--help]

What it does:
  1. Publish OxSdkCore.
  2. Wait 30 minutes, then check every 30 minutes until OxSdkCore is available.
  3. Publish OxSdkForGames.
  4. Wait 30 minutes, then check every 30 minutes until OxSdkForGames is available.
  5. Print a completion message, ring the terminal bell, and try a macOS notification.

Common environment variables:
  INITIAL_WAIT_SECONDS=1800       Seconds before the first check after each publish.
  CHECK_INTERVAL_SECONDS=1800    Seconds between checks.
  MAX_CHECKS=0                   0 means retry forever.
  CHECK_MODE=spec                Use "spec" for pod spec cat, or "install" for pod install.
  ALLOW_WARNINGS=1               Add --allow-warnings to pod trunk push.
  CORE_PUBLISH_CMD=...           Override the core publish command.
  GAME_PUBLISH_CMD=...           Override the game publish command.
  CORE_CHECK_CMD=...             Override the core availability check command.
  GAME_CHECK_CMD=...             Override the game availability check command.

Examples:
  scripts/publish_core_then_game.sh --dry-run
  MAX_CHECKS=10 scripts/publish_core_then_game.sh
  CHECK_MODE=install scripts/publish_core_then_game.sh
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --dry-run)
      DRY_RUN=1
      shift
      ;;
    --help|-h)
      usage
      exit 0
      ;;
    *)
      printf 'Unknown argument: %s\n\n' "$1" >&2
      usage >&2
      exit 2
      ;;
  esac
done

log() {
  local message="$1"
  printf '[%s] %s\n' "$(date '+%Y-%m-%d %H:%M:%S')" "$message" | tee -a "$LOG_FILE"
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

build_publish_command() {
  local spec_file="$1"
  local package_name="$2"
  local short_name="$3"
  local env_name
  local short_env_name
  local allow_warnings_flag=()

  if [[ "$ALLOW_WARNINGS" == "1" ]]; then
    allow_warnings_flag+=(--allow-warnings)
  fi

  short_env_name="${short_name}_PUBLISH_CMD"
  if [[ -n "${!short_env_name:-}" ]]; then
    printf '%s' "${!short_env_name}"
    return
  fi

  env_name="PUBLISH_${package_name}_CMD"
  if [[ -n "${!env_name:-}" ]]; then
    printf '%s' "${!env_name}"
    return
  fi

  printf '%q ' "$POD" trunk push "$spec_file" "${allow_warnings_flag[@]}"
}

run_command() {
  local description="$1"
  local command="$2"

  log "$description"
  log "Command: $command"

  if [[ "$DRY_RUN" == "1" ]]; then
    log "DRY_RUN=1, skipped."
    return 0
  fi

  bash -lc "$command" 2>&1 | tee -a "$LOG_FILE"
}

spec_is_available() {
  local pod_name="$1"
  local version="$2"
  local short_name="$3"
  local env_name="CHECK_${pod_name}_CMD"
  local short_env_name="${short_name}_CHECK_CMD"
  local command

  if [[ -n "${!short_env_name:-}" ]]; then
    command="${!short_env_name}"
  elif [[ -n "${!env_name:-}" ]]; then
    command="${!env_name}"
  elif [[ "$CHECK_MODE" == "install" ]]; then
    local tmp_dir
    tmp_dir="$(mktemp -d)"
    command="cd $(printf '%q' "$tmp_dir") && printf '%s\n' \"platform :ios, '13.0'\" \"target 'CheckPull' do\" \"  pod '$pod_name', '$version'\" \"end\" > Podfile && $POD install --repo-update"
  else
    command="$POD spec cat $(printf '%q' "$pod_name") --version=$(printf '%q' "$version")"
  fi

  log "Checking whether $pod_name ($version) can be pulled..."
  log "Command: $command"

  if bash -lc "$command" >>"$LOG_FILE" 2>&1; then
    log "$pod_name ($version) is available."
    return 0
  fi

  log "$pod_name ($version) is not available yet."
  return 1
}

wait_until_available() {
  local pod_name="$1"
  local version="$2"
  local short_name="$3"
  local checks=0

  if [[ "$DRY_RUN" == "1" ]]; then
    log "DRY_RUN=1, skipped waiting and checking $pod_name."
    return 0
  fi

  log "Waiting $INITIAL_WAIT_SECONDS seconds before the first $pod_name check."
  sleep "$INITIAL_WAIT_SECONDS"

  while true; do
    checks=$((checks + 1))

    if spec_is_available "$pod_name" "$version" "$short_name"; then
      return 0
    fi

    if [[ "$MAX_CHECKS" != "0" && "$checks" -ge "$MAX_CHECKS" ]]; then
      die "$pod_name ($version) still cannot be pulled after $checks checks."
    fi

    log "Next $pod_name check in $CHECK_INTERVAL_SECONDS seconds."
    sleep "$CHECK_INTERVAL_SECONDS"
  done
}

notify_done() {
  local message="$1"

  printf '\a'
  log "$message"

  if command -v osascript >/dev/null 2>&1; then
    osascript -e "display notification \"${message//\"/\\\"}\" with title \"OxSDK 发布完成\"" >/dev/null 2>&1 || true
  fi
}

main() {
  [[ -f "$CORE_SPEC" ]] || die "Core podspec not found: $CORE_SPEC"
  [[ -f "$GAME_SPEC" ]] || die "Game podspec not found: $GAME_SPEC"

  local core_name
  local core_version
  local game_name
  local game_version
  local core_publish_command
  local game_publish_command

  core_name="$(read_podspec_value "$CORE_SPEC" "name")"
  core_version="$(read_podspec_value "$CORE_SPEC" "version")"
  game_name="$(read_podspec_value "$GAME_SPEC" "name")"
  game_version="$(read_podspec_value "$GAME_SPEC" "version")"

  log "Core: $core_name $core_version"
  log "Game: $game_name $game_version"
  log "Log file: $LOG_FILE"

  core_publish_command="$(build_publish_command "$CORE_SPEC" "$core_name" "CORE")"
  game_publish_command="$(build_publish_command "$GAME_SPEC" "$game_name" "GAME")"

  run_command "Publishing $core_name..." "$core_publish_command"
  wait_until_available "$core_name" "$core_version" "CORE"

  run_command "Publishing $game_name..." "$game_publish_command"
  wait_until_available "$game_name" "$game_version" "GAME"

  notify_done "$game_name $game_version 可以拉了。"
}

main "$@"
