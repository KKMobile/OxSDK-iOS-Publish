//
//  OxNativeAdManager.h
//  OxSdkCore
//

#import "OxAdManager.h"
#import "IViewAd.h"
#import "NativeAdDelegate.h"
#import "OxNativeViewBinder.h"

@class AdUnitBaseConfig;

NS_ASSUME_NONNULL_BEGIN

@interface OxNativeAdManager : OxAdManager <IViewAd>

@property (nonatomic, strong, nullable) OxNativeViewBinder *viewBinder;

+ (instancetype)createAdWithViewController:(UIViewController *)viewController
                                 adUnitName:(NSString *)adUnitName;

+ (instancetype)createAdWithViewController:(UIViewController *)viewController
                              adUnitConfig:(AdUnitBaseConfig *)adUnitConfig
                                 adUnitName:(NSString *)adUnitName;

- (void)setViewBinder:(OxNativeViewBinder *)binder;
- (void)showAd:(UIView *)adContainerV;
- (void)showAd:(UIView *)adContainerV placement:(NSString *)placement;
- (void)hideAd;

@end

NS_ASSUME_NONNULL_END
