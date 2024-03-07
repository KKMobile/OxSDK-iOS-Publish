#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "OxSdkForGames"#SDK名称
  spec.version      = "1.1.4.1-RC01-202403071830"#版本号
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
  spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
  spec.resources = ["ResBundle/Games/OxSdkRes.bundle","ResBundle/Games/Language.bundle"]
  
    spec.ios.vendored_frameworks = 'FrameworkGames/OxSdkForGames.framework',
      "FrameworkGames/DTExchangeAdapter-8.2.5.0/DTExchangeAdapter.xcframework",
  "FrameworkGames/IronSourceAdapter-7.7.0.0.0/IronSourceAdapter.xcframework",
  "FrameworkGames/MetaAdapter-6.14.0.0/MetaAdapter.xcframework"

  spec.dependency 'PureLayout'
  spec.dependency 'AFNetworking'
  spec.dependency 'SDWebImage'
  spec.dependency 'Adjust'
  spec.dependency 'FirebaseAnalytics', '>=8.0.0'
  spec.dependency 'FirebaseRemoteConfig', '>=8.0.0'
  # Max Mediation
    spec.dependency'AppLovinSDK', '12.2.1'
    spec.dependency'AmazonPublisherServicesSDK','4.7.8.0'
    spec.dependency'AppLovinMediationAmazonAdMarketplaceAdapter','4.7.8.0'
    spec.dependency'BidMachine', '2.5.1.0'
    spec.dependency'AppLovinMediationChartboostAdapter', '9.6.0.0'
    spec.dependency'AppLovinMediationFyberAdapter', '8.2.5.2'
    spec.dependency'AppLovinMediationGoogleAdManagerAdapter', '11.0.1.0'
    spec.dependency'AppLovinMediationGoogleAdapter', '11.0.1.0'
    spec.dependency'AppLovinMediationInMobiAdapter', '10.6.4.0'
    spec.dependency'ALInMobiCustomAdapterFramework', '10.6.4.0'
    spec.dependency'AppLovinMediationIronSourceAdapter', '7.7.0.0.1'
    spec.dependency'AppLovinMediationFacebookAdapter', '6.14.0.1'
    spec.dependency'AppLovinMediationMobileFuseAdapter', '1.7.1.0'
    spec.dependency'AppLovinMediationOguryPresageAdapter', '4.2.2.1'
    spec.dependency'AppLovinMediationByteDanceAdapter', '5.8.0.7.0'
    spec.dependency'AppLovinMediationSmaatoAdapter', '22.7.0.0'
    spec.dependency'AppLovinMediationUnityAdsAdapter', '4.9.3.0'
    spec.dependency'AppLovinMediationVerveAdapter', '2.21.1.0'
    spec.dependency'AppLovinMediationVungleAdapter', '7.2.2.0'
    spec.dependency'AppLovinMediationLineAdapter', '2.7.20240214.0'
    spec.dependency'AppLovinMediationMintegralAdapter', '7.5.7.0.0'
    #spec.dependency'MolocoCustomAdapterAppLovin','1.4.2.0'
    spec.dependency'YandexMobileAds', '5.9.1'
    spec.dependency'OpenWrapSDK', '3.4.1'
    spec.dependency'AppLovinPubMaticAdapter', '1.1.0'

    #Admob Mediation
    spec.dependency'Google-Mobile-Ads-SDK', '11.0.1'
    spec.dependency'GoogleMobileAdsMediationAppLovin','12.2.1.0'
    spec.dependency'GoogleMobileAdsMediationUnity','4.9.3.0'
    spec.dependency'GoogleMobileAdsMediationVungle','7.2.2.1'
    spec.dependency'GoogleMobileAdsMediationChartboost','9.6.0.1'
    spec.dependency'GoogleMobileAdsMediationMintegral','7.5.7.0'
    spec.dependency'GoogleMobileAdsMediationInMobi','10.6.4.0'
    spec.dependency'GoogleMobileAdsMediationPangle','5.8.0.7.0'
    spec.dependency'OguryMediationGoogleMobileAds','4.2.2.0'
    spec.dependency'AdMobPubMaticAdapter','2.2.0'
    spec.dependency'FiveGADAdapter','1.5.0'

end
