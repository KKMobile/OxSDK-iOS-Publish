#
#  Be sure to run `pod spec lint OxSdkCore.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

    spec.name         = "OxSdkCore"#SDK名称
    spec.version      = "1.2.0.0-RC11-ADN-202401241900"#版本号
    spec.summary      = "OxAdSdk for core applications."#概要
    #描述  （描述一定要比概要多一些,不然会有警告!）
    spec.description  = <<-DESC
    OxAdSdk for game applications.OxAdSdk for core applications.
                   DESC
    spec.homepage     = "https://github.com/KKMobile/OxSDK-iOS-Publish.git"#github 上的仓库地址
    spec.license      = { :type => "MIT", :file => "LICENSE" }#创建GitHub仓库时使用的license类型
    spec.author             = { "OxDevelopers" => "tianci5275@gmail.com" }#作者
    spec.platform     = :ios#支持平台
    spec.ios.deployment_target = "12.0"#支持iOS最低版本
    spec.swift_version = '4.0'
    spec.source       = { :git => "https://github.com/KKMobile/OxSDK-iOS-Publish.git", :tag => "core-#{spec.version}" }
    spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件
    spec.requires_arc = true#是否时自动内存管理
    spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置


    spec.subspec 'APS' do |ss|
        ss.dependency 'AmazonPublisherServicesSDK','4.7.6.0'
        ss.dependency 'AppLovinMediationAmazonAdMarketplaceAdapter','4.7.6.0'
    end


    spec.subspec 'Admob_Applovin' do |ss|
        ss.dependency 'GoogleMobileAdsMediationAppLovin', '11.11.4.0'
    end

    spec.subspec 'Base' do |ss|

        ss.vendored_frameworks = 'Frameworks/OxSdkCore.framework'#SDK相对本文件路径
        ss.resources = ["ResBundle/Core/OxSdkRes.bundle","ResBundle/Core/Language.bundle"]
        
        ss.dependency 'PureLayout'
        ss.dependency 'AFNetworking'
        ss.dependency 'SDWebImage'
        ss.dependency 'Adjust'
        ss.dependency 'FirebaseAnalytics', '>=8.0.0'
        ss.dependency 'FirebaseRemoteConfig', '>=8.0.0'

        # Max Mediation
        ss.dependency 'AppLovinSDK', '11.11.4'
        ss.dependency 'Google-Mobile-Ads-SDK', '10.13.0'
        ss.dependency 'UnityAds', '4.9.0'
        ss.dependency 'FBAudienceNetwork', '6.14.0'
        ss.dependency 'OxSdkCore/APS'
        ss.dependency 'OxSdkCore/Admob_Applovin'
    end


    spec.subspec 'Admob' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationGoogleAdManagerAdapter', '10.13.0.0'
        ss.dependency 'AppLovinMediationGoogleAdapter', '10.13.0.0'
    end

    spec.subspec 'AdColony' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationAdColonyAdapter', '4.9.0.0.4'
        ss.dependency 'GoogleMobileAdsMediationAdColony','4.9.0.2'
    end

    spec.subspec 'UnityAds' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationUnityAdsAdapter', '4.9.0.0'
        ss.dependency 'GoogleMobileAdsMediationUnity','4.9.0.0'
        ss.vendored_frameworks = 'Frameworks/OxMaxCustomUnityAdsAdapter.framework'
    end


    spec.subspec 'Fyber' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationFyberAdapter', '8.2.4.0'
        ss.dependency 'GoogleMobileAdsMediationFyber','8.2.4.0'
        ss.vendored_frameworks = 'Frameworks/OxMaxCustomFyberAdapter.framework'
    end


    spec.subspec 'InMobi' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationInMobiAdapter', '10.6.0.0'
        ss.dependency 'ALInMobiCustomAdapterFramework', '10.6.0.0'
        ss.dependency 'GoogleMobileAdsMediationInMobi','10.6.0.0'
    end

    spec.subspec 'Facebook' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationFacebookAdapter','6.14.0.0'
        ss.dependency 'GoogleMobileAdsMediationFacebook','6.14.0.0'
    end

    spec.subspec 'OguryPresage' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationOguryPresageAdapter', '4.2.2.0'
        ss.dependency 'OguryMediationGoogleMobileAds','4.2.2.0'
    end

    spec.subspec 'Pangle' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationByteDanceAdapter', '5.5.0.9.0'
        ss.dependency 'GoogleMobileAdsMediationPangle','5.5.0.9.0'
        ss.vendored_frameworks = 'Frameworks/OxMaxCustomPangleAdapter.framework'
    end


    spec.subspec 'Smaato' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationSmaatoAdapter','22.4.0.0'
    end

    spec.subspec 'Verve' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationVerveAdapter', '2.20.0.0'
        ss.dependency 'GoogleMobileAds-HyBid-Adapters','2.20.0.0'
    end

    spec.subspec 'Mintegral' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationMintegralAdapter', '7.4.7.0.0'
        ss.vendored_frameworks = 'Frameworks/OxMaxCustomMintegralAdapter.framework'
    end

    spec.subspec 'BidMachine' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationBidMachineAdapter', '2.3.0.2'
    end

    spec.subspec 'IronSource' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationIronSourceAdapter', '7.5.1.0.0'
        ss.dependency 'GoogleMobileAdsMediationIronSource','7.5.1.0'
    end

    spec.subspec 'Yandex' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'YandexMobileAds', '5.9.1'
        ss.vendored_frameworks = 'Frameworks/OxMaxYandexAdapyer.framework'
    end

    spec.subspec 'Pubmatic' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'OpenWrapSDK', '3.2.0'
        ss.dependency 'AppLovinPubMaticAdapter', '1.1.0'
        ss.dependency 'AdMobPubMaticAdapter','2.2.0'
    end

    spec.subspec 'Chartboost' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationChartboostAdapter', '9.5.1.0'
        ss.dependency 'GoogleMobileAdsMediationChartboost','9.5.1.0'
    end
    
    spec.subspec 'MobileFuse' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationMobileFuseAdapter', '1.6.5.0'
        ss.dependency 'MobileFuseAdMobAdapter','1.6.5.0'
    end

    spec.subspec 'Vungle' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationVungleAdapter', '7.1.0.2'
        ss.dependency 'GoogleMobileAdsMediationVungle','7.1.0.0'
    end

    spec.subspec 'Line' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationLineAdapter', '2.6.20230609.0'
        ss.dependency 'FiveGADAdapter','1.5.0'
    end

    spec.subspec 'Moloco' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'MolocoCustomAdapterAppLovin','1.3.0.0'
    end

    spec.subspec 'HyprMX' do |ss|
        ss.dependency 'OxSdkCore/Base'
        ss.dependency 'AppLovinMediationHyprMXAdapter','6.3.0.0'
    end



    spec.subspec 'Games' do |ss|

    	ss.dependency 'OxSdkCore/Base'

    	ss.subspec 'Base' do |s|
	        s.dependency 'OxSdkCore/Admob'
	        s.dependency 'OxSdkCore/Facebook'
	        s.dependency 'OxSdkCore/UnityAds'
    	end

    	ss.subspec 'Lite1' do |s|
    		s.dependency 'OxSdkCore/Games/Base'

            s.dependency 'OxSdkCore/Fyber'
	        s.dependency 'OxSdkCore/InMobi'
	        s.dependency 'OxSdkCore/IronSource'
	        s.dependency 'OxSdkCore/OguryPresage'
	        s.dependency 'OxSdkCore/Pangle'
	        s.dependency 'OxSdkCore/Verve'
	        ss.dependency 'OxSdkCore/Vungle'
	        s.dependency 'OxSdkCore/Pubmatic'
	        s.dependency 'OxSdkCore/BidMachine'
	        s.dependency 'OxSdkCore/Moloco'
    	end

    	ss.subspec 'Lite2' do |s|
    		s.dependency 'OxSdkCore/Games/Base'
    		s.dependency 'OxSdkCore/Games/Lite1'

	        s.dependency 'OxSdkCore/Chartboost'
	        s.dependency 'OxSdkCore/MobileFuse'
	        s.dependency 'OxSdkCore/Smaato'
	        s.dependency 'OxSdkCore/Mintegral'
	        s.dependency 'OxSdkCore/Line'
    	end

        ss.dependency 'OxSdkCore/Yandex'
        ss.dependency 'OxSdkCore/HyprMX'

    end


    spec.subspec 'Tools' do |ss|
    	ss.dependency 'OxSdkCore/Base'

    	ss.subspec 'Base' do |s|
	        s.dependency 'OxSdkCore/Admob'
	        s.dependency 'OxSdkCore/Facebook'
    	end

    	ss.subspec 'Lite1' do |s|
    		s.dependency 'OxSdkCore/Tools/Base'

	        s.dependency 'OxSdkCore/Pangle'
    	end

    	ss.subspec 'Lite2' do |s|
    		s.dependency 'OxSdkCore/Tools/Lite1'
    		
	        s.dependency 'OxSdkCore/Fyber'
	        s.dependency 'OxSdkCore/InMobi'
	        s.dependency 'OxSdkCore/OguryPresage'
	        s.dependency 'OxSdkCore/UnityAds'
	        s.dependency 'OxSdkCore/Vungle'
    	end
    end


    spec.dependency 'OxDiscoveryPlugin','1.0.3-202312041600'
end
