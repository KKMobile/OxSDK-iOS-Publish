//
//  OxStrategy.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class AdHelperConfigManager, AdUnitBaseConfig, OxAdParams, OxPlacementParams;

@protocol AdDelegate;
@protocol AdInternalListener;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, OxStrategyLoadType) {
    OxStrategyLoadTypeCloseReload = 0,
    OxStrategyLoadTypeShowFailReload,
    OxStrategyLoadTypeFailReload,
    OxStrategyLoadTypeNetworkReload,
};

@interface OxStrategy : NSObject

- (void)setAdUnitBaseConfig:(nullable AdUnitBaseConfig *)adUnitConfig;

- (void)canReloadWithConfigManager:(AdHelperConfigManager *)configManager
                          loadType:(OxStrategyLoadType)loadType
                        isNotMaxAd:(BOOL)isNotMaxAd
                      loadAdAction:(dispatch_block_t)loadAdAction
                           isReady:(BOOL)isReady;

- (BOOL)canNotLoadAdWithConfigManager:(AdHelperConfigManager *)configManager
                             listener:(nullable id<AdDelegate>)listener;

- (BOOL)canNotShowAdWithPlacementParams:(OxPlacementParams *)placementParams
                               adParams:(nullable OxAdParams *)adParams
                                adIsReady:(BOOL)adIsReady
                                 listener:(nullable id<AdDelegate>)listener
                     adInternalListener:(nullable id<AdInternalListener>)adInternalListener;

- (void)clientInvokingShowAdWithLimitation:(nullable NSString *)limitation
                          placementParams:(OxPlacementParams *)placementParams
                                  isReady:(BOOL)isReady;

- (void)resetRetry;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
