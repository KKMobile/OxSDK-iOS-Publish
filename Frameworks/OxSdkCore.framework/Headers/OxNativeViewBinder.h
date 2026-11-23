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

/** Native 视图绑定基类；LayoutBinder 传入素材视图，ClassBinder 传入对应网络的原生广告视图。视图需由宿主保持有效。 */
@interface OxNativeViewBinder : NSObject

@end


/** 将标题、图标、媒体、广告标识、正文与 CTA 等素材绑定到宿主 UIKit 视图。 */
@interface OxNativeViewLayoutBinder : OxNativeViewBinder

/// Default assets for direct networks when the host supplies no layout binder.
+ (instancetype)defaultBinderForBounds:(CGRect)bounds;

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

/** 直接使用 MAX MANativeAdView 或 AdMob GADNativeAdView；不同网络的视图不可混用。 */
@interface OxNativeViewClassBinder : OxNativeViewBinder

@property(nonatomic, strong) MANativeAdView *mMaxView;
@property(nonatomic, strong) GADNativeAdView *mAdmobView;

@end

NS_ASSUME_NONNULL_END
