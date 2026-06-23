//
//  OxRemoteConfigHelper.h
//  OxSDK-Game
//
//  Created by BJMM100001 on 2023/2/14.
//

#import <Foundation/Foundation.h>
#import "OxAdjustTokens.h"

NS_ASSUME_NONNULL_BEGIN

/// Dynamic Explore 远程配置解析结果
@interface OxDynamicExploreConfig : NSObject

@property (nonatomic, copy) NSString *exploreIds;
@property (nonatomic, assign) int nUp;
@property (nonatomic, assign) int nDown;
@property (nonatomic, assign) int dSeconds;

- (instancetype)initWithExploreIds:(NSString *)exploreIds
                               nUp:(int)nUp
                             nDown:(int)nDown
                          dSeconds:(int)dSeconds;

@end

@interface OxRemoteConfigHelper : NSObject

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

/// 获取被禁用的插屏广告位
+ (NSString *)getDisableInterIds;

/// 获取被禁用的RV广告位
+ (NSString *)getDisableRVIds;

// 并行数
+ (NSInteger)getParallelTasks:(NSInteger)defaultValue;

// Max native id 当 Banner id
+ (NSString *)getNative2BannerId;

// Max native id 当插屏 ids
+ (NSString *)getNative2InterIds;

// 添加额外的插屏ID
+ (NSString *)getAddInterIds;

// 添加额外的RV ID
+ (NSString *)getAddRVIds;

// 是否关闭 【加载失败｜展示失败 重试】 功能，格式：reward,interstitial,open,native， -1 为关闭，其他数据不关闭，比如: -1,0,0,0  这里只关闭 reward ，其他的不关闭
+ (NSString *)getDisableReload;

// 广告关闭之后，是否立刻请求，格式：reward,interstitial， -1 为关闭，其他数据不关闭，比如: -1,0  这里只关闭 reward ，其他的不关闭
+ (NSString *)getDisableCloseReload;

// 重试时间最大方次数，重试时间一般都是2的n次方，这里是动态获取n
+ (int)getReloadTime;

// 广告缓存最大数量设置，等于 0 不生效
+ (int)getCacheAdSize;

// 获取远端配置的超时时间
+ (int)getTimeOutSeconds;

/**
 * 配置BidExplored功能的插屏ID和跳高百分比，先ID，后百分比，使用英文逗号链接,例如：6edc59f27f01055f,0.2
 */
+ (NSString *)getExploredConfig:(NSString *)placementName;

/**
 * 配置 Explored IDs
 */
+ (NSString *)getDynamicExploreIDs:(NSString *)placementName;

/**
 * 统一解析 Dynamic Explore 配置：
 * adsdk_dynamic_explore_[placement] = exploreId,nUp,nDown,dSeconds
 */
+ (OxDynamicExploreConfig *)getDynamicExploreConfig:(NSString *)placementName;

/**
 * 探索模式：向上动态跳价失败后重试次数
 */
+ (int)getExploredDynamicNUp:(NSString *)placementName;

/**
 * 探索模式：向下动态跳价失败后重试次数
 */
+ (int)getExploredDynamicNDown:(NSString *)placementName;

/**
 * 探索模式：允许继续上探的最高成功跳价最大返回时间（秒）
 */
+ (int)getExploredDynamicDSeconds:(NSString *)placementName;

/**
 * 广告缓存模式，High：保留高价，New：保留最新
 */
+ (NSString *)getIsExploredCacheModel;

/**
 * 是否删除RV缓存的无底价广告,0:false,1:true
 */
+ (int)getIsExploredIsDeleteCache;


+ (int)getGdprStyle;


/*
 * 配置是否在目标区域开启 MAX GDPR  目前只对 Admob 聚合生效
 * -1: 没有配置，0.默认配置，1. 目标区域配置。
 */
+ (int)getGeoConsent;

/// 是否达到内存限制
/// - Parameter adFormat: 达到内存限制的广告格式
+ (BOOL)isMemoryLimitReached:(NSString *)adFormat;

+ (NSArray*)getKeywords;

+ (NSString *)getString:(NSString *)key defaultValue:(NSString *)defaultValue;
+ (double)getDouble:(NSString *)key defaultValue:(double)defaultValue;
+ (int)getInt:(NSString *)key defaultValue:(int)defaultValue;
+ (BOOL)getBool:(NSString *)key defaultValue:(bool)defaultValue;

@end

NS_ASSUME_NONNULL_END
