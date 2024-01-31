#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

    spec.name         = "OxSdkForGames"#SDK名称
    spec.version      = "1.1.5.2-Size"#版本号
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


    spec.subspec 'Base' do |ss|
        ss.ios.vendored_frameworks =
        'FrameworkSize/OxSdkForGames.framework','FrameworkSize/OxCustomUnityAdsAdapter.framework'

        ss.dependency 'AppLovinSDK', '11.11.4'
        ss.dependency 'AmazonPublisherServicesSDK','4.7.6.0'
        ss.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','4.7.6.0'
        ss.dependency 'AppLovinMediationGoogleAdManagerAdapter', '10.13.0.0'
        ss.dependency 'AppLovinMediationGoogleAdapter', '10.13.0.0'
        ss.dependency 'AppLovinMediationFacebookAdapter', '6.14.0.0'
        ss.dependency 'AppLovinMediationUnityAdsAdapter', '4.9.0.0'
        ss.dependency 'OpenWrapSDK', '3.2.0'

        ss.dependency 'GoogleMobileAdsMediationAppLovin','11.11.4.0'  #1
        ss.dependency 'GoogleMobileAdsMediationFacebook','6.14.0.0'    #1
        ss.dependency 'GoogleMobileAdsMediationUnity','4.9.0.0'
    end

    spec.subspec 'Lite1' do |ss|
        ss.dependency 'OxSdkForGames/Base'
        ss.ios.vendored_frameworks = 'FrameworkSize/GADMVerveAdapter.framework',
                                    'FrameworkSize/OxCustomFyberAdapter.framework',
                                    'FrameworkSize/OxCustomPangleAdapter.framework'

        ss.dependency 'AppLovinMediationFyberAdapter', '8.2.4.0'
        ss.dependency 'AppLovinMediationInMobiAdapter', '10.6.0.0'
        ss.dependency 'ALInMobiCustomAdapterFramework', '10.6.0.0'
        ss.dependency 'AppLovinMediationIronSourceAdapter', '7.5.1.0.0'
        ss.dependency 'AppLovinMediationOguryPresageAdapter', '4.2.2.0'
        ss.dependency 'AppLovinMediationByteDanceAdapter', '5.5.0.9.0'
        ss.dependency 'AppLovinMediationVerveAdapter', '2.18.0.0'
        ss.dependency 'AppLovinMediationVungleAdapter', '7.1.0.2'
        ss.dependency 'AppLovinPubMaticAdapter', '1.1.0'
        ss.dependency 'AppLovinMediationBidMachineAdapter', '2.3.0.2'
        ss.dependency 'MolocoCustomAdapterAppLovin','1.3.0.0'

        ss.dependency 'GoogleMobileAdsMediationFyber','8.2.4.0'
        ss.dependency 'GoogleMobileAdsMediationInMobi','10.6.0.0'
        ss.dependency 'GoogleMobileAdsMediationIronSource',' 7.5.1.0'  #1
        ss.dependency 'OguryMediationGoogleMobileAds','4.2.2.0'
        ss.dependency 'GoogleMobileAdsMediationPangle','5.5.0.9.0'
        ss.dependency 'GoogleMobileAdsMediationVungle','7.1.0.0'   #1
        ss.dependency 'AdMobPubMaticAdapter','2.2.0'
    end

    spec.subspec 'Lite2' do |ss|
        ss.dependency 'OxSdkForGames/Lite1'

        ss.dependency 'AppLovinMediationChartboostAdapter', '9.5.1.0'
        ss.dependency 'AppLovinMediationMobileFuseAdapter', '1.6.5.0'
        ss.dependency 'AppLovinMediationSmaatoAdapter', '22.4.0.0'
        ss.dependency 'AppLovinMediationLineAdapter', '2.6.20230609.0'
        ss.dependency 'AppLovinMediationMintegralAdapter', '7.4.7.0.0'


        ss.dependency 'GoogleMobileAdsMediationChartboost','9.5.1.0'
        ss.dependency 'MobileFuseAdMobAdapter','1.6.5.0'
        ss.dependency 'GoogleMobileAdsMediationMintegral','7.4.7.0'
        ss.dependency 'FiveGADAdapter','1.5.0'

    end

    spec.subspec 'Full' do |ss|
        ss.dependency 'OxSdkForGames/Lite2'
        ss.ios.vendored_frameworks = 'FrameworkSize/MaxYandexAdapyer.framework'
        ss.dependency 'Google-Mobile-Ads-SDK', '10.13.0'
    end


end
