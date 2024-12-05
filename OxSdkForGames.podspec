#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

    spec.name         = "OxSdkForGames"#SDK名称
    spec.version      = "4.0-MO-LP-202412051600"#版本号
    spec.summary      = "OxAdSdk for game applications."#概要
    #描述  （描述一定要比概要多一些,不然会有警告!）
    spec.description  = <<-DESC
    OxAdSdk for game applications.OxAdSdk for game applications.
                   DESC
    spec.homepage     = "https://github.com/KKMobile/OxSDK-iOS-Publish.git"#github 上的仓库地址
    spec.license      = { :type => "MIT", :file => "LICENSE" }#创建GitHub仓库时使用的license类型
    spec.author             = { "OxDevelopers" => "tianci5275@gmail.com" }#作者
    spec.platform     = :ios#支持平台
    spec.ios.deployment_target = "13.0"#支持iOS最低版本
    spec.swift_version = '4.0'
    spec.source       = { :git => "https://github.com/KKMobile/OxSDK-iOS-Publish.git", :tag => "g-#{spec.version}" }
    spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件
    spec.requires_arc = true#是否时自动内存管理
    spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
    spec.resources = ["ResBundle/Games/OxSdkRes.bundle","ResBundle/Games/Language.bundle"]
    spec.resource_bundles = {'OxSdkForGames' => ['ResBundle/PrivacyInfo.xcprivacy']}
  
    spec.ios.vendored_frameworks = 'FrameworkGames/OxSdkForGames.framework'

    spec.frameworks = 'UIKit'
    spec.dependency 'PureLayout'
    spec.dependency 'Adjust'
    spec.dependency 'FBSDKCoreKit'
    spec.dependency 'FirebaseAnalytics', '>=8.0.0'
    spec.dependency 'FirebaseRemoteConfig', '>=8.0.0'
    
    # Max Mediation
    spec.dependency 'AppLovinSDK', '13.0.1'
    spec.dependency 'AmazonPublisherServicesSDK','4.10.0.0'
    spec.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','4.10.0.0'
    spec.dependency 'AppLovinMediationBidMachineAdapter', '3.0.1.0.0'
    spec.dependency 'AppLovinMediationChartboostAdapter', '9.7.0.2'
    spec.dependency 'AppLovinMediationFyberAdapter', '8.3.2.1'
    spec.dependency 'AppLovinMediationGoogleAdManagerAdapter', '11.11.0.0'
    spec.dependency 'AppLovinMediationGoogleAdapter', '11.11.0.0'
    spec.dependency 'AppLovinMediationInMobiAdapter', '10.7.5.1'
    spec.dependency 'ALInMobiCustomAdapterFramework', '10.7.5.1'
    spec.dependency 'AppLovinMediationIronSourceAdapter', '8.5.0.0.0'
    spec.dependency 'AppLovinMediationFacebookAdapter', '6.15.2.1'
    spec.dependency 'AppLovinMediationMobileFuseAdapter', '1.7.6.1'
    spec.dependency 'AppLovinMediationOguryPresageAdapter', '4.4.2.0'
    spec.dependency 'AppLovinMediationByteDanceAdapter', '6.2.0.9.0'
    spec.dependency 'AppLovinMediationSmaatoAdapter', '22.9.1.0'
    spec.dependency 'AppLovinMediationUnityAdsAdapter', '4.12.3.0'
    spec.dependency 'AppLovinMediationVerveAdapter','3.1.1.0'
    spec.dependency 'AppLovinMediationVungleAdapter', '7.4.2.1'
    spec.dependency 'AppLovinMediationMintegralAdapter', '7.7.2.0.1'
    spec.dependency 'OpenWrapSDK', '4.0.0.0'
    spec.dependency 'AppLovinPubMaticAdapter', '1.2.0'
    spec.dependency 'AppLovinMediationYandexAdapter','7.5.0.3'
    spec.dependency 'AppLovinMediationLineAdapter', '2.8.20240827.1'
    spec.dependency 'AppLovinMediationMolocoAdapter','3.2.0.0'
    spec.dependency 'AppLovinMediationMyTargetAdapter','5.21.9.0'

    #Admob Mediation
    spec.dependency 'Google-Mobile-Ads-SDK', '11.11.0'
    spec.dependency 'GoogleMobileAdsMediationUnity','4.12.3.1'
    spec.dependency 'GoogleMobileAdsMediationVungle','7.4.2.0'
    spec.dependency 'GoogleMobileAdsMediationChartboost','9.7.0.1'
    spec.dependency 'GoogleMobileAdsMediationMintegral','7.7.2.1'
    spec.dependency 'GoogleMobileAdsMediationInMobi','10.7.5.1'
    spec.dependency 'GoogleMobileAdsMediationPangle','6.2.0.9.0'
    spec.dependency 'GoogleMobileAdsMediationFacebook','6.15.2.1'
    spec.dependency 'GoogleMobileAdsMediationIronSource','8.5.0.0.0'
    spec.dependency 'GoogleMobileAdsMediationFyber','8.3.2.1'
    spec.dependency 'OguryMediationGoogleMobileAds','4.4.2.0'
    spec.dependency 'AdMobPubMaticAdapter','3.1.0'
    spec.dependency 'FiveGADAdapter','1.5.1'
    spec.dependency 'MobileFuseAdMobAdapter','1.7.6.0'
    spec.dependency 'GoogleMobileAds-HyBid-Adapters','3.1.1.0'
  
    #Levelplay Mediation
    spec.dependency 'IronSourceSDK','8.5.0.0'
    spec.dependency 'IronSourceAdQualitySDK','7.22.0'
    spec.dependency 'IronSourceAppLovinAdapter','4.3.50.0'
    spec.dependency 'IronSourceAPSAdapter','4.3.16.0'
    spec.dependency 'IronSourceBidMachineAdapter','4.3.11.1'
    spec.dependency 'IronSourceChartboostAdapter','4.3.19.3'
    spec.dependency 'IronSourceFyberAdapter','4.3.37.0'
    spec.dependency 'IronSourceFacebookAdapter','4.3.46.1'
    spec.dependency 'IronSourceAdMobAdapter','4.3.58.0'
    spec.dependency 'IronSourceInMobiAdapter','4.3.24.2'
    spec.dependency 'IronSourcePangleAdapter','4.3.33.0'
    spec.dependency 'IronSourceSmaatoAdapter','4.3.15.0'
    spec.dependency 'IronSourceUnityAdsAdapter','4.3.43.1'
    spec.dependency 'IronSourceVungleAdapter','4.3.38.0'
    spec.dependency 'IronSourceMintegralAdapter', '4.3.26.1'
    spec.dependency 'IronSourceMolocoAdapter', '4.3.7.0'
    spec.dependency 'IronSourceMyTargetAdapter', '4.1.25.0'
    spec.dependency 'IronSourcePubMaticAdapter', '1.2.0'
    spec.dependency 'IronSourceMobileFuseAdapter','4.3.1.1'
    spec.dependency 'IronSourceOguryAdapter','4.3.1.0'
    spec.dependency 'IronSourceVerveAdapter', '4.3.1.0'

end
