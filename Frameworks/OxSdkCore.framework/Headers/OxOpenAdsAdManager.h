//
//  OxOpenAdsAdManager.h
//  OxSdkCore
//

#import "OxAdManager.h"
#import "IFullScreenAd.h"
#import "OpenAdsAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/** OxOpenAdsAdManager：按逻辑广告位创建并管理 openads 广告；在主线程调用涉及页面、容器和视图的 API。 */
@interface OxOpenAdsAdManager : OxAdManager <IFullScreenAd>

/// 按逻辑广告位创建/复用 Manager；页面用于实际展示，不是广告网络 ID。
+ (instancetype)createAdWithViewController:(UIViewController *)viewController
                                 adUnitName:(NSString *)adUnitName;

- (void)showAd;
/// 展示已加载广告。View 广告需有效容器，全屏广告需有效页面；isReady 为 YES 仍不保证网络最终展示成功。
- (void)showAd:(NSString *)placement;

@end

NS_ASSUME_NONNULL_END
