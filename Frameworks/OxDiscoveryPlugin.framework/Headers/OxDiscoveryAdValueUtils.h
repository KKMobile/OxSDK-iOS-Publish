//
//  OxAdValueUtils.h
//  OxDiscoveryPlugin
//
//  Created by Mavl_2023_100272 on 2023/6/6.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MAAd;
@class GADAdValue;

NS_ASSUME_NONNULL_BEGIN

@interface OxDiscoveryAdValueUtils : NSObject


+ (void)logMaxImpressionRevenue:(NSDictionary *)parmas;
+ (void)logAdmobImpressionRevenue:(NSDictionary *)parmas;

@end

NS_ASSUME_NONNULL_END
