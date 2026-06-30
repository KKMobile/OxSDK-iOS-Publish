//
//  PubMaticManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class MAAdView, MANativeAdLoader, MAInterstitialAd, MARewardedAd, MAAppOpenAd;

NS_ASSUME_NONNULL_BEGIN

@interface PubMaticManager : NSObject

+ (instancetype)sharedInstance;

- (void)initPubMatic;
- (void)enableBannerTest:(MAAdView *)adView enabled:(BOOL)enabled;
- (void)enableNativeTest:(MANativeAdLoader *)loader enabled:(BOOL)enabled;
- (void)enableMrecTest:(MAAdView *)adView enabled:(BOOL)enabled;
- (void)enableInterstitialTest:(MAInterstitialAd *)interstitialAd enabled:(BOOL)enabled;
- (void)enableRewardedTest:(MARewardedAd *)rewardedAd enabled:(BOOL)enabled;
- (void)enableOpenAdTest:(MAAppOpenAd *)openAd enabled:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
