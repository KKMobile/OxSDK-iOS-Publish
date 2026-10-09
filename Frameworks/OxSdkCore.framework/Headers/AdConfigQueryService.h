//
//  AdConfigQueryService.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
@class AdConfigSnapshotProvider;
@class AdUnitConfig;
@class AdUnitBaseConfig;
@class IdConfig;
@class AdConfigQuery;
@class UserValueConfig;

NS_ASSUME_NONNULL_BEGIN

/**
 * 广告配置查询服务
 *
 * 基于 AdConfigSnapshotProvider 中的运行时快照（只读），提供广告位、广告 ID 等配置的查询能力。
 * 内部维护 idConfigCache / adUnitsCache 查询缓存；配置刷新或分群切换后需调用 clearCaches 再 preload。
 *
 * 典型调用方：OxAdConfigManager → AdLoadManager / OxAdManager
 */
@interface AdConfigQueryService : NSObject

/** 注入快照提供者，初始化查询缓存字典 */
- (instancetype)initWithSnapshotProvider:(AdConfigSnapshotProvider *)snapshotProvider;

/** 按广告类型（interstitial/banner 等）获取该类型下全部广告位列表 */
- (NSArray<AdUnitConfig *> *)adUnitsForType:(NSString *)adType;

/** 按广告格式 + 广告位名称获取单元基础配置（如 interstitial + Test1） */
- (AdUnitBaseConfig * _Nullable)adUnitBaseConfigForFormat:(NSString *)adFormat unitName:(NSString *)unitName;

/** 获取指定广告位下的全部 ID 配置（不按平台过滤） */
- (NSArray<IdConfig *> *)adUnitIdsForType:(NSString *)adType unitName:(NSString *)unitName;

/** 按聚合平台（max/admob）筛选 ID，并按 weight 降序排序 */
- (NSArray<IdConfig *> *)idsByPlatformForFormat:(NSString *)adFormat unitName:(NSString *)unitName platform:(NSString *)platform;

/** 根据 AdConfigQuery 组合条件查询 ID 列表（支持 platform、idAdType 等过滤） */
- (NSArray<IdConfig *> *)queryIdConfigs:(AdConfigQuery *)query;

/** 按广告格式、广告位和 ID 广告类型查询，并按 weight 降序排列。 */
- (NSArray<IdConfig *> *)idsByAdConfigQueryForFormat:(NSString *)adFormat
                                            unitName:(NSString *)unitName
                                           idAdType:(NSString *)idAdType;

/** 在 ID 配置数组中按 adType 查找第一个匹配项 */
- (IdConfig * _Nullable)idConfigByAdType:(NSArray<IdConfig *> *)idConfigs adType:(NSString *)adType;

/** 汇总所有已缓存 ID 中配置了用户价值（userValue）的项，key 为 adId */
- (NSDictionary<NSString *, UserValueConfig *> *)userValues;

/** 按广告 ID（adId）反查 IdConfig，优先命中 idConfigCache */
- (IdConfig * _Nullable)idConfigById:(NSString *)adId;

/** 判断给定 weight 是否为该广告位的底价 ID（即该单元下最大 weight） */
- (BOOL)isFloorID:(NSInteger)widget adFormat:(NSString *)adFormat adUnitName:(NSString *)adUnitName;

/** 从 ID 列表中提取 dynamic > 0 的动态底价广告 ID 字符串数组 */
- (NSArray<NSString *> * _Nullable)dynamicIdsFromIds:(NSArray<IdConfig *> *)ids;

/** 收集全配置中 disabledCache 为 YES 的 adId，以逗号拼接返回 */
- (NSString *)disabledCacheIdsString;

/** 收集配置了全局展示间隔（interval）的所有广告单元基础配置 */
- (NSArray<AdUnitBaseConfig *> *)allAdUnitBaseConfigsWithInterval;

/** 根据当前快照推断支持的广告类型列表（banner/native/mrec/interstitial/rewarded/openAds） */
- (NSArray<NSString *> *)supportedAdTypes;

/** 后台异步预热：遍历全部 ID 写入 idConfigCache，加速后续 idConfigById 查询 */
- (void)preloadCachesAsync;

/** 清空 ID 与广告位查询缓存（配置更新后调用） */
- (void)clearCaches;

/** 释放服务资源，等同 clearCaches */
- (void)releaseService;

@end

NS_ASSUME_NONNULL_END
