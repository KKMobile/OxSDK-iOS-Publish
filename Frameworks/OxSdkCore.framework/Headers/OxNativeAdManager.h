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

/** OxNativeAdManager：按逻辑广告位创建并管理 nativead 广告；在主线程调用涉及页面、容器和视图的 API。 */
@interface OxNativeAdManager : OxAdManager <IViewAd>

@property (nonatomic, strong, nullable) OxNativeViewBinder *viewBinder;

/// 按逻辑广告位创建/复用 Manager；页面用于实际展示，不是广告网络 ID。
+ (instancetype)createAdWithViewController:(UIViewController *)viewController
                                 adUnitName:(NSString *)adUnitName;

/// 按逻辑广告位创建/复用 Manager；页面用于实际展示，不是广告网络 ID。
+ (instancetype)createAdWithViewController:(UIViewController *)viewController
                              adUnitConfig:(AdUnitBaseConfig *)adUnitConfig
                                 adUnitName:(NSString *)adUnitName;

- (void)setViewBinder:(OxNativeViewBinder *)binder;
/// 展示已加载广告。View 广告需有效容器，全屏广告需有效页面；isReady 为 YES 仍不保证网络最终展示成功。
- (void)showAd:(UIView *)adContainerV;
/// 展示已加载广告。View 广告需有效容器，全屏广告需有效页面；isReady 为 YES 仍不保证网络最终展示成功。
- (void)showAd:(UIView *)adContainerV placement:(NSString *)placement;
/// 隐藏当前视图广告；需要重新可见时再次调用 show。
- (void)hideAd;

@end

NS_ASSUME_NONNULL_END
