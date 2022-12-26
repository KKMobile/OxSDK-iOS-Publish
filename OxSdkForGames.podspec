#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "OxSdkForGames"#SDK名称
  spec.version      = "2.0.0.0-RC01-202212211237"#版本号
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

  spec.dependency 'PureLayout'
  spec.dependency 'AFNetworking'
  spec.dependency 'SDWebImage'
  spec.dependency 'FirebaseAnalytics'
  spec.dependency 'Adjust'
  # Max Mediation
  spec.dependency 'AppLovinSDK', '11.5.3'
  spec.dependency 'AppLovinMediationAdColonyAdapter', '4.9.0.0.2'
  spec.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','4.4.3.0'
  spec.dependency 'AppLovinMediationChartboostAdapter', '9.1.0.0'
  spec.dependency 'AppLovinMediationFyberAdapter', '8.1.6.0'
  spec.dependency 'AppLovinMediationGoogleAdManagerAdapter', '9.11.0.4'
  spec.dependency 'AppLovinMediationGoogleAdapter', '9.11.0.4'
  spec.dependency 'AppLovinMediationInMobiAdapter', '10.1.0.2'
  spec.dependency 'AppLovinMediationIronSourceAdapter', '7.2.5.1.0'
  spec.dependency 'AppLovinMediationFacebookAdapter', '6.12.0.0'
  spec.dependency 'AppLovinMediationOguryPresageAdapter', '2.6.2.1'
  spec.dependency 'AppLovinMediationByteDanceAdapter', '4.6.2.2.3'
  spec.dependency 'AppLovinMediationSmaatoAdapter', '21.7.8.0'
  spec.dependency 'AppLovinMediationUnityAdsAdapter', '4.4.1.0'
  spec.dependency 'AppLovinMediationVerveAdapter', '2.16.0.0'
  spec.dependency 'AppLovinMediationVungleAdapter', '6.12.0.3'
  spec.dependency 'AmazonPublisherServicesSDK','4.4.3'
  spec.dependency 'OpenWrapSDK', '2.6.2 '
  spec.dependency 'AppLovinPubMaticAdapter', '1.0.1'
  
  #Admob Mediation
  spec.dependency 'GoogleMobileAdsMediationFacebook','6.12.0.0'
  spec.dependency 'GoogleMobileAdsMediationAppLovin','11.5.3.0'
  spec.dependency 'GoogleMobileAdsMediationInMobi','10.1.0.0'
  spec.dependency 'GoogleMobileAdsMediationUnity','4.4.1.0'
  spec.dependency 'GoogleMobileAdsMediationFyber','8.1.6.0'
  spec.dependency 'GoogleMobileAdsMediationPangle','4.6.2.2.0'
  spec.dependency 'GoogleMobileAdsMediationVungle','6.12.0.0'

  # OM
  spec.dependency 'OxMediation','1.0.4.0-RC01-20221211231'
  spec.dependency 'OMAdMobAdapter','9.5.0.0-202212131150'
  spec.dependency 'OMApsAdapter','4.5.5.0-202212131150'
  spec.dependency 'OMFacebookAdapter','6.9.0.0-202212131150'
  spec.dependency 'OMFyberAdapter','7.5.4.0-202212131150'
  spec.dependency 'OMGoogleAdAdapter','9.5.0.0-202212131150'
  spec.dependency 'ChartboostHelium','3.3.0'
  spec.dependency 'OMHeliumAdapter','3.2.0.0-202212131150'
  spec.dependency 'OMInMobiAdapter','10.0.7.0-202212131150'
  spec.dependency 'OMIronSourceAdapter','7.2.2.1.0-202212131150'
  spec.dependency 'OMMaxAdapter','11.5.3.0-202212131150'
  spec.dependency 'OMPangleAdapter','4.8.0.6.0-202212131150'
  spec.dependency 'OMPubMaticAdapter','2.6.2.0-202212131150'
  spec.dependency 'OMUnityAdapter','4.2.1.0-202212131150'
  spec.dependency 'OMVungleAdapter','6.11.0.0-202212131150'

end