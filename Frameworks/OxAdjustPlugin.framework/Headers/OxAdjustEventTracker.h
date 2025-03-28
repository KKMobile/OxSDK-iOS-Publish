//
//  OxAdjustEventTracker.h
//  OxAdjustEventTracker
//
//  Created by Mavl_2023_100272 on 2023/6/12.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

#define OxAdjustPlugin_SDK_VERSION    @"1.0.6-202503281600"


NS_ASSUME_NONNULL_BEGIN

@interface OxAdjustEventTracker : NSObject

+ (void)trackEvent:(NSString *)eventName adjustParams:(nullable NSDictionary *)adjustParams;

+ (NSString *)getNetwork;
+ (NSString *)getCampaign;
+ (NSString *)getAdID;

@end

NS_ASSUME_NONNULL_END
