// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import "OMAdBase.h"
#import "OMAdBasePrivate.h"
#import "OMBannerCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@class OMBannerAd;

@protocol bannerDelegate<NSObject>
- (void)bannerDidLoad:(OMBannerAd *)bannerAd;
- (void)bannerDidFailToLoad:(OMBannerAd *)bannerAd error:(NSError *)error;
- (void)bannerWillExposure:(OMBannerAd *)bannerAd;
- (void)bannerDidClick:(OMBannerAd *)bannerAd;
- (void)bannerWillPresentScreen:(OMBannerAd *)bannerAd;
- (void)bannerDidDissmissScreen:(OMBannerAd *)bannerAd;
- (void)bannerWillLeaveApplication:(OMBannerAd *)bannerAd;
@end

@interface OMBannerAd : OMAdBase<bannerCustomEventDelegate>

@property (nonatomic, weak)id<bannerDelegate> delegate;
@property (nonatomic, assign) BOOL impr;

- (UIView *)bannerView;

@end

NS_ASSUME_NONNULL_END
