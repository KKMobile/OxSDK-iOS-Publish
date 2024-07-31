//
//  OxAdLoader.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/5/31.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OxAdUnit.h"

@class OxAd,OxAdLoader;

typedef enum : NSUInteger {
    OxAdLoadTypeManualLoad,
    OxAdLoadTypePreload,
    OxAdLoadTypeRetryLoad
} OxAdLoadType;

NS_ASSUME_NONNULL_BEGIN

@protocol OxAdLoaderDelegate <NSObject>

/// 获取到部分广告后就会被调用，在一次获取过程中可能被多次调用
/// - Parameter ads: 获取到的广告列表
- (void)onAdReceived:(OxAdLoader *)adLoader ad:(OxAd *)ad;

/// 整个获取广告过程结束时调用，在一次获取过程过程中只会调用一次，并且，该方法被调用后，不会再有任何回调发生。
/// - Parameter error: 错误码。如果为空，表示之前的onAdReceived回调已经返回了足够的广告，如果不为空，则表示表示之前的onAdReceived回调没有返回足够的广告。
- (void)onAdFinished:(OxAdLoader *)adLoader error:(nullable NSError *)error;

@end

@interface OxAdLoader : NSObject

@property(nonatomic, assign,readonly) NSInteger requiresLoadCount;  // 要请求几次
@property(nonatomic, assign,readonly) NSInteger mRetryCount;  // 重试次数
@property(nonatomic, assign,readonly) NSInteger failedCount;  // 请求失败几次 用来执行重试逻辑
@property(nonatomic, assign,readonly) BOOL loading;
@property(nonatomic, assign,readonly) OxAdLoadType loadType;
@property(nonatomic, assign,readonly) OxSdkAdFormat adFormat;

- (instancetype)initWithAdUnitName:(NSString *)adUnitName;
/// load ad
/// - Parameters:
///   - count: 数量
///   - placementName: placement
///   - delegate: 监听
- (void)load:(NSInteger)count delegate:(id<OxAdLoaderDelegate>)delegate;

/// 取消广告的加载, 对于同一个AcbNativeAdLoader实例对象，调用了cancel方法后，不应该再调用load方法
- (void)cancel;

// 执行重试逻辑
- (void)reloaded:(NSInteger)count;

@end

NS_ASSUME_NONNULL_END
