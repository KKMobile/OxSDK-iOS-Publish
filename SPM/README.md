# OxSdkCore 二进制 SPM 分发

开发仓库 `Mavl-AdSDK-Game` 保存实现源码，本发布仓库保存 `Package.swift`、少量资源支持代码和资源。接入方通过 GitHub URL 添加包，Core 从 GitHub Release 下载 XCFramework，不直接下载 Core 的 `.m` 实现源码。

当前只发布 `OxSdkCore` 产品，Adapter、Plugin、Games 聚合产品不在本轮分发范围内。最低 iOS 15，Xcode 15 / Swift tools 5.9 及以上。

## 当前准备结果

2026-11-09 已在本地生成 `0.1.0-spm.1` 候选包，并使用 Xcode 26.3 完成：

- Core Release 二进制：iOS arm64、模拟器 arm64 / x86_64 构建通过。
- 独立二进制接入：真机和模拟器目标的模块导入、公开 API 调用及动态 Framework 链接通过。
- 正式 HTTPS 清单解析通过，ZIP 校验值与清单一致，ZIP 中没有实现源码。
- 保留原 SDK 的公开头文件；`OxMaxNativeInterstitialAd.h` 现有两处 nullability 声明警告尚未修改。

当前没有执行提交、打 Tag、推送或 GitHub Release 发布，因此远程 URL 暂未完成真实下载验证。App 内的图片、多语言和广告运行测试仍待执行。

## 本地准备一次发布

在本仓库根目录运行，版本必须符合 SPM 的三段式 SemVer，例如 `0.1.0-spm.1`。这是首次 SPM 验证的暂定预发布版本，不代表已经在 GitHub 发布；不要直接使用 CocoaPods 的 `core-4.5-...` Tag。

```sh
python3 scripts/prepare_spm_core_release.py \
  --source ../Mavl-AdSDK-Game \
  --version 0.1.0-spm.1
```

可通过 `--package-cache /绝对路径/SourcePackages` 复用 Xcode 依赖缓存。脚本只读取原始开发仓库，在本仓库 `.build/` 中构建副本，不修改原始源码，不执行 Git commit、Tag、push 或上传。

脚本执行以下步骤：

1. 用六个官方 SPM 依赖构建 Core 的 Release 目标。
2. 仅归档 Core 的目标代码，不将 AppLovin、Google、PureLayout 等第三方 SDK 合并进 Core。
3. 生成 XCFramework：iOS arm64、iOS Simulator arm64 / x86_64。
4. 将公开头文件复制进 Framework；发布包中的头文件不再引用开发机源码路径。
5. 生成 `SPM/Artifacts/<版本>/OxSdkCore.xcframework.zip` 和 SHA-256 校验值。
6. 更新根目录 `Package.swift` 的 HTTPS 下载地址和校验值，同步资源及依赖版本记录。

`SPM/Artifacts/` 和 `.build/` 已忽略。**不要把构建副本提交到公共仓库，里面包含用于编译的实现源码。** 上传 Release 的是 XCFramework ZIP。

## 发布前验证

```sh
python3 scripts/verify_spm_core_release.py \
  SPM/Artifacts/0.1.0-spm.1/release.json
```

验证使用刚生成的二进制及正式的依赖/资源配置，构建独立宿主动态 Framework，检查 `@import OxSdkCore`、`OxPreferenceManager` 和资源接口的编译与链接，分别覆盖真机和模拟器。验证阶段的本地路径仅用于 GitHub 文件上传前测试；根目录正式清单使用 HTTPS 下载地址。

这项检查不能代替真实 App 的广告、图片、多语言测试，也不能证明尚未上传的 GitHub URL 可下载。

## 真正发布到 GitHub

本地准备成功后，需要由发布人完成：

1. 审核并提交根目录 `Package.swift`、`Package.resolved`、`.gitignore`、`SPM/` 中的配置/支持代码/资源，以及两个 Python 脚本。不要提交 `SPM/Artifacts/` 或 `.build/`。
2. 在该提交上创建并推送与清单下载地址一致的 Tag，例如 `0.1.0-spm.1`，并将提交推送到 `KKMobile/OxSDK-iOS-Publish`。
3. 在该 Tag 下创建 GitHub Release，上传 `SPM/Artifacts/0.1.0-spm.1/OxSdkCore.xcframework.zip`。必须上传 ZIP 资产，GitHub 自动生成的 Source code ZIP 不能替代 XCFramework。
4. 发布 Release，并核对清单中的下载 URL 能直接下载相同 ZIP。Release 资产更换后校验值会变化；已发布版本应保留原资产，用新版本发布更新。
5. 在独立 App 中移除原来的本地 OxSDK 包引用，通过下面的 GitHub URL 添加包，选择该版本，编译并运行测试。

公开仓库 + 公开 Release 的接入方无需该仓库的写入权限。私有仓库则需访问权限；本方案没有为私有 Release 资产实现额外鉴权。

## 接入方操作

Xcode → File → Add Package Dependencies，填写：

```text
https://github.com/KKMobile/OxSDK-iOS-Publish.git
```

Dependency Rule 选择 Exact Version，填写已经发布的 SPM Tag，例如 `0.1.0-spm.1`，将 `OxSdkCore` 产品加入 App Target。

App Target 的 Other Linker Flags 保留 `$(inherited)`，添加 `-ObjC`。Objective-C 使用 `@import OxSdkCore;`，Swift 使用 `import OxSdkCore`。

Core 和相同的第三方广告 SDK 应由一种包管理方式提供，避免同时从 CocoaPods 重复引入。Google App ID、广告平台配置和隐私配置仍需宿主 App 按各平台要求完成。

## 二进制资源与依赖

资源通过 `OxSdkCoreSupport` 源码目标自动加入宿主 App。Core 二进制调用支持目标提供的资源容器函数，从其中读取 `OxSdkRes.bundle` 和 `Language.bundle`；隐私清单也位于该资源包中。不依赖开发机路径，也无需接入方手动复制资源。

六个官方依赖的地址、版本和 Product 记录在 `SPM/core-dependencies.json`，与已验证的源码 SPM 版本一致：PureLayout 3.1.9、Google Mobile Ads 13.7.0、UMP 2.6.0、AppLovin 13.2.0，以及 MAX Google / Google Ad Manager Adapter 的 SPM Tag 13070000.0.0。

二进制分发隐藏实现源码；公开头文件、资源和 Objective-C 符号仍可被接入方查看。
