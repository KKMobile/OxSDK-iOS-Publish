//
//  KeywordsAndUserPropertiesManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/7/14.
//

#import <Foundation/Foundation.h>
@import Adjust;

NS_ASSUME_NONNULL_BEGIN

@interface KeywordsAndUserPropertiesManager : NSObject

@property (nonatomic, copy) NSString *mKeywordChannel;

@property (nonatomic, copy) NSString *mKeywordCampaign;

+ (nonnull instancetype)shared;

- (void)initialize;

- (void)setDailyLevel:(int)dailyLevel;

- (void)setDeepUser:(bool)isDeepUser;

- (void)checkUserProperties;

- (void)configApplovinKeywords;

- (void)setPropLtAdValue:(NSString *)propLtv;

/// 输出格式化之后的 mKeywordChannel
- (NSString *)getFormattedChannel;
/// 输出格式化之后的 mKeywordCampaign
- (NSString *)getFormattedCampaign;
@end

NS_ASSUME_NONNULL_END