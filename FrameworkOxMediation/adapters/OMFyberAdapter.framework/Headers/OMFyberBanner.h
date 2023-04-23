// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <UIKit/UIKit.h>
#import <Fyber_Marketplace_SDK/IASDKCore-Bridging-Header.h>
#import "OMBannerCustomEvent.h"
NS_ASSUME_NONNULL_BEGIN

@interface OMFyberBanner : UIView <OMBannerCustomEvent>

@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
