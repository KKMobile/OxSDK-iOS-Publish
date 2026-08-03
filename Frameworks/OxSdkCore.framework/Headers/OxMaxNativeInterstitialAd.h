//
//  OxMaxNativeInterstitialAd.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/8/8.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OxInterstitialAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxMaxNativeInterstitialAd : OxInterstitialAd

- (instancetype)initWithPlacementParams:(OxPlacementParams *)placementParams
                               idConfig:(IdConfig *)idConfig
                         viewController:(UIViewController *)viewController
                      internalListener:(id<AdInternalListener>)listener;

@end

NS_ASSUME_NONNULL_END
