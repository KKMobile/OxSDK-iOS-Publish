//
//  PubMaticManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/6/24.
//

#import <Foundation/Foundation.h>
@import AppLovinSDK;

NS_ASSUME_NONNULL_BEGIN

@interface PubMaticManager : NSObject

+ (void)init;

+ (void)enableBannerTest:(MAAdView*)adView;

+ (void)enableMrecTest:(MAAdView*)adView;

+ (void)enableInterstitialTest:(MAInterstitialAd*)interstitialAd;

+ (void)enableRewardedTest:(MARewardedAd*)rewardedAd;

@end

NS_ASSUME_NONNULL_END
