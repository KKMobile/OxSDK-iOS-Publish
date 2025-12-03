//
//  AdEventUtil.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/14.
//

#import <Foundation/Foundation.h>
#import "OxAdSdkManager.h"

@class OxAdParams,OxPlacementParams;

NS_ASSUME_NONNULL_BEGIN
@interface AdEventUtil : NSObject

/// MAX 价值打点
/// - Parameters:
///   - ad: max ad
///   - mAdEventParams: 参数
+ (void)logMaxImpressionRevenueWithAd:(MAAd *)ad mAdEventParams:(OxAdParams *)mAdEventParams;

/// Admob 价值打点
/// - Parameters:
///   - advalue: admob ad
///   - adNetwork: network
///   - mAdEventParams: 参数
+ (void)logAdmobImpressionRevenueWithAd:(GADAdValue *)advalue adNetwork:(NSString *)adNetwork AdEventParams:(OxAdParams *)mAdEventParams;

// uservalue
+ (void)logAdUserValueError:(NSString *)error;
+ (void)logAdUserValueError:(NSString *)error type:(AdUserValueErrorType)type;
+ (void)logAdUserValue:(NSString *)adUnitId count:(NSInteger)count value:(float)value isNewPeriod:(BOOL)isNewPeriod;
+ (void)logAdUserValueSegment:(NSString *)adUnitId value:(float)value factor:(float)factor segmentValue:(NSString *)segmentValue;
+ (void)logAdUserValueNoSegment:(NSString *)adUnitId value:(float)value factor:(float)factor;
+ (void)logAdSegment:(NSDictionary *)segmentMap;

+ (void)trackClientEvent:(NSString *)eventName params:(nullable NSDictionary *)params;


+ (void)trackAdEventByKey:(nonnull NSString *)key paramDic:(nullable NSDictionary *)params;

/// 客户端请求广告。
+ (void)trackAdRequestEvent:(OxPlacementParams *)params;

/// OxSdk 内部 Adapter 请求广告。
+ (void)trackAdapterRequestEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// 因为某些原因，没有给 App 回调事件上报
+ (void)trackListenerInterruptEvent:(OxPlacementParams *)params eventName:(NSString *)eventName errorMsg:(NSString *)errorMsg;

/// Max 中 Aps Load
+ (void)trackApsLoadRequestEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// Max 中 Aps 加载完成（包括成功失败）
+ (void)trackApsLoadFinishEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// 删除过期缓存的时候上报
+ (void)trackDeleteExpireAdEvent:(OxPlacementParams *)params deleteSize:(NSInteger)deleteSize cacheSize:(NSInteger)cacheSize;

/// 客户端广告加载完成。
+ (void)trackAdLoadedEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// OxSdk 内部 Adapter 加载完成。
+ (void)trackAdAdapterLoadedEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// OxSdk 广告加载失败。
+ (void)trackAdAdapterLoadFailedEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// 客户端广告加载失败。
+ (void)trackAdLoadFailedEvent:(OxPlacementParams *)params adParams:(nullable OxAdParams *)adParams;

/// 客户端广告展示。
+ (void)trackAdShowEvent:(OxPlacementParams *)params limitation:(NSString *)limitation;

/// 客户端调用 showAd 后，Sdk 进行必要检查（比如 isReady），检查通过后调用 Mediation 的广告展示 API。
+ (void)trackAdShowingEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// 应用剩余过低，达到设定阈值时，不再展示广告，并上报该事件。
+ (void)trackAdMemoryLimitedEvent:(OxPlacementParams *)params;

/// 客户端广告展示成功（Displayed 回调）。
+ (void)trackAdImpressionEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// OxSdk 广告展示成功（Displayed 回调）。
+ (void)trackAdAdapterImpressionEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// 客户端广告展示失败（DisplayFailed 回调）。
+ (void)trackAdShowFailedEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// OxSdk 广告展示失败（DisplayFailed 回调）。
+ (void)trackAdAdapterShowFailedEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// 客户端广告被点击。
+ (void)trackAdClickEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// OxSdk 广告被点击。
+ (void)trackAdAdapterClickEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// 客户端广告被关闭。
+ (void)trackAdCloseEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// OxSdk 广告被关闭。
+ (void)trackAdAdapterCloseEvent:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// 客户端获得 RV 奖励。
+ (void)trackAdGottenCredit:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;

/// OxSdk 获得 RV 奖励。
+ (void)trackAdAdapterGottenCredit:(OxPlacementParams *)params adParams:(OxAdParams *)adParams;


+ (int)getFrequencyOfEvent:(CountedEvents)event;
+ (void)countEventIfShould:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
