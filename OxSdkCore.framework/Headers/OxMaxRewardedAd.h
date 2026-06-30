//
//  OxMaxRewardedAd.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/8/9.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OxRewardedAd.h"

@class OxPlacementParams, IdConfig;
@protocol AdInternalListener;

NS_ASSUME_NONNULL_BEGIN

@interface OxMaxRewardedAd : OxRewardedAd

@property (nonatomic, assign) BOOL mUserRewarded;

- (instancetype)initWithPlacementParams:(OxPlacementParams *)placementParams
                               idConfig:(IdConfig *)idConfig
                         viewController:(nullable UIViewController *)viewController
                      internalListener:(nullable id<AdInternalListener>)listener;

@end

NS_ASSUME_NONNULL_END
