//
//  OxAdjustEventTracker.h
//  OxAdjustPlugin
//
//  Created by Mavl_2023_100272 on 2024/10/23.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAdjustEventTracker : NSObject

+ (void)trackEvent:(NSString *)eventName adjustParams:(nullable NSDictionary *)adjustParams;

+ (NSString *)getNetwork;
+ (NSString *)getCampaign;
+ (NSString *)getAdID;


@end

NS_ASSUME_NONNULL_END
