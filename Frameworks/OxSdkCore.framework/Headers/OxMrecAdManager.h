//
//  OxMrecAdManager.h
//  OxSdkCore
//

#import "OxAdManager.h"
#import "IBannerAd.h"
#import "MrecAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxMrecAdManager : OxAdManager <IBannerAd>

+ (instancetype)createAdWithViewController:(UIViewController *)viewController
                                 adUnitName:(NSString *)adUnitName;

- (void)showAd:(UIView *)adContainerV;
- (void)showAd:(UIView *)adContainerV placement:(NSString *)placement;
- (void)hideAd;
- (void)stopAutoRefresh;
- (void)startAutoRefresh;

@end

NS_ASSUME_NONNULL_END
