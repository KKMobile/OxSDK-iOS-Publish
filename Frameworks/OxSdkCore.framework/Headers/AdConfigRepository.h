//
//  AdConfigRepository.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
@class AdConfig;
@class ConfigSegment;
@class OxAdConfigCache;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdConfigLoadResult : NSObject
@property (nonatomic, strong, nullable) AdConfig *mergedConfig; // 最终生效的配置（已合并）
@property (nonatomic, strong, nullable) AdConfig *defaultConfig;// default 段原始配置
@property (nonatomic, copy) NSString *configVersion; // 版本号
@property (nonatomic, copy) NSString *configSource; // 来源：assets / sp / remote / memory
@property (nonatomic, copy) NSString *defaultConfigVersion; // 本次合并实际使用的 default 版本
@property (nonatomic, copy) NSString *remoteConfigVersion; // 当前可见的远端配置版本
@property (nonatomic, copy) NSArray<ConfigSegment *> *allSegments;  // 全部分群列表
@end

@interface AdConfigRepository : NSObject
- (instancetype)initWithCache:(OxAdConfigCache *)cache;
- (nullable OxAdConfigLoadResult *)load;
- (BOOL)hasRemoteSegments;
- (AdConfig * _Nullable)mergeWithSegment:(AdConfig *)defaultConfig segment:(nullable ConfigSegment *)segment;
- (void)releaseRepository;
/// Remote Config 拉取完成后统一失效缓存，供上层重新按当前审核态/线上态重建
- (void)invalidateAllCaches;
@end

NS_ASSUME_NONNULL_END
