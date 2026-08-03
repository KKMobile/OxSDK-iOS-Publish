//
//  AdConfigQuery.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AdConfigQueryBuilder;

@interface AdConfigQuery : NSObject

@property (nonatomic, copy, readonly) NSString *adFormat;
@property (nonatomic, copy, readonly) NSString *unitName;
@property (nonatomic, copy, readonly, nullable) NSString *platform;
@property (nonatomic, copy, readonly, nullable) NSString *idAdType;

+ (instancetype)queryWithBuilder:(void (^)(AdConfigQueryBuilder *builder))block;

@end

@interface AdConfigQueryBuilder : NSObject

- (AdConfigQueryBuilder *)setAdFormat:(NSString *)adFormat;
- (AdConfigQueryBuilder *)setUnitName:(NSString *)unitName;
- (AdConfigQueryBuilder *)setPlatform:(NSString *)platform;
- (AdConfigQueryBuilder *)setIdAdType:(NSString *)idAdType;
- (AdConfigQuery *)build;

@end

NS_ASSUME_NONNULL_END
