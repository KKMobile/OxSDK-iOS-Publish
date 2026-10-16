//
//  OxAdCachedList.h
//

#import <Foundation/Foundation.h>
@class OxAd;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdCachedList : NSObject

- (instancetype)initWithPlacement:(NSString *)adPlacement;

/// 插入一条广告
- (void)put:(OxAd * _Nullable)ad;

/// 当前广告数量
- (NSInteger)size;

/// 获取一条 ecpm 最高的广告（移除缓存）
- (OxAd * _Nullable)get;

/// 获取多条 ecpm 最高的广告
- (NSArray<OxAd *> *)get:(NSInteger)count;

/// 获取所有缓存广告（只返回 isReady = YES 的）
- (NSArray<OxAd *> *)getAll;

@end

NS_ASSUME_NONNULL_END
