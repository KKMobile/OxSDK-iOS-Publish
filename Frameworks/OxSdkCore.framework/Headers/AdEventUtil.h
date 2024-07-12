//
//  AdEventUtil.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/14.
//

#import <Foundation/Foundation.h>
#import "OxAdSdkManager.h"
#import "OxAdShowLimitation.h"
#import "OxError.h"
NS_ASSUME_NONNULL_BEGIN

@class OxAd,OxAdData;

@interface AdEventUtil : NSObject

+ (void)logMaxImpressionRevenue:(MAAd *)ad placement:(NSString *)placement;
+ (void)logAdmobImpressionRevenue:(NSString *)adUnitId adFormat:(NSString *)adFormat adNetwork:(NSString *)adNetwork advalue:(GADAdValue *)advalue placement:(NSString *)placement;

/// 记录事件，回传给客户端。
+ (void)recordEvent:(NSString *)name paramDic:(NSDictionary *)params;

+ (void)trackAdEventByKey:(nonnull NSString *)key paramDic:(nullable NSDictionary *)params;


/// 客户端打点
+ (void)trackClientEvent:(NSString *)eventName params:(nullable NSDictionary *)params;
+ (void)trackGamesEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

/// 请求的 广告格式
/// - Parameters:
///   - adFormat: format
///   - adUnitName:  adUnitName
///   - adUnitId: adUnitId 可以为空
///   - errorCode: 错误信息
+ (void)trackAdRequestEventAdformat:(OxSdkAdFormat)adFormat adUnitName:(NSString *)adUnitName adUnitId:(nullable NSString *)adUnitId limitation:(nullable NSString *)limitation;

+ (void)trackAdLoadedEventAdformat:(OxAd *)ad;
+ (void)trackAdLoadedFailedEventAdformat:(OxSdkAdFormat)adFormat adUnitName:(NSString *)adUnitName adUnitId:(NSString *)adUnitId  error:(NSString *)error failedDuration:(double)failedDuration;
+ (void)trackAdShowEventAdformat:(OxSdkAdFormat)adFormat adUnitName:(NSString *)adUnitName showPlacement:(NSString *)showPlacement ad:(OxAd *)ad limitation:(nullable NSString *)limitation;
+ (void)trackAdShowingEventAdformat:(OxAd *)ad;
+ (void)trackAdMemoryLimitedEvent:(OxAd *)ad;
+ (void)trackAdImpressionEventAdformat:(OxAd *)ad;
+ (void)trackAdShowFailedEventAdformat:(OxAd *)ad error:(NSString *)error;
+ (void)trackAdClickEventAdformat:(OxAd *)ad;
+ (void)trackAdCloseEventAdformat:(OxAd *)ad;
+ (void)trackAdGottenCreditAdformat:(OxAd *)ad;



//// 请求广告
//+ (void)trackAdRequestEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement;
//
//// 加载成功
//+ (void)trackAdLoadedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement      loadedDuration:(double)loadedDuration bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName
//    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses latencyMillis:(double)latencyMillis creativeId:(nullable NSString*)creativeId revenue:(double)revenue;
//
//// 加载失败
//+ (void)trackAdLoadFailedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement error:(nullable NSString*)error failedDuration:(double)failedDuration;
//
//// 客户端调用 showAd 系列方法
//+ (void)trackAdShowEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement      limitation:(nullable NSString*)limitation;
//
//// 客户端调用 showAd 后，Sdk 进行必要检查（比如 isReady（）），检查通过后调用 Mediation 的广告展示 API。
//+ (void)trackAdShowingEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement networkNamee:(nullable NSString *) networkName creativeId:(nullable NSString *)creativeId;
//
//// 广告展示成功（Displayed 回调）。
//+ (void)trackAdImpressionEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName
//    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses latencyMillis:(double)latencyMillis creativeId:(nullable NSString*)creativeId revenue:(double)revenue;
//
///// 达到限制
//+ (void)trackAdMemoryLimitedEvent:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement;
//
//// 广告展示失败（DisplayFailed 回调）。
//+ (void)trackAdShowFailedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName
//    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses creativeId:(nullable NSString*)creativeId error:(nullable NSString*)error failedDuration:(double)failedDuration;
//
//// 广告被点击
//+ (void)trackAdClickEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName
//    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses creativeId:(nullable NSString*)creativeId revenue:(double)revenue;
//
//// 广告被关闭。
//+ (void)trackAdCloseEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName
//    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses latencyMillis:(double)latencyMillis creativeId:(nullable NSString*)creativeId revenue:(double)revenue showingDuration:(double)showingDuration;
//
//// 获得 RV 奖励。
//+ (void)trackAdGottenCreditAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(nullable NSString *)placement networkName:(nullable NSString*)networkName
//    waterfallName:(nullable NSString*)waterfullName networkResponses:(NSInteger)networkResponses creativeId:(nullable NSString*)creativeId revenue:(double)revenue;

+ (int)getFrequencyOfEvent:(CountedEvents)event;
+ (void)countEventIfShould:(NSString *)name;
+ (NSArray *)eventsShouldBeCounted;

+ (NSInteger)getNetworkState;

@end

NS_ASSUME_NONNULL_END
