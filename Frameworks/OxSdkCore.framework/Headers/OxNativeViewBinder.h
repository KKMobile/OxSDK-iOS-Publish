//
//  OxNativeViewBinder.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/7/9.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@class MANativeAdView,GADNativeAdView,GADMediaView,GADAdChoicesView;

NS_ASSUME_NONNULL_BEGIN

@interface OxNativeViewBinder : NSObject

/// MAX: UIView  Admob:GADMediaView
@property(nonatomic, strong) UIView *mediaView;
@property(nonatomic, strong) UIView *adChoices;
@property(nonatomic, strong) UIView *starRate;
@property(nonatomic, strong) UIImageView *icon;
@property(nonatomic, strong) UILabel *title;
@property(nonatomic, strong) UILabel *adLabel;
@property(nonatomic, strong) UILabel *advertiser;
@property(nonatomic, strong) UILabel *body;
@property(nonatomic, strong) UILabel *store;
@property(nonatomic, strong) UILabel *price;
@property(nonatomic, strong) UIButton *callToAction;

@property(nonatomic, strong) GADMediaView *admobMediaView;
@property(nonatomic, strong) GADAdChoicesView *admobAdChoices;

@property(nonatomic, strong) MANativeAdView *maxNativeBinder;
@property(nonatomic, strong) MANativeAdView *maxBannerNativeBinder;  // Native Banner 加载 专用配置 可以为nil
@property(nonatomic, strong) GADNativeAdView *admobNativeBinder;

+ (OxNativeViewBinder *)createBinder:(MANativeAdView *)maxNativeBinder admobNativeBinder:(GADNativeAdView *)admobNativeBinder;

+ (OxNativeViewBinder *)createBinder:(MANativeAdView *)maxNativeBinder maxBannerNativeBinder:(nullable MANativeAdView *)maxBannerNativeBinder admobNativeBinder:(GADNativeAdView *)admobNativeBinder;

@end

NS_ASSUME_NONNULL_END
