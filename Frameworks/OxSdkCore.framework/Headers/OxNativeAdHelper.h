//
//  OxNativeAdHelper.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/7/24.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import "OxAdHelper.h"
#import "IViewAd.h"
#import "NativeAdDelegate.h"
#import "OxNativeViewBinder.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxNativeAdHelper : OxAdHelper <IViewAd>

@property (nonatomic, weak) id<NativeAdDelegate> mAdDelegate;

/// 绑定 Native 样式
- (void)setViewBinder:(OxNativeViewBinder *)binder;

+ (OxNativeAdHelper *)createAdWithCurrentVC:(UIViewController *)currentVC adUnitID:(NSString *)adUnitID;

@end

NS_ASSUME_NONNULL_END
