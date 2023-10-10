#
#  Be sure to run `pod spec lint OxDiscoveryPlugin.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|


  spec.name         = "OxDiscoveryPlugin"#SDK名称
  spec.version      = "1.0.0-202306291800"#版本号
  spec.summary      = "OxAdSdk for discovery applications."#概要
#描述  （描述一定要比概要多一些,不然会有警告!）
  spec.description  = <<-DESC
  OxAdSdk for discovery applications.OxAdSdk for discovery applications.
                   DESC
  spec.homepage     = "https://github.com/KKMobile/OxSDK-iOS-Publish.git"#github 上的仓库地址
  spec.license      = { :type => "MIT", :file => "LICENSE" }#创建GitHub仓库时使用的license类型
  spec.author             = { "OxDevelopers" => "tianci5275@gmail.com" }#作者
  spec.platform     = :ios#支持平台
  spec.ios.deployment_target = "11.0"#支持iOS最低版本
  spec.swift_version = '4.0'
  spec.source       = { :git => "https://github.com/KKMobile/OxSDK-iOS-Publish.git", :tag => "discovery-#{spec.version}" }
  spec.ios.vendored_frameworks = 'Frameworks/OxDiscoveryPlugin.framework'#SDK相对本文件路径
  spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
  
  spec.dependency 'AppLovinSDK'
  spec.dependency 'Google-Mobile-Ads-SDK'
  spec.dependency 'FirebaseAnalytics'
  spec.dependency 'FirebaseRemoteConfig'
end