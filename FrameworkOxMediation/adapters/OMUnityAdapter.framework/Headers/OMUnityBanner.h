// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <UIKit/UIKit.h>
#import "OMBannerCustomEvent.h"
#import <UnityAds/UnityAds.h>

NS_ASSUME_NONNULL_BEGIN

@interface OMUnityBanner : UIView<OMBannerCustomEvent,UADSBannerViewDelegate>

@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
@property (nonatomic, assign) BOOL impr;
@property (nonatomic, strong) UADSBannerView *bannerView;

- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
