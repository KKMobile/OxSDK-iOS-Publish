//
//  OxOpenAdsAdManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/6/18.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import "OxAdManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxOpenAdsAdManager : OxAdManager

- (void)show:(NSString *)adUnitName showPlacement:(NSString *)showPlacement delegate:(id<OxAdActionDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END