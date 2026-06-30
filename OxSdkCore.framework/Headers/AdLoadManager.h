//
//  AdLoadManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class OxAdManager, OxAd, AdUnitBaseConfig, IdConfig;

NS_ASSUME_NONNULL_BEGIN

@interface AdLoadManager : NSObject

- (instancetype)initWithAdManager:(OxAdManager *)adManager
                    adUnitConfig:(nullable AdUnitBaseConfig *)adUnitConfig
                       adUnitIds:(NSArray<IdConfig *> *)adUnitIds;

- (void)loadAdInternal:(BOOL)isReload;
- (void)updateConfig:(nullable AdUnitBaseConfig *)newAdUnitConfig idConfigs:(NSArray<IdConfig *> *)newIdConfigs;

- (NSArray<OxAd *> *)getCacheAds;
- (BOOL)isReadyForCacheAd;
/// 缓存或 adMap 中第一个可用广告（供成功回调使用）
- (nullable OxAd *)firstReadyOxAd;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
