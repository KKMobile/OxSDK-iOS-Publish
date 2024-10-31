//
//  OxDiscoveryDelegate.h
//  OxDiscoveryPlugin
//
//  Created by Mavl_2023_100272 on 2023/6/6.
//  Copyright © 2023 耿志向. All rights reserved.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol OxDiscoveryDelegate <NSObject>

- (void)trackEvent:(NSInteger)eventType eventName:(NSString *)eventName params:(nullable NSDictionary *)params;
- (void)onDailyLevelChanged:(NSInteger)level;
- (double)getRcDouble:(NSString *)key defaultValue:(double)defaultValue;

@end

NS_ASSUME_NONNULL_END
