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

- (void)setDailyLevel:(int)dailyLevel;

- (void)setDeepUser:(bool)isDeepUser;

- (void)checkUserProperties;

//不再建议使用此方法
- (void)configApplovinKeywords;
- (NSArray<MASegment *> *)configApplovinSegments;

///  设置 channel 和 campaign
- (void)setChannelAndCampaign;

- (void)setPropLtAdValue:(NSString *)propLtv;

/// 输出格式化之后的 mKeywordChannel
- (NSString *)getFormattedChannel;
/// 输出格式化之后的 mKeywordCampaign
- (NSString *)getFormattedCampaign;
@end

NS_ASSUME_NONNULL_END
