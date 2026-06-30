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
- (NSArray<ConfigSegment *> *)allSegments;
- (NSArray<ConfigSegment *> *)localSegments;
- (NSArray<ConfigSegment *> *)remoteSegments;
- (BOOL)saveRemoteConfig:(NSString *)json remoteVersion:(NSInteger)remoteVersion;
- (void)clearSPCache;
- (nullable AdConfig *)refreshConfig:(NSString *)assetsFileName;
- (void)updateConfig:(NSString *)newJson;
- (OxAdConfigCacheInfo *)cacheInfo;
- (void)releaseCache;

@end

NS_ASSUME_NONNULL_END
