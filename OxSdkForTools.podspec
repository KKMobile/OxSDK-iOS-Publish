#
#  Be sure to run `ss.dependency spec lint OxSdkForTools.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|


  spec.name         = "OxSdkForTools"#SDK名称
  spec.version      = "1.2.2.0-RC01-202503172130"#版本号
  spec.summary      = "OxAdSdk for tools applications."#概要
  #描述  （描述一定要比概要多一些,不然会有警告!）
  spec.description  = <<-DESC
  OxAdSdk for tools applications.OxAdSdk for tools applications.
                   DESC
  spec.homepage     = "https://github.com/KKMobile/OxSDK-iOS-Publish.git"#github 上的仓库地址
  spec.license      = { :type => "MIT", :file => "LICENSE" }#创建GitHub仓库时使用的license类型
  spec.author             = { "OxDevelopers" => "tianci5275@gmail.com" }#作者
  spec.platform     = :ios#支持平台
  spec.ios.deployment_target = "12.0"#支持iOS最低版本
  spec.swift_version = '4.0'
  spec.source       = { :git => "https://github.com/KKMobile/OxSDK-iOS-Publish.git", :tag => "t-#{spec.version}" }
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
  
  spec.vendored_frameworks = 'Frameworks/OxSdkCore.framework'#SDK相对本文件路径
  spec.resources = ["ResBundle/Core/OxSdkRes.bundle","ResBundle/Core/Language.bundle"]

  spec.dependency 'PureLayout'
  spec.dependency 'AFNetworking'
  spec.dependency 'SDWebImage'
  spec.dependency 'FirebaseAnalytics', '>=8.0.0'
  spec.dependency 'FirebaseRemoteConfig', '>=8.0.0'

  #Core Max Mediation
  spec.dependency 'AppLovinSDK', '13.0.0'
  spec.dependency 'AmazonPublisherServicesSDK','5.0.1.0'
  spec.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','5.0.1.0'
  spec.dependency 'AppLovinMediationGoogleAdManagerAdapter', '11.13.0.0'
  spec.dependency 'AppLovinMediationGoogleAdapter', '11.13.0.0'
  spec.dependency 'AppLovinMediationFacebookAdapter','6.16.0.0'
  spec.dependency 'AppLovinMediationByteDanceAdapter', '6.4.1.2.0'
  spec.dependency 'AppLovinMediationUnityAdsAdapter', '4.13.1.0'
  spec.dependency 'AppLovinMediationMintegralAdapter', '7.7.5.0.0'
  spec.dependency 'AppLovinMediationBidMachineAdapter', '3.2.0.0.0'
  spec.dependency 'AppLovinMediationFyberAdapter', '8.3.5.0'
  spec.dependency 'AppLovinMediationOguryPresageAdapter', '5.0.2.0'
  spec.dependency 'AppLovinMediationInMobiAdapter', '10.8.0.0'
  spec.dependency 'AppLovinMediationVungleAdapter', '7.4.4.0'
  spec.dependency 'AppLovinMediationMolocoAdapter', '3.6.0.1'
  
  #Core Admob Mediation
  spec.dependency 'GoogleMobileAdsMediationFacebook','6.16.0.0'
  spec.dependency 'GoogleMobileAdsMediationAppLovin','13.0.0.2'
  spec.dependency 'GoogleMobileAdsMediationPangle','6.4.1.2.0'
  spec.dependency 'GoogleMobileAdsMediationUnity', '4.13.1.0'
  spec.dependency 'GoogleMobileAdsMediationFyber', '8.3.5.0'
  spec.dependency 'GoogleMobileAdsMediationInMobi', '10.8.0.0'
  spec.dependency 'GoogleMobileAdsMediationMoloco', '3.6.0.0'
  spec.dependency 'GoogleMobileAdsMediationMintegral','7.7.5.0'
  spec.dependency 'GoogleMobileAdsMediationVungle','7.4.4.0'
  spec.dependency 'OguryMediationGoogleMobileAds','5.0.2.0'
    
    
  spec.dependency 'OxDiscoveryPlugin','1.0.3-202312041600'
    
end
