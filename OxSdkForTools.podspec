#
#  Be sure to run `ss.dependency spec lint OxSdkForTools.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|


  spec.name         = "OxSdkForTools"#SDK名称
  spec.version      = "1.2.3.0-RC02-202603191100"#版本号
  spec.summary      = "OxAdSdk for tools applications."#概要
  #描述  （描述一定要比概要多一些,不然会有警告!）
  spec.description  = <<-DESC
  OxAdSdk for tools applications.OxAdSdk for tools applications.
                   DESC
  spec.homepage     = "https://github.com/KKMobile/OxSDK-iOS-Publish.git"#github 上的仓库地址
  spec.license      = { :type => "MIT", :file => "LICENSE" }#创建GitHub仓库时使用的license类型
  spec.author             = { "OxDevelopers" => "tianci5275@gmail.com" }#作者
  spec.platform     = :ios#支持平台
  spec.ios.deployment_target = "13.0"#支持iOS最低版本
  spec.swift_version = '4.0'
  spec.source       = { :git => "https://github.com/KKMobile/OxSDK-iOS-Publish.git", :tag => "t-#{spec.version}" }
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
  
  spec.vendored_frameworks = 'Frameworks/OxSdkCore.framework'#SDK相对本文件路径
  spec.resources = ["ResBundle/Core/OxSdkRes.bundle","ResBundle/Core/Language.bundle"]

  spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件

  spec.dependency 'PureLayout'

  #Core Max Mediation
  spec.dependency 'AppLovinSDK', '13.2.0'
  spec.dependency 'Google-Mobile-Ads-SDK', '12.14.0.0'
  spec.dependency 'AppLovinMediationGoogleAdManagerAdapter', '12.14.0.0'
  spec.dependency 'AppLovinMediationGoogleAdapter', '12.14.0.0'
  spec.dependency 'GoogleMobileAdsMediationAppLovin','13.2.0.0'
  spec.dependency 'GoogleUserMessagingPlatform','2.6.0'

  spec.dependency 'OxAPSAdapter', '5.2.0.0'
  spec.dependency 'OxFacebookAdapter', '6.21.1.0'
  spec.dependency 'OxPangleAdapter', '7.8.5.5.0'
 
  spec.dependency 'OxRemoteConfigPlugin', '2.0.0-202411251600'
  spec.dependency 'OxDiscoveryPlugin', '3.0.2-202509042130'
  spec.dependency 'OxFirebasePlugin', '2.0.0-202411251600'
    
end
