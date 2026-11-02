//
//  KeywordsAndUserPropertiesManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/7/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MASegment;

@interface KeywordsAndUserPropertiesManager : NSObject

@property (nonatomic, copy) NSString *mKeywordChannel;

@property (nonatomic, copy) NSString *mKeywordCampaign;

+ (nonnull instancetype)shared;

- (void)initialize;

/// 配置解析完成后开始接收 Adjust 归因更新，并在有效归因变更时重评配置分群。
- (void)startAttributionUpdates;

/// 宿主通知归因更新时，主动从 Adjust/插件缓存读取当前 channel 与 campaign。
- (void)refreshAttributionWithInitializationElapsedMillis:(long long)initializationElapsedMillis;

- (void)setDailyLevel:(int)dailyLevel;

- (void)setDeepUser:(bool)isDeepUser;

- (void)checkUserProperties;

//不再建议使用此方法
- (void)configApplovinKeywords;
- (NSArray<MASegment *> *)configApplovinSegments;
- (NSDictionary *)defaultSegmentFromRemoteConfig;

- (void)setPropLtAdValue:(NSString *)propLtv;

/// 输出格式化之后的 mKeywordChannel
- (NSString *)getFormattedChannel;
/// 输出格式化之后的 mKeywordCampaign
- (NSString *)getFormattedCampaign;
@end

NS_ASSUME_NONNULL_END
