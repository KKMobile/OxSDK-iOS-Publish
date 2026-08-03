#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""为 OxSdkCore 的 .m 文件批量添加中文注释（属性、方法、类）。"""

import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))

# 常见词根 -> 中文
WORD_MAP = {
    "ad": "广告", "ads": "广告", "load": "加载", "loaded": "已加载", "loading": "加载中",
    "fail": "失败", "failed": "失败", "success": "成功", "manager": "管理器", "config": "配置",
    "callback": "回调", "delegate": "代理", "listener": "监听器", "timeout": "超时",
    "cache": "缓存", "task": "任务", "controller": "控制器", "coordinator": "协调器",
    "generation": "批次", "ready": "就绪", "destroy": "销毁", "init": "初始化",
    "show": "展示", "display": "展示", "click": "点击", "close": "关闭", "closed": "已关闭",
    "request": "请求", "response": "响应", "error": "错误", "retry": "重试", "reload": "重载",
    "network": "网络", "consent": " consent", "gdpr": "GDPR", "max": "MAX", "admob": "AdMob",
    "interstitial": "插屏", "banner": "横幅", "rewarded": "激励", "reward": "奖励",
    "native": "原生", "open": "开屏", "mrec": "中矩形", "floor": "底价", "dynamic": "动态",
    "user": "用户", "value": "价值", "segment": "分群", "rule": "规则", "event": "事件",
    "track": "追踪", "placement": "广告位", "format": "格式", "unit": "单元", "id": "ID",
    "map": "映射", "list": "列表", "array": "数组", "count": "数量", "index": "索引",
    "stage": "阶段", "batch": "批次", "pending": "待完成", "result": "结果", "status": "状态",
    "flag": "标志", "lock": "锁", "block": "块", "queue": "队列", "thread": "线程",
    "main": "主", "weak": "弱引用", "strong": "强引用", "shared": "共享", "instance": "单例",
    "update": "更新", "apply": "应用", "check": "检查", "validate": "校验", "parse": "解析",
    "merge": "合并", "copy": "拷贝", "remove": "移除", "add": "添加", "get": "获取",
    "set": "设置", "is": "是否", "has": "是否有", "can": "能否", "should": "是否应",
    "start": "开始", "stop": "停止", "cancel": "取消", "finish": "完成", "handle": "处理",
    "create": "创建", "build": "构建", "execute": "执行", "register": "注册", "dispatch": "分发",
    "internal": "内部", "external": "外部", "params": "参数", "param": "参数", "info": "信息",
    "helper": "辅助", "util": "工具", "utils": "工具", "model": "模型", "bean": "数据模型",
    "repository": "仓库", "provider": "提供者", "service": "服务", "bus": "总线",
    "firebase": "Firebase", "adjust": "Adjust", "facebook": "Facebook", "firebase": "Firebase",
    "revenue": "收益", "ecpm": "eCPM", "waterfall": "瀑布流", "mediation": "聚合",
    "sdk": "SDK", "ox": "Ox", "pref": "偏好", "preference": "偏好", "install": "安装",
    "day": "天", "days": "天", "memory": "内存", "device": "设备", "view": "视图",
    "controller": "控制器", "popup": "弹窗", "privacy": "隐私", "custom": "自定义",
    "remote": "远程", "local": "本地", "assets": "资源", "enable": "启用", "disable": "禁用",
    "parallel": "并行", "serial": "串行", "concurrent": "并发", "weight": "权重",
}

ACTION_PREFIX = {
    "init": "初始化",
    "load": "加载",
    "show": "展示",
    "hide": "隐藏",
    "destroy": "销毁",
    "handle": "处理",
    "on": "回调：",
    "get": "获取",
    "set": "设置",
    "is": "判断是否为",
    "has": "判断是否包含",
    "can": "判断能否",
    "should": "判断是否应",
    "try": "尝试",
    "start": "开始",
    "stop": "停止",
    "cancel": "取消",
    "finish": "完成",
    "create": "创建",
    "build": "构建",
    "execute": "执行",
    "register": "注册",
    "update": "更新",
    "apply": "应用",
    "check": "检查",
    "prepare": "准备",
    "call": "调用",
    "track": "追踪",
    "add": "添加",
    "remove": "移除",
}


def has_chinese(s: str) -> bool:
    return bool(re.search(r"[\u4e00-\u9fff]", s))


def split_camel(name: str):
    parts = re.sub(r"([a-z])([A-Z])", r"\1 \2", name)
    parts = re.sub(r"[_\-]", " ", parts)
    return [p.lower() for p in parts.split() if p]


def translate_identifier(name: str) -> str:
    if not name or name in ("self", "super", "nil", "YES", "NO"):
        return name
    tokens = split_camel(name)
    out = []
    for t in tokens:
        out.append(WORD_MAP.get(t, t))
    return "".join(out) if out else name


def comment_for_property(prop_line: str) -> str:
    m = re.search(r"@property[^;]*\b(\w+)\s*;", prop_line)
    if not m:
        m = re.search(r"@property[^;]*\b(\w+)\s*\*", prop_line)
    if not m:
        return "/** 属性 */"
    name = m.group(1)
    desc = translate_identifier(name)
    type_hint = ""
    if "BOOL" in prop_line:
        type_hint = "布尔"
    elif "NSString" in prop_line:
        type_hint = "字符串"
    elif "NSInteger" in prop_line or "NSUInteger" in prop_line or "int" in prop_line:
        type_hint = "整数"
    elif "NSTimeInterval" in prop_line:
        type_hint = "时间间隔"
    elif re.search(r"\*\)", prop_line) or "*" in prop_line:
        type_hint = "对象"
    extra = f"（{type_hint}）" if type_hint else ""
    return f"/** {desc}{extra} */"


def comment_for_method(sig_line: str) -> str:
    sig = sig_line.strip()
    # 提取方法名（第一个冒号前或整个 selector）
    m = re.match(r"^[+\-]\s*\([^)]+\)\s*(\w+)", sig)
    if not m:
        return "/** 方法实现 */"
    first = m.group(1)
    for prefix, verb in ACTION_PREFIX.items():
        if first.startswith(prefix) or first.lower().startswith(prefix):
            rest = first[len(prefix):] if first.startswith(prefix) else first
            rest_desc = translate_identifier(rest) if rest else ""
            return f"/** {verb}{rest_desc} */"
    return f"/** {translate_identifier(first)} */"


def comment_for_class(impl_line: str) -> str:
    m = re.search(r"@implementation\s+(\w+)", impl_line)
    if not m:
        return None
    cls = m.group(1)
    desc = translate_identifier(cls.replace("Ox", "Ox").replace("ALC", "ALC"))
    return f"\n#pragma mark - {cls} 实现\n\n/** {cls}：{desc} */"


def process_file(path: str, dry_run: bool = False) -> bool:
    with open(path, "r", encoding="utf-8", errors="replace") as f:
        lines = f.readlines()

    out = []
    i = 0
    changed = False
    in_interface = False
    last_was_pragma = False

    while i < len(lines):
        line = lines[i]
        stripped = line.strip()

        # @implementation 类注释
        if stripped.startswith("@implementation") and not stripped.startswith("@implementation "):
            pass
        if re.match(r"^@implementation\s+\w+", stripped):
            if i == 0 or not has_chinese(lines[i - 1]):
                cls_comment = comment_for_class(stripped)
                if cls_comment and (i == 0 or "/**" not in lines[i - 1]):
                    out.append(cls_comment + "\n")
                    changed = True
            out.append(line)
            i += 1
            continue

        # @interface 私有类扩展
        if stripped.startswith("@interface"):
            in_interface = True
            out.append(line)
            i += 1
            continue
        if stripped.startswith("@end") and in_interface:
            in_interface = False
            out.append(line)
            i += 1
            continue

        # @property 注释
        if in_interface and "@property" in stripped:
            prev = out[-1].strip() if out else ""
            if not has_chinese(prev) and not prev.startswith("/**"):
                out.append(comment_for_property(stripped) + "\n")
                changed = True
            out.append(line)
            i += 1
            continue

        # 方法实现注释
        if re.match(r"^[+\-]\s*\(", stripped):
            prev = out[-1].strip() if out else ""
            # 跳过已有中文注释、#pragma、@end、空行后的 /** 
            skip = False
            if prev.startswith("#pragma"):
                last_was_pragma = True
            if has_chinese(prev) or prev.startswith("/**") or prev.startswith("*"):
                skip = True
            if not skip and prev == "" and len(out) >= 2:
                p2 = out[-2].strip()
                if has_chinese(p2) or p2.startswith("/**"):
                    skip = True
            if not skip:
                cmt = comment_for_method(stripped)
                out.append(cmt + "\n")
                changed = True
            out.append(line)
            i += 1
            continue

        # #pragma mark 中文
        if stripped.startswith("#pragma mark") and not has_chinese(stripped):
            m = re.search(r"#pragma mark\s*-?\s*(.+)", stripped)
            if m:
                section = m.group(1).strip()
                if section and not has_chinese(section):
                    cn = translate_identifier(section.replace("/", " ").replace(" ", ""))
                    out.append(f"#pragma mark - {section}（{cn}）\n")
                    changed = True
                    i += 1
                    continue

        out.append(line)
        i += 1

    if changed and not dry_run:
        with open(path, "w", encoding="utf-8") as f:
            f.writelines(out)
    return changed


def main():
    dry = "--dry-run" in sys.argv
    count = 0
    for dirpath, _, filenames in os.walk(ROOT):
        if "scripts" in dirpath:
            continue
        for fn in filenames:
            if not fn.endswith(".m"):
                continue
            path = os.path.join(dirpath, fn)
            if process_file(path, dry_run=dry):
                count += 1
                print("updated:", path)
    print(f"done, {'would update' if dry else 'updated'} {count} files")


if __name__ == "__main__":
    main()
