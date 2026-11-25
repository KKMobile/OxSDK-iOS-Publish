//
//  OxNativeViewBinder.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/7/24.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class GADMediaView;
@class MANativeAdView;
@class GADNativeAdView;

NS_ASSUME_NONNULL_BEGIN

@interface OxNativeViewBinder : NSObject

@end


@interface OxNativeViewLayoutBinder : OxNativeViewBinder

@property(nonatomic, strong) UIView *mediaView;
@property(nonatomic, strong) UIImageView *icon;
@property(nonatomic, strong) UIImageView *starRating;
@property(nonatomic, strong) UILabel *title;
@property(nonatomic, strong) UILabel *adLabel;
@property(nonatomic, strong) UILabel *advertiser;
@property(nonatomic, strong) UILabel *body;
@property(nonatomic, strong) UIButton *callToAction;

@property(nonatomic, strong) GADMediaView *admobMediaView;

@end

@interface OxNativeViewClassBinder : OxNativeViewBinder

@property(nonatomic, strong) MANativeAdView *mMaxView;
@property(nonatomic, strong) GADNativeAdView *mAdmobView;

@end

NS_ASSUME_NONNULL_END
