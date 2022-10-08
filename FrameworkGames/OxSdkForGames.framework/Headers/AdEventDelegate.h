//
//  AdEventDelegate.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/6/24.
//

#ifndef AdEventDelegate_h
#define AdEventDelegate_h
#import "OxAdjustTokens.h"

@protocol AdEventDelegate<NSObject>

- (OxAdjustTokens *)getAdjustTokens;

- (NSArray *)getTopValuesConfig;

@optional

- (int)getEventLevel;

- (int)getDeepUserLevel;

- (int)getAllowedKeywordType;

- (double)getAdLtvMedium;

- (double)getAdLtvHigh;

/**
* 应用安装后的 n 天内，视为新增用户。
*/
- (int)getDaysOfNewUser;

/**
* 安装应用的第 n 天，安装当天为 1。
*/
- (int)getDayCountSinceInstall;

- (nullable NSString *)getUacCampaign;

/**
* Sdk 内部进行事件上报时，将事件信息暴露给客户端，客户端可根据需求进行利用。
* @param name 事件名称。
* @param params 相关参数。
*/
- (void) onTrackEvent:(nonnull NSString *)name params:(nullable nullable NSDictionary *)params;
         
@end

#endif /* AdEventDelegate_h */
