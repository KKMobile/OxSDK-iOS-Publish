//
//  UrlParamsBean.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 用于存储 Adjust 链接解析结果的 Bean
@interface UrlParamsBean : NSObject

@property (nonatomic, copy, nullable) NSString *campaign;
@property (nonatomic, copy, nullable) NSString *channel;
@property (nonatomic, copy, nullable) NSString *bannerDays;
@property (nonatomic, copy, nullable) NSString *bannerLevel;
@property (nonatomic, copy, nullable) NSString *interDays;
@property (nonatomic, copy, nullable) NSString *interLevel;

+ (instancetype)fromMap:(nullable NSDictionary<NSString *, NSString *> *)map;

@end

NS_ASSUME_NONNULL_END
