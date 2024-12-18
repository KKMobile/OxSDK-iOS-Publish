//
//  AdEventUtil.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/14.
//

#import <Foundation/Foundation.h>
#import "OxAdSdkManager.h"
#import "OxAdShowLimitation.h"
NS_ASSUME_NONNULL_BEGIN
@interface AdEventUtil : NSObject

+ (void)trackAdEventByKey:(nonnull NSString *)key paramDic:(nullable NSDictionary *)params;

/// 客户端打点
+ (void)trackClientEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

// 请求广告
+ (void)trackAdRequestEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement;

// 加载成功
+ (void)trackAdLoadedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement      loadedDuration:(double)loadedDuration bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName
    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses latencyMillis:(double)latencyMillis creativeId:(nullable NSString*)creativeId revenue:(double)revenue;

// 加载失败
+ (void)trackAdLoadFailedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement error:(nullable NSString*)error failedDuration:(double)failedDuration;

// 客户端调用 showAd 系列方法
+ (void)trackAdShowEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement      limitation:(nullable NSString*)limitation;

// 客户端调用 showAd 后，Sdk 进行必要检查（比如 isReady（）），检查通过后调用 Mediation 的广告展示 API。
+ (void)trackAdShowingEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement networkNamee:(nullable NSString *) networkName creativeId:(nullable NSString *)creativeId;

// 广告展示成功（Displayed 回调）。
+ (void)trackAdImpressionEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName
    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses latencyMillis:(double)latencyMillis creativeId:(nullable NSString*)creativeId revenue:(double)revenue;

/// 达到限制
+ (void)trackAdMemoryLimitedEvent:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement;

// 广告展示失败（DisplayFailed 回调）。
+ (void)trackAdShowFailedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName
    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses creativeId:(nullable NSString*)creativeId error:(nullable NSString*)error failedDuration:(double)failedDuration;

// 广告被点击
+ (void)trackAdClickEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName
    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses creativeId:(nullable NSString*)creativeId revenue:(double)revenue;

// 广告被关闭。
+ (void)trackAdCloseEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName
    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses latencyMillis:(double)latencyMillis creativeId:(nullable NSString*)creativeId revenue:(double)revenue showingDuration:(double)showingDuration;

// 获得 RV 奖励。
+ (void)trackAdGottenCreditAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement networkName:(nullable NSString*)networkName
    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses creativeId:(nullable NSString*)creativeId revenue:(double)revenue;

+ (int)getFrequencyOfEvent:(CountedEvents)event;

+ (NSInteger)getNetworkState;

@end

NS_ASSUME_NONNULL_END
