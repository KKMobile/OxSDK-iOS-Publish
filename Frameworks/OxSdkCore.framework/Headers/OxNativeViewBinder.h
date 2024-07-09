//
//  OxNativeViewBinder.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/7/9.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>


@class MANativeAdView,GADNativeAdView;

NS_ASSUME_NONNULL_BEGIN

@interface OxNativeViewBinder : NSObject

@property(nonatomic, strong) MANativeAdView *maxNativeBinder;
@property(nonatomic, strong) MANativeAdView *maxBannerNativeBinder;  // Native Banner 加载 专用配置 可以为nil
@property(nonatomic, strong) GADNativeAdView *admobNativeBinder;

+ (OxNativeViewBinder *)createBinder:(MANativeAdView *)maxNativeBinder admobNativeBinder:(GADNativeAdView *)admobNativeBinder;

+ (OxNativeViewBinder *)createBinder:(MANativeAdView *)maxNativeBinder maxBannerNativeBinder:(nullable MANativeAdView *)maxBannerNativeBinder admobNativeBinder:(GADNativeAdView *)admobNativeBinder;

@end

NS_ASSUME_NONNULL_END
