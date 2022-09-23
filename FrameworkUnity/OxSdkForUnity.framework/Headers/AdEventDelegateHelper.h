//
//  AdEventDelegateHelper.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/9/2.
//

#import <Foundation/Foundation.h>
#import "OxAdjustTokens.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdEventDelegateHelper : NSObject

+ (OxAdjustTokens *)getAdjustTokens;

+ (NSArray *)getTopValuesConfig;

+ (int)getEventLevel;

+ (int)getDeepUserLevel;

+ (int)getAllowedKeywordType;

+ (double)getAdLtvMedium;

+ (double)getAdLtvHigh;

+ (int)getDaysOfNewUser;

+ (int)getDayCountSinceInstall;

+ (nullable NSString *)getUacCampaign;

+ (void)onTrackEvent:(nonnull NSString *)name params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
