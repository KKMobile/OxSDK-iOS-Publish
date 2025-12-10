//
//  OxStrategyManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/11/4.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@class OxAdConfigManager,OxPlacementParams,OxAdParams;

@interface OxStrategyManager : NSObject

- (void)setConfig:(OxAdConfigManager *)adConfigManager;


/**
 * @brief 检查是否可以执行广告重新加载操作
 *
 * 根据不同的重载类型（关闭重载、失败重载、网络重载）判断是否应当重新加载广告。
 * 该方法会综合判断配置项、网络状态以及广告就绪状态。
 *
 * @param loadType  重载类型，参见 OxAdLoadType 枚举
 * @param isMaxAd 是否是 MAX 聚合
 * @param adFormat  广告格式（如 Rewarded、Interstitial、OpenAds、Native）
 * @param isReady   当前广告是否已准备就绪
 * @param completion 结果回调块，返回是否允许重新加载：
 *                   - YES：允许重载
 *                   - NO：不允许重载
 */
- (void)checkCanReloadWithType:(OxAdLoadType)loadType
                       isMaxAd:(BOOL)isMaxAd
                      adFormat:(NSString *)adFormat
                       isReady:(BOOL)isReady
                    completion:(void (^)(BOOL canReload))completion;

- (BOOL)canShowAd:(OxPlacementParams *)placementParams
         adParams:(OxAdParams *)adParams
        adIsReady:(BOOL)adIsReady;
- (BOOL)isMemoryLimitReached:(OxPlacementParams *)placementParams
                    adParams:(OxAdParams *)adParams;
- (BOOL)isAdReady:(OxPlacementParams *)placementParams
         adParams:(OxAdParams *)adParams
        adIsReady:(BOOL)adIsReady;

- (void)onClientShowingLimitationWithPalcementParams:(OxPlacementParams *)placementParams isReady:(BOOL)isReady limitation:(NSString *)limitation;

- (void)clientInvokingShowAdWithPalcementParams:(OxPlacementParams *)placementParams adParams:(OxAdParams *)adParams isReady:(BOOL)isReady limitation:(NSString *)limitation;

- (BOOL)canLoadAd:(OxPlacementParams *)placementParams;

- (void)reset;
- (void)destory;

@end

NS_ASSUME_NONNULL_END
