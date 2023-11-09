#
#  Be sure to run `pod spec lint OxSdkForGames.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "OxSdkForGames"#SDK名称
  spec.version      = "1.1.3.3-Lite2-RCO1-20231109"#版本号
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
  spec.source_files = ['Games_Size/Adapter/Google/GADMSmaatoAdapter/*',
                       'Games_Size/Adapter/Google/GADMMintegralAdapter/*',
                       'Games_Size/Adapter/Max/Mintegral/*']

  spec.dependency 'OxSdkForGames','1.1.3.3-Lite1-RCO1-20231109'
  spec.dependency 'AppLovinMediationChartboostAdapter', '9.2.0.0'
  spec.dependency 'AppLovinMediationMobileFuseAdapter', '1.4.4.0'
  spec.dependency 'AppLovinMediationSmaatoAdapter', '22.0.2.0'
  spec.dependency 'AppLovinMediationMintegralAdapter', '7.3.5.0.0'
  spec.dependency 'AppLovinMediationLineAdapter', '2.6.20230215'
  
  spec.dependency 'GoogleMobileAdsMediationChartboost','9.2.0.0'
  spec.dependency 'MobileFuseAdMobAdapter','1.4.4.0'
  spec.dependency 'FiveGADAdapter','1.5.0'
  
end
