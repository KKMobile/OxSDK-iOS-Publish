//
//  ConfigMerger.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class AdConfig;
@class ConfigSegment;

NS_ASSUME_NONNULL_BEGIN

@interface ConfigMerger : NSObject

- (AdConfig * _Nullable)mergeConfigsWithSegments:(AdConfig * _Nullable)defaultConfig
                                  localSegments:(NSArray<ConfigSegment *> * _Nullable)localSegments
                                 remoteSegments:(NSArray<ConfigSegment *> * _Nullable)remoteSegments;

@end

NS_ASSUME_NONNULL_END
