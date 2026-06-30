//
//  ConfigParser.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class AdConfig;
@class ConfigSegment;

NS_ASSUME_NONNULL_BEGIN

@interface OxConfigParseResult : NSObject
@property (nonatomic, strong, nullable) AdConfig *defaultConfig;
@property (nonatomic, strong, nullable) NSArray<ConfigSegment *> *segments;
@end

@interface ConfigParser : NSObject

+ (nullable OxConfigParseResult *)parseJsonWithSegments:(NSString *)jsonString isSegment:(BOOL)isSegment;
+ (NSInteger)parseRemoteConfigVersion:(NSString *)json;

@end

NS_ASSUME_NONNULL_END
