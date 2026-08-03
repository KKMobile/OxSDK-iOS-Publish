//
//  UrlParamsManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class UrlParamsBean;

NS_ASSUME_NONNULL_BEGIN

/// URL 参数管理类：设置 URL 并自动解析，获取解析后的 Bean 对象
@interface UrlParamsManager : NSObject

+ (instancetype)sharedInstance;

- (void)setUrl:(nullable NSString *)url;
- (nullable NSString *)url;
- (UrlParamsBean *)bean;

/// @return YES 表示因 deeplink 限制不可加载广告
- (BOOL)canNotLoadAd:(NSString *)adFormat;

@end

NS_ASSUME_NONNULL_END
