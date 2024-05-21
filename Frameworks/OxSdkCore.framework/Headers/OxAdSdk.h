//
//  OxAdSdk.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2023/6/9.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OxAdSdkManager.h"
#import "OxGamesEventUtil.h"

#define OxSDK_VERSION    @"1.2.0.0"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdSdk : NSObject

/// 获取版本号
+ (NSString *)getSdkVersion;

/// 初始化 OxAdSdk。
+ (void)initialize:(OnSdkInitComplete)successBlock;

/// 延迟初始化 OxAdSdk。
/// - Parameters:
///   - delayInMills: 延迟时间
+ (void)initializeWithDelayInMills:(int)delayInMills successBlock:(OnSdkInitComplete)successBlock;

/// 切换到指定的mediation
+ (void)switchMediation:(OxSdkMediationType)mediation;

///  Remote Config 获取完成后，通知 OxAdSdk。
+ (void)onRemoteConfigFetchCompleted;

/// 判断 Sdk 是否初始化完成。
+ (BOOL)isSdkInitialed;

/// 开启、关闭 OxSdk 测试模式。
+ (void)enableDebug:(BOOL)enable;

/// 是否开启测试模式。
+ (BOOL)isDebugEnabled;

/// 设置 OxSdk 打点回调。
+ (void)setAdEventDelegate:(id<AdEventDelegate>)delegate;

/// 展示测试套件，目前仅支持 Max 聚合平台。
+ (void)showMediationDebugger;

/// 设置用户是否在 ConsentDialog 中选择接收。
+ (void)setHasUserConsent:(BOOL)hasUserConsent;

///      RewardedVideo 广告展示时，初始静音状态。
///      仅对部分广告网络生效。
+ (void)setMute:(BOOL)mute;

/// 当前 Medaition。
+ (OxSdkMediationType)getMediation;

/// 设置核心 Level。
+ (void)setCoreLevel:(int)level;

/// 设置用户 Id。
+ (void)setUserId:(NSString *)userIdentifier;

/// 设置应用安装天数，安装当天计为 1。
+ (void)setDayCountSinceInstall:(int)count;

/**
 * 获取 Sdk 上报目标事件的次数。
 *
 * @param event 事件对应的序号，取值范围：{@link CountedEvents}
 * @return 目标事件上报次数。当传入的参数超出范围时，返回 -1。
 */
+ (int)getFrequencyOfEvent:(CountedEvents)event;

/// 获取全生命周期广告累计价值。
+ (double)getLtAdValue;


/// 客户端上报商业化相关打点。
+ (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

/// 客户端上报商业化相关打点。 用户游戏 过关 死局等
/// - Parameters:
///   - eventType: 打点类型
///   - value: 打点的值，如果是custom value 直接传 eventname
///   - params: params
+ (void)trackGamesEvent:(GamesEventType)eventType value:(NSString *)value params:(nullable NSDictionary *)params;

/// 获取google的adaptive Banner的尺寸，方便页面布局
+ (CGSize)getAdaptiveBannerAdSize;


@end

NS_ASSUME_NONNULL_END
