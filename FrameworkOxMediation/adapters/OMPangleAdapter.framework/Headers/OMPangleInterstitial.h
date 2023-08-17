// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <PAGAdSDK/PAGAdSDK.h>
#import "OMInterstitialCustomEvent.h"
#import "OMBidCustomEvent.h"
NS_ASSUME_NONNULL_BEGIN


@interface OMPangleInterstitial : NSObject<OMInterstitialCustomEvent,PAGLInterstitialAdDelegate>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, assign) BOOL adReadyFlag;
@property (nonatomic, strong) PAGLInterstitialAd *pagInterstitialAd;
@property (nonatomic, weak) id<interstitialCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
