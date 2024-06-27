//
//  OxAdManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/5/30.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdEvents.h"
#import "OxAdData.h"

@class AdReward;

NS_ASSUME_NONNULL_BEGIN

@protocol OxAdManagerDelegate <NSObject>

/// 获取到可用广告
- (void)onAdReceived:(NSString *)adUnitName;
- (void)onAdFinished:(NSString *)adUnitName errorType:(OxErrorType)errorType error:(nullable NSError *)error;

@end

@protocol OxAdActionDelegate <NSObject>

- (void)adDidOpen:(OxAdData *)adData;
- (void)adDidShow:(OxAdData *)adData;
- (void)adDidFailToShow:(OxAdData *)adData errorType:(OxErrorType)errorType error:(NSError *)error;
- (void)adDidClick:(OxAdData *)adData;
- (void)adDidClose:(OxAdData *)adData;

@optional
// 激励视频需要实现 获得奖励
- (void)adDidReward:(OxAdData *)adData adReward:(AdReward *)adReward;

@end

@interface OxAdManager : NSObject

+ (instancetype)sharedInstance;

/// 预加载广告
- (void)preload:(NSInteger)count adUnitName:(NSString *)adUnitName;

/// 加载广告
- (void)load:(NSInteger)count adUnitName:(NSString *)adUnitName delegate:(id<OxAdManagerDelegate>)delegate;

- (NSInteger)fetchAd:(NSString *)adUnitName;

/** 主动销毁广告
    销毁广告时机
    I/R/O 三个格式在 Close 之后销毁
    N/B/M 三个格式 在 Load 到新广告之后  调用 show 方法的时候销毁上个广告
    如果客户端有需要 可以主动提前销毁广告释放内存 如：Native 返回上个页面 已经不再需要的场景
*/
- (void)destoryAd:(NSString *)adUnitName showPlacement:(NSString *)showPlacement;

/** 主动销毁广告
    销毁广告时机
    I/R/O 三个格式在 Close 之后销毁
    N/B/M 三个格式 在 Load 到新广告之后  调用 show 方法的时候销毁上个广告
    如果客户端有需要 可以主动提前销毁广告释放内存 如：Native 返回上个页面 已经不再需要的场景
*/
- (void)destoryAd:(NSString *)adUnitName;

@end

NS_ASSUME_NONNULL_END
