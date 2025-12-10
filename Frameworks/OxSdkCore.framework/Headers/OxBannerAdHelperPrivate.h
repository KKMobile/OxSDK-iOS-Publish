//
//  OxBannerAdHelperPrivate.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2025/4/29.
//  Copyright © 2025 耿志向. All rights reserved.
//

#ifndef OxBannerAdHelperPrivate_h
#define OxBannerAdHelperPrivate_h

#import "OxAdHelperPrivate.h"
#import "OxBannerAdHelper.h"
#import "BannerInternalAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxBannerAdHelper()

@property (nonatomic, assign) bool mIsReady;
@property (nonatomic, assign) bool mAutoRefresh;
@property (nonatomic, assign) bool mAdaptive;

@end

NS_ASSUME_NONNULL_END


#endif /* OxBannerAdHelperPrivate_h */
