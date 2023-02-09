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

/**
 * 安装应用的第 n 天，安装当天为 1。
 */
+ (int)getDayCountSinceInstall;

+ (void)onTrackEvent:(nonnull NSString *)name params:(nullable NSDictionary *)params;

+ (NSArray *)getTopValuesConfig;

 /// 打点等级。 OX_CONFIG_ADSDK_LOG_LEVEL
+ (int)getEventLevel;

 /// 获取深度用户阈值。OX_CONFIG_DEPTH_USER_LEVEL
+ (int)getDeepUserLevel;

/// 允许需要设置给 Applovin 的 Keywords。 OX_CONFIG_ADSDK_KEYWORD_TYPE
+ (int)getAllowedKeywordType;

/// ltv medium 阈值。 OX_CONFIG_ADSDK_LTV_MEDIUM
+ (double)getAdLtvMedium;

/// ltv high 阈值。OX_CONFIG_ADSDK_LTV_HIGH
+ (double)getAdLtvHigh;

/// 应用安装后的 n 天内，视为新增用户。OX_CONFIG_ADSDK_DAYS_OF_NEW_USER
+ (int)getDaysOfNewUser;

/// uac campaign 信息。OX_CONFIG_ADSDK_UAC_CAMPAIGN
+ (nullable NSString *)getUacCampaign;

/// 是否达到内存限制
/// - Parameter adFormat: 达到内存限制的广告格式
+ (BOOL)isMemoryLimitReached:(NSString *)adFormat;

+ (NSArray*)getKeywords;

+ (NSString *)getString:(NSString *)key defaultValue:(NSString *)defaultValue;
+ (double)getDouble:(NSString *)key defaultValue:(double)defaultValue;
+ (int)getInt:(NSString *)key defaultValue:(int)defaultValue;
+ (BOOL)getBool:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
