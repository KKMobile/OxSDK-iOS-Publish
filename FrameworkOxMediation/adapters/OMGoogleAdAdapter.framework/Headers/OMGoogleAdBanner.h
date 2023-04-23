// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <UIKit/UIKit.h>
#import <GoogleMobileAds/GoogleMobileAds.h>
#import <Foundation/Foundation.h>
#import "OMBannerCustomEvent.h"


NS_ASSUME_NONNULL_BEGIN

@interface OMGoogleAdBanner : UIView <OMBannerCustomEvent,GADBannerViewDelegate>

@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
@property (nonatomic, strong) GAMBannerView *admobBannerView;
- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
@end

NS_ASSUME_NONNULL_END
