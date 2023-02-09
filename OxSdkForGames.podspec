#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "OxSdkForGames"#SDK名称
  spec.version      = "1.1.0.0-RC01-202302092130"#版本号
  spec.summary      = "OxAdSdk for game applications."#概要
#描述  （描述一定要比概要多一些,不然会有警告!）
  spec.description  = <<-DESC
  OxAdSdk for game applications.OxAdSdk for game applications.
                   DESC
  spec.homepage     = "https://github.com/KKMobile/OxSDK-iOS-Publish.git"#github 上的仓库地址
  spec.license      = { :type => "MIT", :file => "LICENSE" }#创建GitHub仓库时使用的license类型
  spec.author             = { "OxDevelopers" => "tianci5275@gmail.com" }#作者
  spec.platform     = :ios#支持平台
  spec.ios.deployment_target = "10.0"#支持iOS最低版本
  spec.swift_version = '4.0'
  spec.source       = { :git => "https://github.com/KKMobile/OxSDK-iOS-Publish.git", :tag => "g-#{spec.version}" }
  spec.ios.vendored_frameworks = 'FrameworkGames/OxSdkForGames.framework'#SDK相对本文件路径
  spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
  spec.resources = ["ResBundle/OxSdkRes.bundle","ResBundle/Language.bundle"]

  s.frameworks = 'UIKit'
  s.dependency 'PureLayout'
  s.dependency 'AFNetworking'
  s.dependency 'SDWebImage'
  s.dependency 'FirebaseAnalytics'
  s.dependency 'Adjust'
  s.dependency 'FirebaseRemoteConfig'
  # Max Mediation
  s.dependency 'AppLovinSDK', '11.7.0'
  s.dependency 'AppLovinMediationAdColonyAdapter', '4.9.0.0.2'
  s.dependency 'AmazonPublisherServicesSDK','4.4.3' #由于最新版本需要支持iOS12 所以先不升级
  s.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','4.4.3.0'  #由于最新版本需要支持iOS12 所以先不升级
  s.dependency 'AppLovinMediationChartboostAdapter', '9.1.0.0'
  s.dependency 'AppLovinMediationFyberAdapter', '8.1.9.0'
  s.dependency 'AppLovinMediationGoogleAdManagerAdapter', '9.14.0.2'
  s.dependency 'AppLovinMediationGoogleAdapter', '9.14.0.2'
  s.dependency 'AppLovinMediationInMobiAdapter', '10.1.2.5'
  s.dependency 'AppLovinMediationIronSourceAdapter', '7.2.7.0.0'
  s.dependency 'AppLovinMediationFacebookAdapter', '6.12.0.0'
  s.dependency 'AppLovinMediationMobileFuseAdapter', '1.4.0.0'
  s.dependency 'AppLovinMediationOguryPresageAdapter', '4.0.0.0'
  s.dependency 'AppLovinMediationByteDanceAdapter', '4.8.1.0.1'
  s.dependency 'AppLovinMediationSmaatoAdapter', '21.7.9.1'
  s.dependency 'AppLovinMediationUnityAdsAdapter', '4.5.0.2'
  s.dependency 'AppLovinMediationVerveAdapter', '2.17.0.0'
  s.dependency 'AppLovinMediationVungleAdapter', '6.12.1.2'
  s.dependency 'OpenWrapSDK', '2.7.0'
  s.dependency 'AppLovinPubMaticAdapter', '1.0.2'
  #Admob Mediation
  s.dependency 'Google-Mobile-Ads-SDK', '9.14.0'
  s.dependency 'GoogleMobileAdsMediationFacebook','6.12.0.0'
  #s.dependency 'GoogleMobileAdsMediationAppLovin','11.7.0.0' # Admob Sdk 版本冲突（based on Admob 10.0.0+）。
  s.dependency 'GoogleMobileAdsMediationInMobi','10.1.2.1'
  s.dependency 'GoogleMobileAdsMediationUnity','4.5.0.0'
  s.dependency 'GoogleMobileAdsMediationFyber','8.1.9.0'
  s.dependency 'GoogleMobileAdsMediationPangle','4.8.1.0.0'
  s.dependency 'GoogleMobileAdsMediationVungle','6.12.1.1'

end