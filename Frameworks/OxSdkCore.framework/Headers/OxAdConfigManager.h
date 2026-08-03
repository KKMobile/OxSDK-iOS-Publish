//
//  OxAdConfigManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class AdConfig;
@class AdUnitBaseConfig;
@class AdUnitConfig;
@class IdConfig;
@class AppUserValueConfig;
@class AdapterConfig;
@class AdNetworkConfig;
@class AdConfigQuery;
@class OxAdConfigCacheInfo;
@class ConfigSegment;
@class UserValueConfig;

NS_ASSUME_NONNULL_BEGIN

@protocol OxAdConfigParseListener <NSObject>
- (void)onConfigParsed;
- (void)onConfigParseFailed:(NSString *)error;
@end

@protocol OxAdConfigChangeListener <NSObject>
- (void)onConfigChanged:(nullable ConfigSegment *)matchedSegment mergedConfig:(AdConfig *)mergedConfig;
@end

@interface OxAdConfigManager : NSObject

+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());
+ (void)initManager;
+ (void)initManagerWithListener:(nullable id<OxAdConfigParseListener>)listener;
+ (BOOL)isInitialized;
+ (void)releaseManager;

@property (nonatomic, weak, nullable) id<OxAdConfigParseListener> configParseListener;

- (void)addConfigChangeListener:(id<OxAdConfigChangeListener>)listener;
- (void)removeConfigChangeListener:(id<OxAdConfigChangeListener>)listener;
- (void)removeAllConfigChangeListeners;

- (AdConfig * _Nullable)adConfig;
- (BOOL)isValid;
- (BOOL)isConfigParseCompleted;
- (ConfigSegment * _Nullable)currentMatchedSegment;

- (void)refreshConfig;
- (void)updateConfig:(NSString *)newJson;
- (OxAdConfigCacheInfo *)cacheInfo;

/// Firebase Remote Config 拉取完成后，重新加载一次广告配置（当前未接入自动调用，保留供未来按需开启）
- (void)onRemoteConfigFetchCompleted;

- (NSArray<AdUnitConfig *> *)adUnitsForType:(NSString *)adType;
- (AdUnitBaseConfig * _Nullable)adUnitBaseConfigForFormat:(NSString *)adFormat unitName:(NSString *)unitName;
- (NSArray<IdConfig *> *)adUnitIdsForType:(NSString *)adType unitName:(NSString *)unitName;
- (NSArray<IdConfig *> *)idsByPlatformForFormat:(NSString *)adFormat unitName:(NSString *)unitName platform:(NSString *)platform;
- (IdConfig * _Nullable)idConfigByAdType:(NSArray<IdConfig *> *)idConfigs adType:(NSString *)adType;
- (IdConfig * _Nullable)dynamicIdFromIds:(NSArray<IdConfig *> *)ids;
- (NSArray<NSString *> * _Nullable)dynamicIdsFromIds:(NSArray<IdConfig *> *)ids;
- (IdConfig * _Nullable)idConfigById:(NSString *)adId;
- (NSString *)disabledCacheIdsString;
- (NSArray<IdConfig *> *)idsByAdConfigQueryForFormat:(NSString *)adFormat
                                            unitName:(NSString *)unitName
                                           idAdType:(NSString *)idAdType
                                            platform:(NSString *)platform;
- (BOOL)isAdUnitValidForType:(NSString *)adType unitName:(NSString *)unitName;
- (NSArray<NSString *> *)supportedAdTypes;
- (NSArray<IdConfig *> *)queryIdConfigs:(AdConfigQuery *)query;
- (NSArray<AdUnitBaseConfig *> *)allAdUnitBaseConfigsWithInterval;
- (NSDictionary<NSString *, UserValueConfig *> *)userValues;
- (BOOL)isFloorID:(NSInteger)widget adFormat:(NSString *)adFormat adUnitName:(NSString *)adUnitName;

- (NSInteger)geoConsent;
- (NSString *)packageName;
- (NSString *)configVersion;
- (NSString *)configSource;
/// 安全获取当前生效的 default 配置版本
- (NSString *)defaultConfigVersion;
/// 安全获取当前可见的远端配置版本
- (NSString *)remoteConfigVersion;
- (NSString *)mediation;
- (void)setMediation:(NSString *)mediation;
- (NSInteger)daysOfNewUser;
- (NSInteger)depthUserLevel;
- (NSInteger)eventLevel;
- (AppUserValueConfig *)userValueConfig;
- (AdapterConfig *)adapterConfig;
- (AdNetworkConfig *)adMobConfig;
- (AdNetworkConfig *)maxConfig;
- (NSString *)adMobAppId;
- (NSString *)maxAppId;

@end

NS_ASSUME_NONNULL_END
