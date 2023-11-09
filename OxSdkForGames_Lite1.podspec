#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "OxSdkForGames"#SDK名称
  spec.version      = "1.1.3.3-Lite1-RCO1-202311091900"#版本号
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
  spec.resources = ["ResBundle/Adapter/Games/OxSdkRes.bundle","ResBundle/Games/Language.bundle"]
  spec.source_files = ['Games_Size/Adapter/Google/GADMFyberAdapter/*',
                       'Games_Size/Adapter/Google/GADMInMobiAdapter/*',
                       'Games_Size/Adapter/Google/GADMPangleAdapter/*',
                       'Games_Size/Adapter/Google/GADMVerveAdapter/*',
                       'Games_Size/Adapter/Max/Pangle/*',
                       'Games_Size/Adapter/Max/BidMachineAdapter/*',
                       'Games_Size/Adapter/Max/Fyber/*',
                       ]

  spec.dependency 'OxSdkForGames','1.1.3.3-Base-RCO1-202311091900'
  spec.dependency 'AppLovinMediationFyberAdapter', '8.2.2.0'
  spec.dependency 'AppLovinMediationInMobiAdapter', '10.1.2.7'
  spec.dependency 'ALInMobiCustomAdapterFramework', '10.1.2.0'
  spec.dependency 'AppLovinMediationIronSourceAdapter', '7.2.7.0.1'
  spec.dependency 'AppLovinMediationOguryPresageAdapter', '4.1.1.3'
  spec.dependency 'AppLovinMediationByteDanceAdapter', '5.1.0.9.0'
  spec.dependency 'AppLovinMediationVerveAdapter', '2.18.0.0'
  spec.dependency 'AppLovinMediationVungleAdapter', '6.12.3.0'
  spec.dependency 'OpenWrapSDK', '2.7.0'
  spec.dependency 'AppLovinPubMaticAdapter', '1.0.2'
  spec.dependency 'BidMachine', '2.0.0.6'
  spec.dependency 'MolocoCustomAdapterAppLovin','1.1.0.1'
  
  spec.dependency 'GoogleMobileAdsMediationIronSource','7.2.7.0.1'
  spec.dependency 'OguryMediationGoogleMobileAds','4.1.1.0'
  spec.dependency 'GoogleMobileAdsMediationVungle','6.12.3.0'
  spec.dependency 'AdMobPubMaticAdapter','2.1.1'
end
