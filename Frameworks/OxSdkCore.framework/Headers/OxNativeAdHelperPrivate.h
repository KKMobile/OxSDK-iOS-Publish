//
//  OxNativeAdHelperPrivate.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/7/24.
//  Copyright © 2025 耿志向. All rights reserved.
//

#ifndef OxNativeAdHelperPrivate_h
#define OxNativeAdHelperPrivate_h

#import "OxAdHelperPrivate.h"
#import "OxNativeAdHelper.h"
#import "NativeInternalAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class OxNativeViewBinder;

@interface OxNativeAdHelper()

@property (nonatomic, assign) BOOL mIsReady;
@property (nonatomic, strong) OxNativeViewBinder *mViewBinder;

@end

NS_ASSUME_NONNULL_END


#endif /* OxNativeAdHelperPrivate_h */
