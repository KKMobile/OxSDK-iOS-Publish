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


+ (void)logMaxImpressionRevenue:(MAAd *)ad placement:(NSString *)placement coreLevel:(NSInteger)coreLevel;
+ (void)logAdmobImpressionRevenue:(NSString *)adUnitId adFormat:(NSString *)adFormat adNetwork:(NSString *)adNetwork advalue:(GADAdValue *)advalue placement:(NSString *)placement coreLevel:(NSInteger)coreLevel;

@end

NS_ASSUME_NONNULL_END
