#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

    spec.name         = "OxSdkForGames"#SDK名称
    spec.version      = "12.0-MO-MaxMultiCall-202509151500-1330"#版本号
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

    spec.dependency 'OxSdkCore', '12.0-MO-MaxMultiCall-202509151500-1330'
    
    spec.dependency 'OxAPSAdapter', '5.2.0.0'
    spec.dependency 'OxBidMachineAdapter', '3.0.1.0'
    spec.dependency 'OxChartboostAdapter', '9.8.1.0'
    spec.dependency 'OxFacebookAdapter', '6.20.0.0'
    spec.dependency 'OxFyberAdapter', '8.3.6.0'
    spec.dependency 'OxInmobiAdapter', '10.7.5.1'
    spec.dependency 'OxIronSourceAdapter', '8.11.0.0.1'
    spec.dependency 'OxLineAdapter', '2.9.20250512.0'
    spec.dependency 'OxMintegralAdapter', '7.7.2.1'
    spec.dependency 'OxMolocoAdapter', '3.7.2.0'
    spec.dependency 'OxMyTargetAdapter', '5.21.9.0'
    spec.dependency 'OxOguryAdapter', '5.0.1.0'
    spec.dependency 'OxPangleAdapter', '6.2.0.9.1'
    spec.dependency 'OxPubmaticAdapter', '4.5.0.0'
    spec.dependency 'OxSmaatoAdapter', '22.9.2.0'
    spec.dependency 'OxUnityAdsAdapter', '4.12.3.1'
    spec.dependency 'OxVerveAdapter', '3.1.1.1'
    spec.dependency 'OxVungleAdapter', '7.4.5.1'
    spec.dependency 'OxYandexAdapter', '7.5.0.0'
    
    spec.dependency 'OxAdjustPlugin', '4.0.0-202504021600'
    spec.dependency 'OxFBPlugin', '2.0.0-202411251600'
    spec.dependency 'OxFirebasePlugin', '2.0.0-202411251600'
    spec.dependency 'OxTAPlugin', '2.0.0-202411251600'
    spec.dependency 'OxRemoteConfigPlugin', '2.0.0-202411251600'
    spec.dependency 'OxDiscoveryPlugin', '3.0.1-202508141900'
    
end
