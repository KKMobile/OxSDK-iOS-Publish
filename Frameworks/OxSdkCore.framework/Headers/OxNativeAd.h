//
//  OxNativeAd.h
//  OxSdkCore
//

#import "OxAd.h"
#import "IViewAd.h"

@class OxNativeViewBinder;

NS_ASSUME_NONNULL_BEGIN

@interface OxNativeAd : OxAd <IViewAd>

@property (nonatomic, strong, nullable, readonly) OxNativeViewBinder *mViewBinder;

- (void)handleAdLoaded;
- (void)handleAdLoadFailed:(NSString *)error;
- (void)handleAdDisplayed;
- (void)handleAdDisplayFailed:(NSString *)error errorCode:(NSInteger)errorCode;
- (void)handleAdClicked;
- (void)handleAdClosed;

- (void)setViewBinder:(OxNativeViewBinder *)binder;
- (void)showNativeAdToContainer:(UIView *)adView container:(UIView *)container placement:(NSString *)placement;
- (BOOL)isContainerValid:(UIView *)container;

@end

NS_ASSUME_NONNULL_END
