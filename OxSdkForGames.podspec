#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

    spec.name         = "OxSdkForGames"#SDK名称
    spec.version      = "1.1.4.2-RC03-Test"#版本号
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
    spec.dependency 'AppLovinSDK', '12.4.1'
    spec.dependency 'AmazonPublisherServicesSDK','4.9.3.0'
    spec.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','4.9.3.0'
    spec.dependency 'AppLovinMediationBidMachineAdapter', '2.5.3.0.0'
    spec.dependency 'AppLovinMediationChartboostAdapter', '9.7.0.0'
    spec.dependency 'AppLovinMediationFyberAdapter', '8.2.7.0'
    spec.dependency 'AppLovinMediationGoogleAdManagerAdapter', '11.3.0.0'
    spec.dependency 'AppLovinMediationGoogleAdapter', '11.3.0.0'
    spec.dependency 'AppLovinMediationInMobiAdapter', '10.7.2.0'
    spec.dependency 'ALInMobiCustomAdapterFramework', '10.7.2.0'
    spec.dependency 'AppLovinMediationIronSourceAdapter', '8.0.0.0.0'
    spec.dependency 'AppLovinMediationFacebookAdapter', '6.15.1.0'
    spec.dependency 'AppLovinMediationMobileFuseAdapter', '1.7.6.0'
    spec.dependency 'AppLovinMediationOguryPresageAdapter', '4.3.0.0'
    spec.dependency 'AppLovinMediationByteDanceAdapter', '6.1.0.6.0'
    spec.dependency 'AppLovinMediationSmaatoAdapter', '22.8.3.0'
    spec.dependency 'AppLovinMediationUnityAdsAdapter', '4.10.0.0'
    spec.dependency 'AppLovinMediationVerveAdapter','3.0.1.0'
    spec.dependency 'AppLovinMediationVungleAdapter', '7.3.1.0'
    spec.dependency 'AppLovinMediationLineAdapter', '2.7.20240318'
    spec.dependency 'AppLovinMediationMintegralAdapter', '7.6.1.0.0'
    spec.dependency 'AppLovinMediationMyTargetAdapter', '5.21.7.0'
    spec.dependency 'OpenWrapSDK', '3.4.1'
    spec.dependency 'AppLovinPubMaticAdapter', '1.1.0'
    spec.dependency 'AppLovinMediationYandexAdapter','7.5.0.0'
    spec.dependency 'AppLovinMediationLineAdapter', '2.7.20240318'
    spec.dependency 'AppLovinMediationMolocoAdapter','2.2.1.0'

    #Admob Mediation
    spec.dependency 'Google-Mobile-Ads-SDK', '11.3.0'
    spec.dependency 'GoogleMobileAdsMediationAppLovin','12.4.1.0'
    spec.dependency 'GoogleMobileAdsMediationUnity','4.10.0.0'
    spec.dependency 'GoogleMobileAdsMediationVungle','7.3.1.0'
    spec.dependency 'GoogleMobileAdsMediationChartboost','9.7.0.0'
    spec.dependency 'GoogleMobileAdsMediationMintegral','7.6.1.0'
    spec.dependency 'GoogleMobileAdsMediationInMobi','10.7.2.0'
    spec.dependency 'GoogleMobileAdsMediationPangle','6.1.0.6.0'
    spec.dependency 'GoogleMobileAdsMediationFacebook','6.15.1.0'
    spec.dependency 'GoogleMobileAdsMediationIronSource','8.0.0.0.0'
    spec.dependency 'GoogleMobileAdsMediationFyber','8.2.7.0'
    spec.dependency 'OguryMediationGoogleMobileAds','4.3.0.0'
    spec.dependency 'AdMobPubMaticAdapter','2.2.0'
    spec.dependency 'FiveGADAdapter','1.5.1'
    #spec.dependency 'MobileFuseAdMobAdapter','1.7.6.0'

end
