//
//  OxAdPoolManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/8/19.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OxAd;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdPoolManager : NSObject

+ (instancetype)sharedInstance;

/// 在缓存池中添加引用 在成功或者失败之后移除 为了回收缓存
//- (void)addLoadingAd:(OxAd *)ad;
//- (void)removeLoadingAd:(OxAd *)ad;

/// 插入一条广告
- (void)put:(OxAd * _Nullable)ad;

/// 插入若干条广告
- (void)putList:(NSArray<OxAd *> * _Nullable)ads;

/// 取若干条广告
- (NSArray<OxAd *> *)getWithAdType:(NSString *)adType adFormat:(NSString *)adFormat;

@end

NS_ASSUME_NONNULL_END
