//
//  OxAdCacheManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/11/5.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class OxAd;

@interface OxAdCacheManager : NSObject

/// 添加广告到缓存，并按收入排序（高收入在前）
/// @param ad 新广告对象
/// @param cacheAds 当前广告缓存数组（NSMutableArray）
/// @param maxCacheSize 最大缓存数量（超过则移除最低收入的广告）
+ (void)addAdToCache:(OxAd *)ad
            cacheAds:(NSMutableArray<OxAd *> *)cacheAds
        maxCacheSize:(NSInteger)maxCacheSize;

@end

NS_ASSUME_NONNULL_END
