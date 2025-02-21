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
+ (void)trackAdRequestEventAdformat:(OxSdkAdFormat)adFormat mediation:(OxSdkMediationType)mediation adUnitName:(NSString *)adUnitName adUnitId:(nullable NSString *)adUnitId limitation:(nullable NSString *)limitation;

+ (void)trackAdApterRequestEventAdformat:(OxSdkAdFormat)adFormat mediation:(OxSdkMediationType)mediation adUnitName:(NSString *)adUnitName adUnitId:(nullable NSString *)adUnitId limitation:(nullable NSString *)limitation;

+ (void)trackAdLoadedEventAdformat:(OxAd *)ad;
+ (void)trackAdLoadedFailedEventAdformat:(OxSdkAdFormat)adFormat mediation:(OxSdkMediationType)mediation adUnitName:(NSString *)adUnitName adUnitId:(NSString *)adUnitId  error:(NSString *)error failedDuration:(double)failedDuration;
+ (void)trackAdShowEventAdformat:(OxSdkAdFormat)adFormat  mediation:(OxSdkMediationType)mediation adUnitName:(NSString *)adUnitName showPlacement:(NSString *)showPlacement ad:(OxAd *)ad limitation:(nullable NSString *)limitation;
+ (void)trackAdShowingEventAdformat:(OxAd *)ad;
+ (void)trackAdMemoryLimitedEvent:(OxAd *)ad;
+ (void)trackAdImpressionEventAdformat:(OxAd *)ad;
+ (void)trackAdShowFailedEventAdformat:(OxAd *)ad error:(NSString *)error;
+ (void)trackAdClickEventAdformat:(OxAd *)ad;
+ (void)trackAdCloseEventAdformat:(OxAd *)ad;
+ (void)trackAdGottenCreditAdformat:(OxAd *)ad;

+ (int)getFrequencyOfEvent:(CountedEvents)event;
+ (void)countEventIfShould:(NSString *)name;
+ (NSArray *)eventsShouldBeCounted;

+ (NSInteger)getNetworkState;

@end

NS_ASSUME_NONNULL_END
