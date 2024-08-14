#
#  Be sure to run `ss.dependency spec lint OxSdkForTools.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|


  spec.name         = "OxSdkForTools"#SDK名称
  spec.version      = "1.2.0.1"#版本号
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
  
  
    spec.subspec 'Base' do |ss|
        ss.vendored_frameworks = 'Frameworks/OxSdkCore.framework'#SDK相对本文件路径
        ss.resources = ["ResBundle/Core/OxSdkRes.bundle","ResBundle/Core/Language.bundle"]
        
        ss.dependency 'PureLayout'
        ss.dependency 'AFNetworking'
        ss.dependency 'SDWebImage'
        ss.dependency 'Adjust'
        ss.dependency 'FirebaseAnalytics', '>=8.0.0'
        ss.dependency 'FirebaseRemoteConfig', '>=8.0.0'

        ss.dependency 'AppLovinSDK', '12.4.1'
        ss.dependency 'AmazonPublisherServicesSDK','4.9.3.0'
        ss.dependency 'AppLovinMediationGoogleAdManagerAdapter', '11.3.0.0'
        ss.dependency 'AppLovinMediationGoogleAdapter', '11.3.0.0'
        ss.dependency 'AppLovinMediationFacebookAdapter','6.15.0.0'
        ss.dependency 'GoogleMobileAdsMediationFacebook','6.15.0.0'
        ss.dependency 'GoogleMobileAdsMediationAppLovin','12.4.1.0'
    end
    
    spec.subspec 'UnityAds' do |ss|
        ss.source_files = ['Frameworks/MaxCustomAdapter/OxCustomUnityAdsAdapter.{h,m}']
        ss.dependency 'OxSdkForTools/Base'
        ss.dependency 'AppLovinMediationUnityAdsAdapter', '4.10.0.0'
    end
    
    spec.subspec 'Pangle' do |ss|
        ss.source_files = ['Frameworks/MaxCustomAdapter/OxCustomPangleAdapter.{h,m}']
        ss.dependency 'OxSdkForTools/Base'
        ss.dependency 'AppLovinMediationByteDanceAdapter', '5.9.0.7.0'
    end
    
    spec.subspec 'Mintegral' do |ss|
        ss.source_files = ['Frameworks/MaxCustomAdapter/OxCustomMintegralAdapter.{h,m}']
        ss.dependency 'OxSdkForTools/Base'
        ss.dependency 'AppLovinMediationMintegralAdapter', '7.6.1.0.0'
    end
    
    spec.subspec 'Fyber' do |ss|
        ss.source_files = ['Frameworks/MaxCustomAdapter/OxCustomFyberAdapter.{h,m}']
        ss.dependency 'OxSdkForTools/Base'
        ss.dependency 'AppLovinMediationFyberAdapter', '8.2.7.0'
    end
    
    spec.subspec 'Ogury' do |ss|
        ss.dependency 'OxSdkForTools/Base'
        ss.dependency 'AppLovinMediationOguryPresageAdapter', '4.3.0.0'
    end
    
    spec.subspec 'InMobi' do |ss|
        ss.dependency 'OxSdkForTools/Base'
        ss.dependency 'AppLovinMediationInMobiAdapter', '10.7.2.0'
        ss.dependency 'ALInMobiCustomAdapterFramework', '10.7.2.0'
    end
    
    spec.subspec 'Vungle' do |ss|
        ss.dependency 'OxSdkForTools/Base'
        ss.dependency 'AppLovinMediationVungleAdapter', '7.3.1.0'
    end
    
    
    spec.subspec 'Moloco' do |ss|
        ss.dependency 'OxSdkForTools/Base'
        ss.dependency 'AppLovinMediationMolocoAdapter', '3.0.0.1'
    end
        
  spec.dependency 'OxDiscoveryPlugin','1.0.3-202312041600'
    
end
