//
//  OxBaseAdHelperUtil.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/11/5.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class OxAd,OxAdInfo;

@interface OxBaseAdHelperUtil : NSObject

/// 应用禁用广告位列表，移除不需要加载的广告单元
/// @param filteredIds 可用广告位ID数组（可变）
/// @param adUnitIds 所有广告位ID数组
/// @param disableId  禁用广告位ID字符串（以分隔符分隔）
+ (void)applyDisableListWithFilteredIds:(NSMutableArray<NSString *> *)filteredIds
                              adUnitIds:(NSArray<NSString *> *)adUnitIds
                             disableIds:(NSString *)disableId;

/// 添加远端ID
/// @param remoteIds 要添加的远端ID
/// @param filteredIds 添加的数组
+ (void)addRemoteIds:(NSString *)remoteIds filteredIds:(NSMutableArray *)filteredIds;

// 移除已缓存的ID
+ (void)removeCachedIds:(NSMutableArray<NSString *> *)filteredIds
               cacheAds:(NSArray<OxAd *> *)cacheAds;

+ (NSArray<OxAdInfo *> *)convertToAdInfosWithFilteredIds:(NSArray<NSString *> *)filteredIds
                                               nativeIDs:(NSString *)nativeIDs
                                              baseFormat:(NSString *)baseFormat;

@end

NS_ASSUME_NONNULL_END
