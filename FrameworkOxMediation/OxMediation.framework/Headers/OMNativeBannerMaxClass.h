//
//  OMNativeBannerMaxClass.h
//  OxMediation
//
//  Created by 耿志向 on 2023/3/14.
//  Copyright © 2023 AdTiming. All rights reserved.
//
#import <UIKit/UIKit.h>

@interface MANativeAdView : UIView

/**
 * The native ad title label.
 */
@property (nonatomic, weak) IBOutlet UILabel *titleLabel;

/**
 * The native ad advertiser label.
 */
@property (nonatomic, weak) IBOutlet UILabel *advertiserLabel;

/**
 * The native ad body label.
 */
@property (nonatomic, weak) IBOutlet UILabel *bodyLabel;

/**
 * The native ad icon ImageView.
 */
@property (nonatomic, weak) IBOutlet UIImageView *iconImageView;

/**
 * The native ad icon view.
 */
@property (nonatomic, weak) IBOutlet UIView *iconContentView __deprecated_msg("iconContentView is deprecated and will be removed in the future. Use iconImageView instead.");

/**
 * The native ad options view.
 */
@property (nonatomic, weak) IBOutlet UIView *optionsContentView;

/**
 * The native ad media view for holding an arbitrary content view provided by the 3rd-party SDK.
 */
@property (nonatomic, weak) IBOutlet UIView *mediaContentView;

/**
 * The native ad CTA button.
 */
@property (nonatomic, weak, nullable) IBOutlet UIButton *callToActionButton;

@end
