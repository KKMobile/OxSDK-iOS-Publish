//
//  OxBannerAdManager.h
//  OxSdkCore
//

#import "OxAdManager.h"
#import "IBannerAd.h"
#import "BannerAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/** OxBannerAdManager：按逻辑广告位创建并管理 banner 广告；在主线程调用涉及页面、容器和视图的 API。 */
@interface OxBannerAdManager : OxAdManager <IBannerAd>

@property (nonatomic, assign) BOOL adaptive;

/// 按逻辑广告位创建/复用 Manager；页面用于实际展示，不是广告网络 ID。
+ (instancetype)createAdWithViewController:(UIViewController *)viewController
                                 adUnitName:(NSString *)adUnitName;

/// 展示已加载广告。View 广告需有效容器，全屏广告需有效页面；isReady 为 YES 仍不保证网络最终展示成功。
- (void)showAd:(UIView *)adContainerV;
/// 展示已加载广告。View 广告需有效容器，全屏广告需有效页面；isReady 为 YES 仍不保证网络最终展示成功。
- (void)showAd:(UIView *)adContainerV placement:(NSString *)placement;
/// 隐藏当前视图广告；需要重新可见时再次调用 show。
- (void)hideAd;
/// 停止自动刷新，页面离开前可调用。
- (void)stopAutoRefresh;
/// 开启广告网络支持的自动刷新；不等同于立即加载。
- (void)startAutoRefresh;

@end

NS_ASSUME_NONNULL_END
