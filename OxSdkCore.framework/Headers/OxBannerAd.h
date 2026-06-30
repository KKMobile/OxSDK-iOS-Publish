//
//  OxBannerAd.h
//  OxSdkCore
//

#import "OxAd.h"
#import "IBannerAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxBannerAd : OxAd <IBannerAd>

- (void)handleAdLoaded;
- (void)handleAdLoadFailed:(NSString *)error;
- (void)handleAdDisplayed;
- (void)handleAdDisplayFailed:(NSString *)error errorCode:(NSInteger)errorCode;
- (void)handleAdClicked;
- (void)handleAdClosed;

- (void)showAdToContainer:(UIView *)adView container:(UIView *)container placement:(NSString *)placement;
- (BOOL)isContainerValid:(UIView *)container;

@end

NS_ASSUME_NONNULL_END
