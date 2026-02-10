//
//  OxRemoteConfigKeys.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/9/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * tRoas 阈值。
 */
extern NSString* const OX_CONFIG_TOP10;
extern NSString* const OX_CONFIG_TOP20;
extern NSString* const OX_CONFIG_TOP30;
extern NSString* const OX_CONFIG_TOP40;
extern NSString* const OX_CONFIG_TOP50;
extern NSString* const OX_CONFIG_TOP60;

/**
 * 广告打点等级。
 */
extern NSString* const OX_CONFIG_ADSDK_LOG_LEVEL;

/**
 * 应用当前采用的广告 Mediation。
 */
extern NSString* const OX_CONFIG_MEDIATION_PLATFORM;

/**
 * 深度用户等级配置。
 */
extern NSString* const OX_CONFIG_DEPTH_USER_LEVEL;

/**
 * Applovin Keyword Type。
 */
extern NSString* const OX_CONFIG_ADSDK_KEYWORD_TYPE;

/**
 * Ltv medium 阈值。
 */
extern NSString* const OX_CONFIG_ADSDK_LTV_MEDIUM;

/**
 * Ltv high 阈值。
 */
extern NSString* const OX_CONFIG_ADSDK_LTV_HIGH;

/**
 * 应用安装后的 n 天内，视为新增用户。
 */
extern NSString* const OX_CONFIG_ADSDK_DAYS_OF_NEW_USER;

/**
 * uac campaign 信息。
 */
extern NSString* const OX_CONFIG_ADSDK_UAC_CAMPAIGN;

/**
 * 默认的 campaign
 */
extern NSString* const OX_CONFIG_VALUE_DEFAULT_CAMPAIGN;

/**
 * 传给广告平台的关键字。
 */
extern NSString* const OX_CONFIG_ADSDK_KEYWORDS;

/**
 * 被禁用插屏广告位ID。
 */
extern NSString* const OX_CONFIG_AD_DISABLE_INTER_IDS;

/**
 * 被禁用激励视频广告位ID。
 */
extern NSString* const OX_CONFIG_AD_DISABLE_RV_IDS;

/**
 * 并行数
 */
extern NSString* const OX_CONFIG_OXSDK_PARALLEL;

/**
 * Max native id 当 Banner id
 */
extern NSString* const OX_CONFIG_ADSDK_NATIVE_BANNER_ID;

/**
 * Max native id 当插屏 ids
 */
extern NSString* const OX_CONFIG_ADSDK_NATIVE_INTER_IDS;

/**
 * 动态添加插屏广告位ID。
 */
extern NSString* const OX_CONFIG_ADSDK_ADD_INTER_IDS;

/**
 * 动态添加激励视频广告位ID。
 */
extern NSString* const OX_CONFIG_ADSDK_ADD_RV_IDS;

/**
 * 是否关闭 【加载失败｜展示失败 重试】 功能，格式：reward,interstitial,open,native， -1 为关闭。
 */
extern NSString* const OX_CONFIG_ADSDK_DISABLE_RELOAD;

/**
 * 广告关闭之后，是否立刻请求，格式：reward,interstitial， -1 为关闭。
 */
extern NSString* const OX_CONFIG_ADSDK_DISABLE_AD_CLOSE_RELOAD;

/**
 * 重试时间最大方次数，重试时间一般都是2的n次方，这里是动态获取n。
 */
extern NSString* const OX_CONFIG_ADSDK_RELOAD_TIME;

/**
 * 广告缓存最大数量设置，等于 0 不生效。
 */
extern NSString* const OX_CONFIG_ADSDK_CACHE_AD_SIZE;

/**
 *  超时时间
 */
extern NSString* const OX_CONFIG_ADSDK_TIME_OUT_SECONDS;

/**
 * 配置BidExplored功能的RV ID和跳高百分比，先ID，后百分比，使用英文逗号链接,例如：6edc59f27f01055f,0.2
 */
extern NSString* const OX_CONFIG_ADSDK_MAX_DYNAMIC_ID;

/**
 * 广告缓存模式，High：保留高价，New：保留最新。
 */
extern NSString* const OX_CONFIG_ADSDK_MAX_DYNAMIC_CACHE_MODEL;

/**
  * 是否打开 RV 销毁展示无底价广告
  */
extern NSString* const OX_CONFIG_ADSDK_MAX_DYNAMIC_IS_DELETE_CACHE;


/**
 * 应用剩余可用内存低于该阈值时，不再展示 Banner 广告。
 */
extern NSString* const OX_CONFIG_ADSDK_MEMORY_LIMIT_BANNER;

/**
 * 应用剩余可用内存低于该阈值时，不再展示 MRec 广告。
 */
extern NSString* const OX_CONFIG_ADSDK_MEMORY_LIMIT_MREC;

/**
 * 应用剩余可用内存低于该阈值时，不再展示 Interstitial 广告。
 */
extern NSString* const OX_CONFIG_ADSDK_MEMORY_LIMIT_INTER;

/**
 * 应用剩余可用内存低于该阈值时，不再展示 Rewarded 广告。
 */
extern NSString* const OX_CONFIG_ADSDK_MEMORY_LIMIT_REWARDED;

/**
 * GDPR 工具。
 * 0 for Max, 1 for Google Ump
 */
extern NSString* const OX_CONFIG_GDPR_STYLE;
extern NSString* const OX_CONFIG_ADSDK_GEO_CONSENT;

NS_ASSUME_NONNULL_END
