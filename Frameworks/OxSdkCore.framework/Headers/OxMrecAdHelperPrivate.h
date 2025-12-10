//
//  OxMrecAdHelperPrivate.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2025/4/29.
//  Copyright © 2025 耿志向. All rights reserved.
//

#ifndef OxMrecAdHelperPrivate_h
#define OxMrecAdHelperPrivate_h

#import "OxAdHelperPrivate.h"
#import "OxMrecAdHelper.h"
#import "MrecInternalAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxMrecAdHelper()

@property (nonatomic, assign) bool  mIsReady;
@property (nonatomic, assign) bool  mAutoRefresh;

@end

NS_ASSUME_NONNULL_END

#endif /* OxMrecAdHelperPrivate_h */
