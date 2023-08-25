#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "OxSdkForGames"#SDK名称
  spec.version      = "2.0.3.0-RC01-202308251200"#版本号
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
  spec.ios.vendored_frameworks = 'Frameworks/OxSdkCore.framework'#SDK相对本文件路径
  spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
  spec.resources = ["ResBundle/OxSdkRes.bundle","ResBundle/Language.bundle"]

  spec.dependency 'PureLayout'
  spec.dependency 'AFNetworking'
  spec.dependency 'SDWebImage'
  spec.dependency 'Adjust'
  spec.dependency 'FirebaseAnalytics', '>=8.0.0'
  spec.dependency 'FirebaseRemoteConfig', '>=8.0.0'
  
  #Core Max Mediation
  spec.dependency 'AppLovinSDK', '11.8.2'
  spec.dependency 'AppLovinMediationFyberAdapter', '8.2.2.0'
  spec.dependency 'AppLovinMediationGoogleAdManagerAdapter', '10.3.0.1'
  spec.dependency 'AppLovinMediationGoogleAdapter', '10.3.0.1'
  spec.dependency 'AppLovinMediationInMobiAdapter', '10.1.2.7'
  spec.dependency 'ALInMobiCustomAdapterFramework', '10.1.2.0'
  spec.dependency 'AppLovinMediationFacebookAdapter','6.12.0.2'
  spec.dependency 'AppLovinMediationOguryPresageAdapter', '4.1.1.3'
  spec.dependency 'AppLovinMediationByteDanceAdapter', '5.1.0.9.0'
  spec.dependency 'AppLovinMediationSmaatoAdapter','22.1.1.0'
  spec.dependency 'AppLovinMediationUnityAdsAdapter', '4.6.1.0'
  spec.dependency 'AppLovinMediationVerveAdapter', '2.18.0.0'
  spec.dependency 'OpenWrapSDK', '2.7.0'
  spec.dependency 'AppLovinPubMaticAdapter', '1.0.2'
  
  #Core Admob Mediation
  spec.dependency 'Google-Mobile-Ads-SDK', '10.3.0'
  spec.dependency 'GoogleMobileAdsMediationFacebook','6.12.0.1'
  
  #Games Max Mediation
  spec.dependency 'AmazonPublisherServicesSDK','4.6.0'
  spec.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','4.6.0.0'
  spec.dependency 'AppLovinMediationMintegralAdapter', '7.3.5.0.0'
  spec.dependency 'AppLovinMediationAdColonyAdapter', '4.9.0.0.4'
  spec.dependency 'BidMachine', '2.1.0.0'
  spec.dependency 'AppLovinMediationChartboostAdapter', '9.2.0.0'
  spec.dependency 'AppLovinMediationIronSourceAdapter', '7.2.7.0.1'
  spec.dependency 'AppLovinMediationMobileFuseAdapter', '1.4.4.0'
  spec.dependency 'AppLovinMediationVungleAdapter', '6.12.3.0'
  spec.dependency 'AppLovinMediationLineAdapter', '2.6.20230215'
  
  #Games Admob Mediation
  spec.dependency 'GoogleMobileAdsMediationUnity','4.6.1.0'
  spec.dependency 'GoogleMobileAdsMediationVungle','6.12.3.0'

  # OM
  spec.dependency 'OxMediation', '1.1.4.0-RC01-202308172100'
  spec.dependency 'OMAdMobAdapter', '10.3.0.2-202308172100'
  spec.dependency 'OMApsAdapter', '4.6.0-202308172100'
  spec.dependency 'OMFacebookAdapter', '6.12.0.1-202308172100'
  spec.dependency 'OMFyberAdapter', '8.2.2-202308172100'
  spec.dependency 'OMGoogleAdAdapter', '10.3.0-202308172100'
  spec.dependency 'OMHeliumAdapter', '3.3.0.0-202308172100'
  spec.dependency 'OMInMobiAdapter', '10.1.2-202308172100'
  spec.dependency 'OMIronSourceAdapter', '7.2.7.0-202308172100'
  spec.dependency 'OMMaxAdapter', '11.8.2-202308172100'
  spec.dependency 'OMPangleAdapter', '5.1.0.9-202308172100'
  spec.dependency 'OMPubMaticAdapter', '2.7.0-202308172100'
  spec.dependency 'OMUnityAdapter', '4.6.1-202308172100'
  spec.dependency 'OMVerveAdapter', '2.18.0-202308172100'
  spec.dependency 'OMVungleAdapter', '6.12.3-202308172100'
  
  # DiscoveryPlugin
  spec.dependency 'OxDiscoveryPlugin','1.0.1-OM-2O2308251100'

end
