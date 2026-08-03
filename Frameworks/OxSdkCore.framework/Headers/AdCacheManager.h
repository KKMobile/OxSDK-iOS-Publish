//
//  AdCacheManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class OxAd, AdUnitBaseConfig, OxPlacementParams;

NS_ASSUME_NONNULL_BEGIN

@interface AdCacheManager : NSObject

- (void)addAd2Cache:(OxAd *)ad
           cacheAds:(NSMutableArray<OxAd *> *)cacheAds
       isOpenDynamic:(BOOL)isOpenDynamic
    adUnitBaseConfig:(AdUnitBaseConfig *)adUnitBaseConfig
    placementParams:(OxPlacementParams *)placementParams;

- (BOOL)isReadyForCacheAd:(NSMutableArray<OxAd *> *)cacheAds
            placementParams:(OxPlacementParams *)placementParams;

- (void)removeCachedIds:(NSMutableArray<NSString *> *)filteredIds
               cacheAds:(NSMutableArray<OxAd *> *)cacheAds;

@end

NS_ASSUME_NONNULL_END
