//
//  OxBannerAdManager.h
//  OxSdkCore
//

#import "OxAdManager.h"
#import "IBannerAd.h"
#import "BannerAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxBannerAdManager : OxAdManager <IBannerAd>

@property (nonatomic, assign) BOOL adaptive;

+ (instancetype)createAdWithViewController:(UIViewController *)viewController
                                 adUnitName:(NSString *)adUnitName;

- (void)showAd:(UIView *)adContainerV;
- (void)showAd:(UIView *)adContainerV placement:(NSString *)placement;
- (void)hideAd;
- (void)stopAutoRefresh;
- (void)startAutoRefresh;

@end

NS_ASSUME_NONNULL_END
