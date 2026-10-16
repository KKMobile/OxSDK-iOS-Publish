//
//  OxNativeInterstitialViewController.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/8/9.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol OxNativeInterstitialViewControllerDelegate <NSObject>

- (void)onNativeAdClosed;
- (void)onNativeAdDisplayFailed:(NSString *)error;
- (void)onNativeAdDisplay;

@end

@interface OxNativeInterstitialViewController : UIViewController

@property (nonatomic, weak) id<OxNativeInterstitialViewControllerDelegate> delegate;

- (void)setNativeAdView:(UIView *)nativeAdView;

@end

NS_ASSUME_NONNULL_END
