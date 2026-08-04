//
//  AdEventUtil.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/14.
//

#import <Foundation/Foundation.h>
#import "OxAdSdkManager.h"
#import "OxAdShowLimitation.h"
#import "OxAdHelperPrivate.h"

NS_ASSUME_NONNULL_BEGIN
@interface AdEventUtil : NSObject

+ (void)logMaxImpressionRevenue:(MAAd *)ad placement:(NSString *)placement tag:(long long)tag requestTag:(long long)requestTag;
+ (void)logAdmobImpressionRevenue:(NSString *)adUnitId adFormat:(NSString *)adFormat adNetwork:(NSString *)adNetwork advalue:(GADAdValue *)advalue placement:(NSString *)placement tag:(long long)tag requestTag:(long long)requestTag;

// uservalue
+ (void)logAdUserValueError:(NSString *)error;
+ (void)logAdUserValueError:(NSString *)error type:(AdUserValueErrorType)type;
+ (void)logAdUserValue:(NSString *)adUnitId count:(NSInteger)count value:(float)value isNewPeriod:(BOOL)isNewPeriod;
+ (void)logAdUserValueSegment:(NSString *)adUnitId value:(float)value factor:(float)factor segmentValue:(NSString *)segmentValue;
+ (void)logAdUserValueNoSegment:(NSString *)adUnitId value:(float)value factor:(float)factor;
+ (void)logAdSegment:(NSDictionary *)segmentMap;


+ (void)trackAdEventByKey:(nonnull NSString *)key paramDic:(nullable NSDictionary *)params;

/// 客户端打点
+ (void)trackClientEvent:(NSString *)eventName params:(nullable NSDictionary *)params;
+ (void)trackInitSdkEvent;
+ (void)trackFirebaseConfigChangeLogWithExploredConfig:(nullable NSString *)exploredConfig
                                                addIds:(nullable NSString *)addIds
                                         native2InterIds:(nullable NSString *)native2InterIds
                                              disableIds:(nullable NSString *)disableIds
                                                 error:(nullable NSString *)error;
+ (void)trackGetInstallDaysErrorLog:(nullable NSString *)error;


+ (void)trackAdRequestEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag;
+ (void)trackAdRequestEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag loadState:(NSString *)loadState isReload:(BOOL)isReload;
+ (void)trackAdAdapterRequestEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestNumber:(NSInteger)requestNumber requestTag:(long long)requestTag floorPrice:(NSString *)floorPrice jumpHeightPer:(float)jumpHeightPer;


+ (void)trackAdLoadedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement loadedDuration:(double)loadedDuration  requestTag:(long long)requestTag ad:(nullable id)ad;
+ (void)trackAdAdapterLoadedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement loadedDuration:(double)loadedDuration  requestTag:(long long)requestTag ad:(nullable id)ad;

+ (void)trackAdLoadFailedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement error:(NSString *)error failedDuration:(double)failedDuration requestTag:(long long)requestTag;
+ (void)trackAdAdapterLoadFailedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement error:(NSString *)error failedDuration:(double)failedDuration requestTag:(long long)requestTag;

+ (void)trackAdShowEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement limitation:(NSString *)limitation adStatus:(NSString *)adStatus showFailedDuration:(double)showFailedDuration isReady:(BOOL)isReady requestTag:(long long)requestTag;

+ (void)trackAdShowingEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement networkNamee:(nullable NSString *) networkName creativeId:(nullable NSString *)creativeId requestTag:(long long)requestTag;

+ (void)trackAdMemoryLimitedEvent:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag;

+ (void)trackAdImpressionEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag ad:(nullable id)ad;
+ (void)trackAdAdapterImpressionEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag adTag:(long long)adTag ad:(nullable id)ad;

+ (void)trackAdShowFailedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag ad:(nullable id)ad  error:(NSString *)error failedDuration:(double)failedDuration;
+ (void)trackAdAdapterShowFailedEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag adTag:(long long)adTag ad:(nullable id)ad  error:(NSString *)error failedDuration:(double)failedDuration;

+ (void)trackAdClickEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag ad:(nullable id)ad;
+ (void)trackAdAdapterClickEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag adTag:(long long)adTag ad:(nullable id)ad;
+ (void)trackAdCloseEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag ad:(nullable id)ad showingDuration:(double)showingDuration;
+ (void)trackAdapterCloseEventAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag adTag:(long long)adTag ad:(nullable id)ad showingDuration:(double)showingDuration;

+ (void)trackAdGottenCreditAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag ad:(nullable id)ad;
+ (void)trackAdAdapterGottenCreditAdformat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag adTag:(long long)adTag ad:(nullable id)ad;


+ (void)trackListenerInterruptEvent:(NSString *)eventName adFormat:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag error:(NSString *)error;

+ (void)trackDeleteExpireAdEvent:(NSString *)adFormat adUnitId:(NSString *)adUnitId placement:(NSString *)placement requestTag:(long long)requestTag deleteSize:(NSInteger)deleteSize cacheSize:(NSInteger)cacheSize;
+ (void)trackReplaceAdEventAdformat:(NSString *)adFormat oldAdUnitId:(NSString *)oldAdUnitId newAdUnitId:(NSString *)newAdUnitId oldValue:(double)oldValue newValue:(long long)newValue tag:(long long)tag cacheModel:(NSString *)cacheModel cacheAdSize:(NSInteger)cacheAdSize;


+ (int)getFrequencyOfEvent:(CountedEvents)event;
+ (void)countEventIfShould:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
