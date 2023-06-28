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

+ (void)enableBannerTest:(MAAdView*)adView enabled:(bool)enabled;

+ (void)enableMrecTest:(MAAdView*)adView enabled:(bool)enabled;

+ (void)enableInterstitialTest:(MAInterstitialAd*)interstitialAd enabled:(bool)enabled;

+ (void)enableRewardedTest:(MARewardedAd*)rewardedAd enabled:(bool)enabled;

@end

NS_ASSUME_NONNULL_END
