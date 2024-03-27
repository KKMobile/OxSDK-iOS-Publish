#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "OxSdkForGames"#SDK名称
  spec.version      = "MO-AdmobBidding-20240327-1135-V1"#版本号
  spec.summary      = "OxAdSdk for game applications."#概要
#描述  （描述一定要比概要多一些,不然会有警告!）
  spec.description  = <<-DESC
  OxAdSdk for game applications.OxAdSdk for game applications.
                   DESC
  spec.homepage     = "https://github.com/KKMobile/OxSDK-iOS-Publish.git"#github 上的仓库地址
  spec.license      = { :type => "MIT", :file => "LICENSE" }#创建GitHub仓库时使用的license类型
  spec.author             = { "OxDevelopers" => "tianci5275@gmail.com" }#作者
  spec.platform     = :ios#支持平台
  spec.ios.deployment_target = "12.0"#支持iOS最低版本
  spec.swift_version = '4.0'
  spec.source       = { :git => "https://github.com/KKMobile/OxSDK-iOS-Publish.git", :tag => "g-#{spec.version}" }
  spec.ios.vendored_frameworks = 'FrameworkGames/OxSdkForGames.framework'#SDK相对本文件路径
  spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
  spec.resources = ["ResBundle/Games/OxSdkRes.bundle","ResBundle/Games/Language.bundle"]

  spec.dependency 'PureLayout'
  spec.dependency 'AFNetworking'
  spec.dependency 'SDWebImage'
  spec.dependency 'Adjust'
  spec.dependency 'FirebaseAnalytics', '>=8.0.0'
  spec.dependency 'FirebaseRemoteConfig', '>=8.0.0'
  # Max Mediation
  spec.dependency 'AppLovinSDK', '11.8.2'
  spec.dependency 'AmazonPublisherServicesSDK','4.6.0'
  spec.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','4.6.0.0'
  spec.dependency 'BidMachine', '2.0.0.6'
  spec.dependency 'AppLovinMediationChartboostAdapter', '9.2.0.0'
  spec.dependency 'AppLovinMediationFyberAdapter', '8.2.2.0'
  spec.dependency 'AppLovinMediationGoogleAdManagerAdapter', '10.3.0.1'
  spec.dependency 'AppLovinMediationGoogleAdapter', '10.3.0.1'
  spec.dependency 'AppLovinMediationInMobiAdapter', '10.1.2.7'
  spec.dependency 'ALInMobiCustomAdapterFramework', '10.1.2.0'
  spec.dependency 'AppLovinMediationIronSourceAdapter', '7.2.7.0.1'
  spec.dependency 'AppLovinMediationFacebookAdapter', '6.12.0.2'
  spec.dependency 'AppLovinMediationMobileFuseAdapter', '1.4.4.0'
  spec.dependency 'AppLovinMediationOguryPresageAdapter', '4.1.1.3'
  spec.dependency 'AppLovinMediationByteDanceAdapter', '5.1.0.9.0'
  spec.dependency 'AppLovinMediationSmaatoAdapter', '22.0.2.0'
  spec.dependency 'AppLovinMediationUnityAdsAdapter', '4.6.1.0'
  spec.dependency 'AppLovinMediationVerveAdapter', '2.18.0.0'
  spec.dependency 'AppLovinMediationVungleAdapter', '6.12.3.0'
  spec.dependency 'AppLovinMediationLineAdapter', '2.6.20230215'
  spec.dependency 'AppLovinMediationMintegralAdapter', '7.3.5.0.0'
  spec.dependency 'MolocoCustomAdapterAppLovin','1.1.0.1'
  spec.dependency 'YandexMobileAds', '5.9.1'
  spec.dependency 'OpenWrapSDK', '2.7.0'
  spec.dependency 'AppLovinPubMaticAdapter', '1.0.2'
  #Admob Mediation
  spec.dependency 'Google-Mobile-Ads-SDK', '10.3.0'
  spec.dependency 'GoogleMobileAdsMediationFacebook','6.12.0.1'
  spec.dependency 'GoogleMobileAdsMediationUnity','4.6.1.0'
  spec.dependency 'GoogleMobileAdsMediationVungle','6.12.3.0'

  spec.dependency 'GoogleMobileAdsMediationAppLovin','11.8.2.0'
  spec.dependency 'GoogleMobileAdsMediationChartboost','9.2.0.0'
  spec.dependency 'GoogleMobileAdsMediationIronSource','7.2.7.0.1'

  spec.dependency 'MobileFuseAdMobAdapter','1.4.4.0'
  spec.dependency 'OguryMediationGoogleMobileAds','4.1.1.0'
  spec.dependency 'AdMobPubMaticAdapter','2.1.1'
  spec.dependency 'FiveGADAdapter','1.5.0'

end
