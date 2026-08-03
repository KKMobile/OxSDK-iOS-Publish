//
//  OxInterstitialAd.h
//  OxSdkCore
//

#import "OxAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxInterstitialAd : OxAd

- (void)handleAdLoaded;
- (void)handleAdLoadFailed:(NSString *)error;
- (void)handleAdDisplayed;
- (void)handleAdDisplayFailed:(NSString *)error errorCode:(NSInteger)errorCode;
- (void)handleAdClicked;
- (void)handleAdClosed;
- (void)showAdWithDelay:(dispatch_block_t)showBlock;

@end

NS_ASSUME_NONNULL_END
