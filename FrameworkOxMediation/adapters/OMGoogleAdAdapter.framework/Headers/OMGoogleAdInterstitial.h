// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <GoogleMobileAds/GoogleMobileAds.h>
#import "OMInterstitialCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMGoogleAdInterstitial : NSObject <OMInterstitialCustomEvent,GADFullScreenContentDelegate>

@property (nonatomic, strong) GAMInterstitialAd *admobInterstitial;
@property (nonatomic, copy) NSString *pid;
@property (nonatomic, weak) id<interstitialCustomEventDelegate> delegate;
@property (nonatomic, assign) BOOL ready;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;
@end

NS_ASSUME_NONNULL_END
