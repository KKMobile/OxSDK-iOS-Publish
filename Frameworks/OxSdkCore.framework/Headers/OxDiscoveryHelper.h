//
//  OxDiscoveryHelper.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/10/24.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MAAd;
@class GADAdValue;

@interface OxDiscoveryHelper : NSObject

+ (instancetype)sharedInstance;

- (void)logMaxImpressionRevenue:(NSDictionary *)parmas;
- (void)logAdmobImpressionRevenue:(NSDictionary *)parmas;

@end

NS_ASSUME_NONNULL_END
