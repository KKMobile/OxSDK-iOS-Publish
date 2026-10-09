//
//  AdConfigSnapshotProvider.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
@class AdConfig;
@class ConfigSegment;
@protocol OxAdConfigParseListener;

NS_ASSUME_NONNULL_BEGIN

@interface AdConfigSnapshotProvider : NSObject
@property (nonatomic, weak, nullable) id<OxAdConfigParseListener> parseListener;
@property (nonatomic, assign) BOOL parseCompleted;
- (void)updateSnapshotWithMergedConfig:(AdConfig *)mergedConfig
                       defaultConfig:(AdConfig *)defaultConfig
                       configVersion:(NSString *)configVersion
                        configSource:(NSString *)configSource
                 defaultConfigVersion:(nullable NSString *)defaultConfigVersion
                  remoteConfigVersion:(nullable NSString *)remoteConfigVersion
                         allSegments:(NSArray<ConfigSegment *> *)allSegments
                     matchedSegment:(nullable ConfigSegment *)matchedSegment;
- (void)setMatchedSegment:(nullable ConfigSegment *)matchedSegment;
- (void)setMergedConfig:(AdConfig *)mergedConfig;
- (AdConfig * _Nullable)adConfig;
- (AdConfig * _Nullable)defaultAdConfig;
- (NSString *)configVersion;
- (NSString *)configSource;
/// 本次合并实际使用的 default 版本
- (NSString *)defaultConfigVersion;
/// 当前可见的远端配置版本
- (NSString *)remoteConfigVersion;
- (NSArray<ConfigSegment *> *)allSegments;
- (ConfigSegment * _Nullable)currentMatchedSegment;
- (void)clear;
@end

NS_ASSUME_NONNULL_END
