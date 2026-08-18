//
//  OxAdPool.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/8/19.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OxAd;
@class OxAdCachedList;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdPool : NSObject

- (instancetype)initWithType:(NSString *)type;

/// 插入一条广告. 如果广告类型与当前池子匹配则接收, 否则丢弃
- (void)put:(OxAd * _Nullable)ad;

/// 取出某个广告类型下缓存的广告
- (NSArray<OxAd *> *)get:(NSString * _Nullable)adFormat;

/// 返回某个 AdPlacement 下所有缓存的广告
- (NSArray<OxAd *> *)getAll:(NSString * _Nullable)adPlacement;

@end

NS_ASSUME_NONNULL_END
