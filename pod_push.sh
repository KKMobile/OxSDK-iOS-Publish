#!/usr/bin/env bash
#
# ============================================================================
#  pod_push.sh - 交互式上传 OxSdkCore / OxSdkForGames 等 Podspec (macOS 版)
#  上传成功后自动触发 check_game_until_available.sh 查询是否可用
# ============================================================================
#
#  【使用示例】
#
#    1. 赋予执行权限(仅第一次需要):
#         chmod +x pod_push.sh
#         chmod +x scripts/check_game_until_available.sh
#
#    2. 进入存放 .podspec 文件的目录,然后运行:
#         ./pod_push.sh
#
#    3. 按提示选择要上传的 Pod:
#        请选择要上传的 Pod:
#          1) OxSdkCore
#          2) OxSdkForGames
#          3) 其他(手动输入 podspec 名称)
#        请输入序号: 2
#
#    4. 上传成功后会询问/自动执行查询脚本:
#         scripts/check_game_until_available.sh OxSdkCore 1.3.6
#
# ----------------------------------------------------------------------------
#  【上传成功后的自动查询】
#
#    - 默认开启:AUTO_CHECK_AFTER_SUCCESS=1
#    - 查询脚本路径:AUTO_CHECK_SCRIPT(默认 scripts/check_game_until_available.sh)
#    - Pod 名:从 podspec 文件名去掉 .podspec 得到(如 OxSdkCore.podspec -> OxSdkCore)
#    - 版本号:从 podspec 文件里解析 s.version / spec.version
#    - 若脚本不存在或解析不到版本号,会提示并跳过查询,不影响上传成功结果
#
# ----------------------------------------------------------------------------
#  【注意事项(macOS)】
#
#    1. 时区:已强制 export TZ='Asia/Shanghai',按北京时间计算 17:30。
#
#    2. bash 版本:macOS 自带 /bin/bash 是 3.2,本脚本已规避关联数组
#       和空数组配合 set -u 展开报错的问题。
#
#    3. 必须在 podspec 所在目录运行。
#
#    4. 认证与权限:上传前确保已 pod trunk register 并验证邮箱。
#
#    5. 验证错误会立即停止,需手动修复后重新运行。
#
#    6. 错误分类基于关键词匹配,若分类不准请补充 grep 模式。
#
#    7. 附加参数在顶部 TARGET_EXTRA_1/2/3 配置。
#
#    8. 通知默认用 macOS osascript。
#
#    9. 长时间运行建议用 caffeinate 防止睡眠: caffeinate -i ./pod_push.sh
#
#   10. 退出码: 0=成功, 1=参数/文件错误, 2=Podspec 验证失败
#
# ============================================================================

set -uo pipefail

# ---- macOS: 强制按北京时间计算 ----
export TZ='Asia/Shanghai'

# ============ 可配置项 ============

# 可选的上传目标(用普通数组,兼容 bash 3.2)
TARGET_NAMES=("OxSdkCore" "OxSdkForGames")
TARGET_FILES=("OxSdkCore.podspec" "OxSdkForGames.podspec")

# 每个目标对应的额外参数(留空表示不追加)
TARGET_EXTRA_1=""                              # OxSdkCore
TARGET_EXTRA_2="--allow-warnings"              # OxSdkForGames
TARGET_EXTRA_3=""                              # 其他(手动输入时默认不追加)

# 网络重试策略
IMMEDIATE_RETRIES=3          # 立即重试次数
RETRY_WAIT_SECONDS=1         # 每次重试前等待秒数
SCHEDULE_HOUR=17             # 北京时间下午 5 点
SCHEDULE_MINUTE=30           # 30 分

# ---- 上传成功后自动查询 ----
AUTO_CHECK_AFTER_SUCCESS="${AUTO_CHECK_AFTER_SUCCESS:-1}"   # 1=开启, 0=关闭
AUTO_CHECK_SCRIPT="${AUTO_CHECK_SCRIPT:-scripts/check_game_until_available.sh}"

# ============ 工具函数 ============

log() {
  echo "[$(date '+%Y-%m-%d %H:%M:%S')] $*"
}

progress() {
  echo "    >>> [${1}/5] ${2}"
}

is_scheduled_time() {
  local now_h now_m
  now_h=$(date +%H)
  now_m=$(date +%M)
  now_h=$((10#$now_h))
  now_m=$((10#$now_m))
  if [[ "$now_h" -eq "$SCHEDULE_HOUR" && "$now_m" -ge "$SCHEDULE_MINUTE" ]]; then
    return 0
  fi
  return 1
}

seconds_until_scheduled() {
  local now_epoch target_epoch
  now_epoch=$(date +%s)

  target_epoch=$(date -j -f "%Y-%m-%d %H:%M:%S" \
    "$(date +%Y-%m-%d) ${SCHEDULE_HOUR}:${SCHEDULE_MINUTE}:00" +%s 2>/dev/null)

  if [[ -z "$target_epoch" ]]; then
    local today0
    today0=$(date -j -f "%Y-%m-%d %H:%M:%S" "$(date +%Y-%m-%d) 00:00:00" +%s)
    target_epoch=$((today0 + SCHEDULE_HOUR * 3600 + SCHEDULE_MINUTE * 60))
  fi

  if [[ "$target_epoch" -le "$now_epoch" ]]; then
    target_epoch=$((target_epoch + 86400))
  fi
  echo $((target_epoch - now_epoch))
}

classify_error() {
  local output="$1"

  if echo "$output" | grep -qiE \
      "does not point to an existing podspec|Unable to read the license|Unable to accept duplicate entry|is already taken|Unrecognized .swift_version|Source code for your Pod was not accessible|Unable to find a specification|spec lint|did not pass validation|does not pass validation|is not valid"; then
    echo "validation"
    return
  fi

  if echo "$output" | grep -qiE \
      "CDN: trunk URL couldn't be downloaded|Couldn't connect to server|Connection timed out|Operation timed out|Network is unreachable|Could not resolve host|Failed to connect|timed out|SocketError|Errno::ECONN|TLS|SSL"; then
    echo "network"
    return
  fi

  echo "unknown"
}

notify() {
  local msg="$1"
  log "【通知】$msg"
  if command -v osascript >/dev/null 2>&1; then
    osascript -e "display notification \"${msg//\"/\\\"}\" with title \"Pod Push\"" 2>/dev/null || true
  fi
}

# 执行一次 push
do_push() {
  local podspec="$1"
  local extra="$2"
  local tmp_out
  tmp_out=$(mktemp)

  if [[ -n "$extra" ]]; then
    log "开始执行: pod trunk push ${podspec} ${extra} --verbose"
  else
    log "开始执行: pod trunk push ${podspec} --verbose"
  fi

  progress 1 "准备上传"

  pod trunk push "$podspec" ${extra:+"$extra"} --verbose >"$tmp_out" 2>&1 &
  local pod_pid=$!

  tail -n +1 -f "$tmp_out" 2>/dev/null | while IFS= read -r line; do
    echo "$line"
    case "$line" in
      *"Validating spec"*|*"Linting"*|*"-> OxSdk"*)
        progress 2 "验证 podspec (本地 lint)"
        ;;
      *"Pushing the spec"*|*"Uploading"*|*"Trunk"*)
        progress 3 "上传到 Trunk 服务器"
        ;;
      *"Verifying"*|*"Pushing"*)
        progress 4 "服务端验证"
        ;;
      *"Successfully pushed"*|*"published"*)
        progress 5 "完成"
        ;;
    esac
  done &
  local tail_pid=$!

  wait "$pod_pid"
  local exit_code=$?

  sleep 0.3
  kill "$tail_pid" 2>/dev/null || true
  wait "$tail_pid" 2>/dev/null || true

  cat "$tmp_out"
  local full_output
  full_output=$(cat "$tmp_out")
  rm -f "$tmp_out"

  LAST_OUTPUT="$full_output"
  return "$exit_code"
}

LAST_OUTPUT=""

# ============ 从 podspec 解析版本号 ============
# 支持写法:
#   s.version          = '1.3.6'
#   spec.version       = "1.3.6"
#   s.version = "1.3.6"
extract_version_from_podspec() {
  local podspec="$1"
  local ver=""

  # 去掉行首空格,匹配 version = '...' 或 "..."
  ver=$(grep -Eo "\.version[[:space:]]*=[[:space:]]*['\"][^'\"]+['\"]" "$podspec" \
        | head -n 1 \
        | sed -E "s/.*['\"]([^'\"]+)['\"].*/\1/")

  echo "$ver"
}

# ============ 上传成功后自动触发查询脚本 ============
run_auto_check() {
  local podspec="$1"

  if [[ "$AUTO_CHECK_AFTER_SUCCESS" != "1" ]]; then
    log "AUTO_CHECK_AFTER_SUCCESS=0,跳过自动查询。"
    return 0
  fi

  if [[ ! -f "$AUTO_CHECK_SCRIPT" ]]; then
    log "⚠️ 未找到查询脚本: $AUTO_CHECK_SCRIPT,跳过自动查询。"
    log "   可通过 AUTO_CHECK_SCRIPT=路径 指定,或在 podspec 所在目录准备该脚本。"
    return 0
  fi

  local pod_name
  pod_name="$(basename "$podspec" .podspec)"

  local version
  version="$(extract_version_from_podspec "$podspec")"

  if [[ -z "$version" ]]; then
    log "⚠️ 无法从 $podspec 解析版本号,跳过自动查询。"
    return 0
  fi

  log "上传成功,开始自动查询: $pod_name $version"
  notify "上传成功,开始查询 $pod_name $version 是否可用"

  # 用 bash 执行,继承当前环境;失败也不影响主流程的退出码
  if bash "$AUTO_CHECK_SCRIPT" "$pod_name" "$version"; then
    log "✅ 查询脚本执行完成:$pod_name $version 已可用。"
  else
    log "⚠️ 查询脚本返回非 0(可能超时/未找到),但不影响上传成功结果。"
  fi
}

# ============ 主流程 ============

main() {
  log "===== Pod Push 脚本启动 (macOS) ====="
  log "当前北京时间: $(date '+%Y-%m-%d %H:%M:%S')"

  echo "请选择要上传的 Pod:"
  local i=1
  local count=${#TARGET_NAMES[@]}
  while [[ "$i" -le "$count" ]]; do
    echo "  $i) ${TARGET_NAMES[$((i-1))]}"
    i=$((i+1))
  done
  echo "  $((count+1))) 其他(手动输入 podspec 名称)"

  read -r -p "请输入序号: " choice

  local podspec=""
  local extra=""

  if [[ "$choice" =~ ^[0-9]+$ ]] && [[ "$choice" -ge 1 && "$choice" -le "$count" ]]; then
    podspec="${TARGET_FILES[$((choice-1))]}"
    if [[ "$choice" -eq 1 ]]; then
      extra="$TARGET_EXTRA_1"
    elif [[ "$choice" -eq 2 ]]; then
      extra="$TARGET_EXTRA_2"
    fi
  else
    read -r -p "请输入 podspec 文件名(例如 MyPod.podspec): " custom
    if [[ -z "$custom" ]]; then
      log "未输入 podspec 文件名,退出。"
      exit 1
    fi
    podspec="$custom"
    [[ "$podspec" != *.podspec ]] && podspec="${podspec}.podspec"
    extra="$TARGET_EXTRA_3"
  fi

  if [[ ! -f "$podspec" ]]; then
    log "错误: 当前目录下找不到 $podspec"
    notify "Pod Push 失败: 找不到 $podspec"
    exit 1
  fi

  log "已选择 podspec: $podspec"
  if [[ -n "$extra" ]]; then
    log "附加参数: $extra"
  fi

  while true; do
    local attempt=1
    while [[ "$attempt" -le "$IMMEDIATE_RETRIES" ]]; do
      local attempt_start
      attempt_start=$(date +%s)
      log "第 $attempt / $IMMEDIATE_RETRIES 次尝试上传..."

      do_push "$podspec" "$extra"
      local exit_code=$?
      local output="$LAST_OUTPUT"

      local elapsed=$(( $(date +%s) - attempt_start ))

      if [[ "$exit_code" -eq 0 ]]; then
        log "✅ 上传成功! 本次耗时 ${elapsed}s"
        notify "Pod Push 成功: $podspec"

        # ---- 上传成功后自动触发查询 ----
        run_auto_check "$podspec"

        exit 0
      fi

      local err_type
      err_type=$(classify_error "$output")
      log "上传失败,错误类型: $err_type (本次耗时 ${elapsed}s)"

      case "$err_type" in
        validation)
          log "❌ 检测到 Podspec 文件或验证错误,停止重试。"
          log "--- 失败输出开始 ---"
          echo "$output"
          log "--- 失败输出结束 ---"
          notify "Pod Push 失败(验证错误): $podspec,请手动修复后重试"
          exit 2
          ;;
        network)
          log "🌐 网络问题,${RETRY_WAIT_SECONDS}s 后重试..."
          sleep "$RETRY_WAIT_SECONDS"
          ;;
        *)
          log "⚠️ 未识别的错误,${RETRY_WAIT_SECONDS}s 后重试..."
          sleep "$RETRY_WAIT_SECONDS"
          ;;
      esac

      attempt=$((attempt+1))
    done

    log "连续 $IMMEDIATE_RETRIES 次重试失败。"

    if is_scheduled_time; then
      log "当前已是/超过北京时间 ${SCHEDULE_HOUR}:${SCHEDULE_MINUTE},立即继续重试..."
    else
      local wait_s
      wait_s=$(seconds_until_scheduled)
      log "将等待 ${wait_s} 秒,直到北京时间 ${SCHEDULE_HOUR}:${SCHEDULE_MINUTE} 后继续重试..."
      notify "Pod Push 失败,将在北京时间 ${SCHEDULE_HOUR}:${SCHEDULE_MINUTE} 后继续重试"
      sleep "$wait_s"
    fi

    log "到达计划时间,重新开始重试循环。"
  done
}

main "$@"
