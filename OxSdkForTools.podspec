#
#  Be sure to run `pod spec lint OxSdkForTools.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|


  spec.name         = "OxSdkForTools"#SDK名称
  spec.version      = "1.1.0.0-rc01-202303061259"#版本号
  spec.summary      = "OxAdSdk for tools applications."#概要
#描述  （描述一定要比概要多一些,不然会有警告!）
  spec.description  = <<-DESC
  OxAdSdk for tools applications.OxAdSdk for tools applications.
                   DESC
  spec.homepage     = "https://github.com/KKMobile/OxSDK-iOS-Publish.git"#github 上的仓库地址
  spec.license      = { :type => "MIT", :file => "LICENSE" }#创建GitHub仓库时使用的license类型
  spec.author             = { "OxDevelopers" => "tianci5275@gmail.com" }#作者
  spec.platform     = :ios#支持平台
  spec.ios.deployment_target = "11.0"#支持iOS最低版本
  spec.swift_version = '4.0'
  spec.source       = { :git => "https://github.com/KKMobile/OxSDK-iOS-Publish.git", :tag => "t-#{spec.version}" }
  spec.ios.vendored_frameworks = 'FrameworkTools/OxSdkForTools.framework'#SDK相对本文件路径
  spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置

  spec.resources = ["ResBundle/Tools/OxSdkRes.bundle","ResBundle/Tools/Language.bundle"]
  
  spec.dependency 'PureLayout'
  spec.dependency 'SDWebImage'
  spec.dependency 'AFNetworking'
  spec.dependency 'Adjust'
  spec.dependency 'FirebaseAnalytics', '>=8.0.0'
  spec.dependency 'FirebaseRemoteConfig', '>=8.0.0'
  # Max Mediation
  spec.dependency 'AppLovinSDK', '11.7.0'
  spec.dependency 'AmazonPublisherServicesSDK','4.4.3'
  spec.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','4.4.3.0'
  spec.dependency 'AppLovinMediationByteDanceAdapter', '4.8.1.0.1'
  spec.dependency 'AppLovinMediationFacebookAdapter', '6.12.0.0'
  spec.dependency 'AppLovinMediationFyberAdapter', '8.1.9.0'
  spec.dependency 'AppLovinMediationGoogleAdManagerAdapter', '9.14.0.2'
  spec.dependency 'AppLovinMediationGoogleAdapter', '9.14.0.2'
  spec.dependency 'AppLovinMediationSmaatoAdapter','21.7.9.1'
  spec.dependency 'AppLovinMediationUnityAdsAdapter','4.5.0.2'
  spec.dependency 'AppLovinMediationVungleAdapter','6.12.1.2'
  #Admob Mediation
  spec.dependency 'Google-Mobile-Ads-SDK', '9.14.0'
  spec.dependency 'GoogleMobileAdsMediationFacebook','6.12.0.0'
  #spec.dependency 'GoogleMobileAdsMediationAppLovin','11.7.0.0' # Admob Sdk 版本冲突（based on Admob 10.0.0+）。

end