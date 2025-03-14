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

- (void)logMaxImpressionRevenue:(nonnull MAAd *)ad placement:(nullable NSString *)placement coreLevel:(NSInteger)coreLevel;
- (void)logAdmobImpressionRevenue:(nullable NSString *)adUnitId adFormat:(nullable NSString *)adFormat adNetwork:(nullable NSString *)adNetwork advalue:(nonnull GADAdValue *)advalue placement:(nullable NSString *)placement coreLevel:(NSInteger)coreLevel;

@end

NS_ASSUME_NONNULL_END
