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

+ (nonnull instancetype)shared;

- (void)initialize;

- (void)setChannelAndCampaign:(ADJAttribution *)attribution;

- (void)setTopAdValue:(nullable NSString*)topAdValue;

- (void)setDeepUser:(bool)isDeepUser;

- (void)checkUserProperties;

@end

NS_ASSUME_NONNULL_END
