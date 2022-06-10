# Sdk 发布流程
## 制作 Framework
- 新建 Framework 工程
<img width="730" alt="image-20220610171658258" src="https://user-images.githubusercontent.com/38090845/173037313-f243f624-c45b-40c6-8e2c-80842754a164.png">
- 设置支持的最低版本
<img width="724" alt="image-20220610172320608" src="https://user-images.githubusercontent.com/38090845/173037473-5d254f69-1882-4fc3-afef-45e684ba21b4.png">
- 设置支持的平台
<img width="835" alt="image-20220610172420223" src="https://user-images.githubusercontent.com/38090845/173037627-685015cb-1de4-4510-b726-b03519a539f4.png">
- 修改 Build Settings
<img width="873" alt="image-20220610172659787" src="https://user-images.githubusercontent.com/38090845/173037734-b04a2c49-ab20-432c-b9f3-d9b7f6c5bfe8.png">
<img width="878" alt="image-20220610172747171" src="https://user-images.githubusercontent.com/38090845/173037764-f1a6bd11-a24e-492d-8f24-87bed6d0726a.png">
<img width="865" alt="image-20220610172810418" src="https://user-images.githubusercontent.com/38090845/173037791-d1bf3147-b839-4f88-a00f-66e5ad250aa8.png">
- 添加脚本，用于自动合成模拟器和真机使用的 Framework
<img width="859" alt="image-20220610173254660" src="https://user-images.githubusercontent.com/38090845/173037990-0ddf9627-602b-46e4-9344-f083e08f53ae.png">
<img width="1003" alt="image" src="https://user-images.githubusercontent.com/38090845/173039306-628c3462-76da-4e12-b723-f96431f454d9.png">

``` js
# Type a script or drag a script file from your workspace to insert its path.
if [ "${ACTION}" = "build" ]
then
INSTALL_DIR=${SRCROOT}/Products/${PROJECT_NAME}.framework

DEVICE_DIR=${BUILD_ROOT}/${CONFIGURATION}-iphoneos/${PROJECT_NAME}.framework

SIMULATOR_DIR=${BUILD_ROOT}/${CONFIGURATION}-iphonesimulator/${PROJECT_NAME}.framework

# 如果真机包或模拟包不存在，则退出合并
if [ ! -d "${DEVICE_DIR}" ] || [ ! -d "${SIMULATOR_DIR}" ]
then
exit 0
fi

# 如果合并包已经存在，则替换
if [ -d "${INSTALL_DIR}" ]
then
rm -rf "${INSTALL_DIR}"
fi

mkdir -p "${INSTALL_DIR}"

cp -R "${DEVICE_DIR}/" "${INSTALL_DIR}/"

# 使用lipo命令将其合并成一个通用framework  
# 最后将生成的通用framework放置在工程根目录下新建的Products目录下  
lipo -create "${DEVICE_DIR}/${PROJECT_NAME}" "${SIMULATOR_DIR}/${PROJECT_NAME}" -output "${INSTALL_DIR}/${PROJECT_NAME}"

#合并完成后打开目录
open "${SRCROOT}/Products"

fi
```
- 将 Sdk 中的文件拖入当前工程。
- 设置公开的头文件
1. 在创建工程时生成的.h 文件中添加需要公开的头文件。
<img width="860" alt="image" src="https://user-images.githubusercontent.com/38090845/173040435-61d6e56c-8e87-4436-9f2f-89279a9e116c.png">
2.在 target/build phases/headers 中挪动需要公开的头文件（从 Project 拖到 Public）。
<img width="1002" alt="image" src="https://user-images.githubusercontent.com/38090845/173040707-60c3c21d-4d7b-4c84-96f0-7efcec5bb6b7.png">

- 分别选择模拟器和 Any iOS Device(arm64 ,armv7) 运行项目，生成 framework
- 检查生成的 framework 支持的架构（需要支持 arm64、armv7、x86_64）

```
lipo -info [文件路径]
```

## 将 Framework 上传至 CocoaPods
- 在 Github 创建 public 仓库（创建时勾选 LICENSE/MIT，也可手动创建文件）。
- 将仓库 clone 到本地
- 在根目录创建文件夹，一般命名为 Framework，将制作好的 xxx.framework 文件夹置入其中。
- 在根目录创建 cocoapods 配置文件 xxx.podspec

```
pod spec create xxx
```

- 配置 xxx.podspec 文件

```
Pod::Spec.new do |spec|


  spec.name         = "OxSdkForTools"#SDK名称
  spec.version      = "1.0.1-patch2-alpha"#版本号
  spec.summary      = "OxAdSdk for tools applications."#概要
#描述  （描述一定要比概要多一些,不然会有警告!）
  spec.description  = <<-DESC
  OxAdSdk for tools applications.OxAdSdk for tools applications.
                   DESC
  spec.homepage     = "https://github.com/KKMobile/OxSDK-iOS-Publish.git"#github 上的仓库地址
  spec.license      = { :type => "MIT", :file => "LICENSE" }#创建GitHub仓库时使用的license类型
  spec.author             = { "OxDevelopers" => "tianci5275@gmail.com" }#作者
  spec.platform     = :ios#支持平台
  spec.ios.deployment_target = "10.0"#支持iOS最低版本
  spec.swift_version = '4.0'
  spec.source       = { :git => "https://github.com/KKMobile/OxSDK-iOS-Publish.git", :tag => "t-#{spec.version}" }
  spec.ios.vendored_frameworks = 'FrameworkTools/OxSdkForTools.framework'#SDK相对本文件路径
  spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
  
  spec.dependency 'PureLayout'
  spec.dependency 'AFNetworking','4.0.1'
  spec.dependency 'AppLovinSDK', '11.3.3'
  spec.dependency 'AppLovinMediationFacebookAdapter', '6.10.0.3'
  spec.dependency 'AppLovinMediationFyberAdapter', '8.1.4.1'
  spec.dependency 'AppLovinMediationGoogleAdManagerAdapter', '9.5.0.0'
  spec.dependency 'AppLovinMediationGoogleAdapter', '9.5.0.0'
  spec.dependency 'AppLovinMediationByteDanceAdapter', '4.5.1.3.0'
  spec.dependency 'GoogleMobileAdsMediationFacebook', '6.9.0.1'
  spec.dependency 'GoogleMobileAdsMediationAppLovin', '11.3.3.0'
  spec.dependency 'AppLovinMediationSmaatoAdapter','21.7.5.1'

end
```

- 将改动提交到远程仓库，并打上相应 tag
- 如果没有 trunk 账号，首先进行注册

```
pod trunk register "email" 'name' --verbose
```

- 校验配置

```
pod spec lint
```

- 校验通过后，将其推送到 cocoapods

```
pod trunk push ./xxx.podspec
```

