//
//  OxDiscovery.h
//  OxDiscoveryPlugin
//
//  Created by Mavl_2023_100272 on 2024/10/24.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OxDiscoveryPlugin/OxDiscoveryDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxDiscovery : NSObject

+ (instancetype)sharedInstance;

- (void)setDiscoveryDelegate:(id<OxDiscoveryDelegate>)delegate;
- (void)logMaxImpressionRevenue:(NSDictionary *)params;
- (void)logAdmobImpressionRevenue:(NSDictionary *)params;
- (void)logImpressionRevenue:(NSDictionary *)params;

#pragma mark - 内部调用
- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;
- (void)onDailyLevelChanged:(NSInteger)level;
- (double)getRcDouble:(NSString *)key defaultValue:(double)defaultValue;

@end

NS_ASSUME_NONNULL_END
