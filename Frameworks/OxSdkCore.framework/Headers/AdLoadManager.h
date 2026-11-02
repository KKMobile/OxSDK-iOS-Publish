//
//  AdLoadManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class OxAdManager, OxAd, AdUnitBaseConfig, IdConfig;

NS_ASSUME_NONNULL_BEGIN

@interface AdLoadManager : NSObject

- (instancetype)initWithAdManager:(OxAdManager *)adManager
                    adUnitConfig:(nullable AdUnitBaseConfig *)adUnitConfig
                       adUnitIds:(NSArray<IdConfig *> *)adUnitIds;

- (void)loadAdInternal:(BOOL)isReload;
- (void)updateConfig:(nullable AdUnitBaseConfig *)newAdUnitConfig idConfigs:(NSArray<IdConfig *> *)newIdConfigs;

/// 标记业务是否已经发起过 load 请求（供 Banner/Mrec 判断配置变更后是否需要补触发一次加载）
- (void)setHasLoadRequested:(BOOL)hasLoadRequested;

/// 更新缓存广告的展示控制器，避免复用旧的展示上下文。
- (void)updateViewController:(nullable UIViewController *)viewController;

- (NSArray<OxAd *> *)getCacheAds;
- (BOOL)isReadyForCacheAd;
/// 缓存或 adMap 中第一个可用广告（供成功回调使用）
- (nullable OxAd *)firstReadyOxAd;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
