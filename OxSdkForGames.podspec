#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "OxSdkForGames"#SDK名称
  spec.version      = "1.2.0.0-RC02-202308081830"#版本号
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
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置


  # Max Mediation
  spec.dependency 'AppLovinMediationAdColonyAdapter', '4.9.0.0.4'
  spec.dependency 'AmazonPublisherServicesSDK','4.6.0'
  spec.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','4.6.0.0'
  spec.dependency 'AppLovinMediationBidMachineAdapter', '2.1.0.0.1'
  spec.dependency 'AppLovinMediationChartboostAdapter', '9.2.0.0'
  spec.dependency 'AppLovinMediationIronSourceAdapter', '7.2.7.0.1'
  spec.dependency 'AppLovinMediationMobileFuseAdapter', '1.4.4.0'
  spec.dependency 'AppLovinMediationVungleAdapter', '6.12.3.0'
  spec.dependency 'AppLovinMediationLineAdapter', '2.6.20230215'

  #Admob Mediation
  spec.dependency 'GoogleMobileAdsMediationUnity','4.6.1.0'
  spec.dependency 'GoogleMobileAdsMediationVungle','6.12.3.0'
  
  spec.dependency 'OxSdkCore','1.2.0.0-RC02-202308081830'
  spec.dependency 'OxDiscoveryPlugin','1.0.1-202308081830'

end
