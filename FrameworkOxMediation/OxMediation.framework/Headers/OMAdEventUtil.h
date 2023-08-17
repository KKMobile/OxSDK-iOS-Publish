//
//  OMAdEventUtil.h
//  OxMediation
//
//  Created by 耿志向 on 2023/4/11.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMAdBasePrivate.h"

// NetWorkState
typedef NS_ENUM(NSInteger, OMNetWorkState) {
    OM_UNAVAILABLE = 0,
    OM_AVAILABLE = 1
};

// NetWorkType
typedef NS_ENUM(NSInteger, OMNetWorkType) {
    OM_UNWORK = 0,
    OM_DATA_2G,
    OM_DATA_3G,
    OM_DATA_4G,
    OM_DATA_5G,
    OM_WIFI,
    OM_DATA
};


NS_ASSUME_NONNULL_BEGIN

@interface OMAdEventUtil : NSObject

+ (void)trackAdRequestEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId error:(nullable NSError *)error;
+ (void)trackS2sBidEventAdFormat:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId;
+ (void)trackWFRequestEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId;
+ (void)trackWFRequestSuccessEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId bids:(NSDictionary *)bids;
+ (void)trackWFRequestFailedEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId error:(NSError *)error ;
+ (void)trackWFValidEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId haveC2s:(BOOL)haveC2s;
+ (void)trackC2sBidEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId;
+ (void)trackC2sBidCompletedEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId;
+ (void)trackWFBlockEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId reason:(NSString *)reason;
+ (void)trackLoadInstancesEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId netWorkName:(NSString *)netWorkName revenue:(NSString *)revenue gid:(NSString *)gid;
+ (void)trackAdLoadedEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId loadDuration:(long)loadDuration requestDetailsId:(NSString *)requestDetailsId;
+ (void)trackAdFailedEvent:(OxMediationAdFormat)adFormat adunitId:(NSString *)adunitId error:(NSError *)error requestDetailsId:(NSString *)requestDetailsId;

@end

NS_ASSUME_NONNULL_END
