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
/** 最近一次解析失败详情，格式：JSON文件.[字段]原因；无失败时为 nil */
+ (nullable NSString *)lastParseFailError;

@end

NS_ASSUME_NONNULL_END
