//
//  OxAdConfigCache.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class AdConfig;
@class ConfigSegment;
@class ConfigMerger;
@class OxConfigParseResult;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdConfigCacheInfo : NSObject
@property (nonatomic, assign) BOOL memoryCacheExists;
@property (nonatomic, assign) BOOL spCacheExists;
@property (nonatomic, assign) NSInteger spCacheVersion;
@property (nonatomic, assign) BOOL isValid;
@end

@interface OxAdConfigCache : NSObject

- (instancetype)init;

- (nullable AdConfig *)loadConfigWithThreeLevelCache;
- (nullable AdConfig *)loadConfigWithThreeLevelCache:(NSString *)assetsFileName;
- (nullable AdConfig *)defaultConfig;
- (ConfigMerger *)configMerger;
- (NSString *)resolvedTopLevelConfigVersion;
- (NSString *)resolvedConfigSource;
/// 当前运行态用于合并的 default 版本：正常态优先远程，否则本地；审核态固定取本地审核配置版本。
- (NSString *)resolvedDefaultConfigVersion;
/// 当前可见的远端配置版本；无远程配置或审核态时返回空串。
- (NSString *)resolvedRemoteConfigVersion;
- (NSArray<ConfigSegment *> *)allSegments;
- (NSArray<ConfigSegment *> *)localSegments;
- (NSArray<ConfigSegment *> *)remoteSegments;
- (BOOL)saveRemoteConfig:(NSString *)json remoteVersion:(NSInteger)remoteVersion;
- (void)clearSPCache;
- (nullable AdConfig *)refreshConfig:(NSString *)assetsFileName;
- (void)updateConfig:(NSString *)newJson;
- (OxAdConfigCacheInfo *)cacheInfo;
- (void)releaseCache;
/// Remote Config 拉取完成后统一失效，下次重新按当前审核态/线上态重建。
- (void)invalidateAllCaches;

@end

NS_ASSUME_NONNULL_END
