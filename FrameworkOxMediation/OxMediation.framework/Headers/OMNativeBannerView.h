//
//  OMNativeBannerView.h
//  OxMediation
//
//  Created by 耿志向 on 2023/3/14.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <UIKit/UIKit.h>
@class OMNativeAd;
#import "OMNativeAdView.h"
#import "OMNativeMediaView.h"

NS_ASSUME_NONNULL_BEGIN

/// A customized UIView to represent a ad (native ad).
@interface OMNativeBannerView : UIView

@property (nonatomic, strong) OMNativeAd *nativeAd;
@property (nonatomic, strong) OMNativeAdView *nativeAdView;

/// This is a method to initialize an OMNativeView.
/// Parameter frame: the OMNativeView frame.
- (instancetype)initWithFrame:(CGRect)frame;

- (void)setClickableViews:(NSArray<UIView *> *)clickableViews; //for Facebook TencentAd

@end

NS_ASSUME_NONNULL_END
