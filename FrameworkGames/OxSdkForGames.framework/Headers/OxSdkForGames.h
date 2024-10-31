//
//  OxSdkForGames.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/10/21.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OxSdkForGames/AdDelegate.h>
#import <OxSdkForGames/AdEventDelegate.h>
#import <OxSdkForGames/AdEventDelegateHelper.h>
#import <OxSdkForGames/AdEventUtil.h>
#import <OxSdkForGames/AdEvents.h>
#import <OxSdkForGames/AdInternalAdDelegate.h>
#import <OxSdkForGames/AdLTVTracker.h>
#import <OxSdkForGames/AdMobAdSdkManager.h>
#import <OxSdkForGames/AdReward.h>
#import <OxSdkForGames/AdmobBannerAdHelper.h>
#import <OxSdkForGames/AdmobInterstitialAdHelper.h>
#import <OxSdkForGames/AdmobMrecAdHelper.h>
#import <OxSdkForGames/AdmobOpenAdsHelper.h>
#import <OxSdkForGames/AdmobRewardedAdHelper.h>
#import <OxSdkForGames/AppUtils.h>
#import <OxSdkForGames/ApsAdManager.h>
#import <OxSdkForGames/ApsBannerAdManager.h>
#import <OxSdkForGames/ApsBaseAdManager.h>
#import <OxSdkForGames/ApsInterstitialAdManager.h>
#import <OxSdkForGames/ApsMRecAdManager.h>
#import <OxSdkForGames/ApsRewardedAdManager.h>
#import <OxSdkForGames/BannerAdDelegate.h>
#import <OxSdkForGames/BannerInternalAdDelegate.h>
#import <OxSdkForGames/BaseAdManager.h>
#import <OxSdkForGames/BaseConsentManager.h>
#import <OxSdkForGames/ConsentPopupView.h>
#import <OxSdkForGames/DataTools.h>
#import <OxSdkForGames/GDPRConsentants.h>
#import <OxSdkForGames/GoogleConsentManager.h>
#import <OxSdkForGames/IBannerAd.h>
#import <OxSdkForGames/IFullScreenAd.h>
#import <OxSdkForGames/IViewAd.h>
#import <OxSdkForGames/InterstitialAdDelegate.h>
#import <OxSdkForGames/InterstitialInternalAdDelegate.h>
#import <OxSdkForGames/KeywordsAndUserPropertiesManager.h>
#import <OxSdkForGames/MaxAdSdkManager.h>
#import <OxSdkForGames/MaxBannerAdHelper.h>
#import <OxSdkForGames/MaxConsentManager.h>
#import <OxSdkForGames/MaxInterstitialAdHelper.h>
#import <OxSdkForGames/MaxMrecAdHelper.h>
#import <OxSdkForGames/MaxOpenAsdHelper.h>
#import <OxSdkForGames/MaxRewardedAdHelper.h>
#import <OxSdkForGames/MrecAdDelegate.h>
#import <OxSdkForGames/MrecInternalAdDelegate.h>
#import <OxSdkForGames/OXLogMoudle.h>
#import <OxSdkForGames/OpenAdsAdDelegate.h>
#import <OxSdkForGames/OpenAdsInternalAdDelegate.h>
#import <OxSdkForGames/OxAdHelper.h>
#import <OxSdkForGames/OxAdSdkManager.h>
#import <OxSdkForGames/OxAdShowLimitation.h>
#import <OxSdkForGames/OxAdjustTokens.h>
#import <OxSdkForGames/OxAdjustTokensBuilder.h>
#import <OxSdkForGames/OxBannerAdHelper.h>
#import <OxSdkForGames/OxConsentMananger.h>
#import <OxSdkForGames/OxCustomMaxAdapter.h>
#import <OxSdkForGames/OxEventLogger.h>
#import <OxSdkForGames/OxFBEventLogger.h>
#import <OxSdkForGames/OxFirebaseEventLogger.h>
#import <OxSdkForGames/OxAdjustEventLogger.h>
#import <OxSdkForGames/OxDiscoveryHelper.h>
#import <OxSdkForGames/OxInterstitialAdHelper.h>
#import <OxSdkForGames/OxKeywordType.h>
#import <OxSdkForGames/OxMAAdRevenueDelegateImpl.h>
#import <OxSdkForGames/OxMrecAdHelper.h>
#import <OxSdkForGames/OxNativeInterUtil.h>
#import <OxSdkForGames/OxNetworkReachabilityManager.h>
#import <OxSdkForGames/OxOpenAdsAdHelper.h>
#import <OxSdkForGames/OxPrefManager.h>
#import <OxSdkForGames/OxPreferenceManager.h>
#import <OxSdkForGames/OxRemoteConfigHelper.h>
#import <OxSdkForGames/OxRemoteConfigKeys.h>
#import <OxSdkForGames/OxResBundleUtil.h>
#import <OxSdkForGames/OxRewardedAdHelper.h>
#import <OxSdkForGames/OxSdkForGames.h>
#import <OxSdkForGames/OxTAEventLogger.h>
#import <OxSdkForGames/OxUnitAdsGdprUtil.h>
#import <OxSdkForGames/PrivacyPopupView.h>
#import <OxSdkForGames/OxPubMaticAdHelper.h>
#import <OxSdkForGames/Reachability.h>
#import <OxSdkForGames/RewardedAdDelegate.h>
#import <OxSdkForGames/RewardedInternalAdDelegate.h>
#import <OxSdkForGames/UIImageViewAligned.h>

//! Project version number for OxSdkForGames.
FOUNDATION_EXPORT double OxSdkForGamesVersionNumber;

//! Project version string for OxSdkForGames.
FOUNDATION_EXPORT const unsigned char OxSdkForGamesVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <OxSdkForGames/PublicHeader.h>


