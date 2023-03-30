// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import "OMBaseCustomEvent.h"
NS_ASSUME_NONNULL_BEGIN

@protocol OMBannerCustomEvent;

@protocol bannerCustomEventDelegate <OMCustomEventDelegate>

- (void)bannerCustomEventDidClick:(id<OMBannerCustomEvent>)adapter;
- (void)bannerCustomEventWillPresentScreen:(id<OMBannerCustomEvent>)adapter;
- (void)bannerCustomEventDismissScreen:(id<OMBannerCustomEvent>)adapter;
- (void)bannerCustomEventWillLeaveApplication:(id<OMBannerCustomEvent>)adapter;
@end

@protocol OMBannerCustomEvent <OMBaseCustomEvent>
@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
