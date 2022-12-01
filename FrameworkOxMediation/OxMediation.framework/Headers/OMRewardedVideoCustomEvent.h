// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OMCustomEventDelegate.h"
#import "OMBidCustomEvent.h"
NS_ASSUME_NONNULL_BEGIN

@protocol OMRewardedVideoCustomEvent;

@protocol rewardedVideoCustomEventDelegate<OMCustomEventDelegate>

- (void)rewardedVideoCustomEventDidOpen:(id<OMRewardedVideoCustomEvent>)adapter;
- (void)rewardedVideoCustomEventDidFailToShow:(id<OMRewardedVideoCustomEvent>)adapter withError:(NSError*)error;
- (void)rewardedVideoCustomEventVideoStart:(id<OMRewardedVideoCustomEvent>)adapter;
- (void)rewardedVideoCustomEventVideoEnd:(id<OMRewardedVideoCustomEvent>)adapter;
- (void)rewardedVideoCustomEventDidClick:(id<OMRewardedVideoCustomEvent>)adapter;
- (void)rewardedVideoCustomEventDidReceiveReward:(id<OMRewardedVideoCustomEvent>)adapter;
- (void)rewardedVideoCustomEventDidClose:(id<OMRewardedVideoCustomEvent>)adapter;

@end

@protocol OMRewardedVideoCustomEvent<NSObject>
@property(nonatomic, weak, nullable) id<rewardedVideoCustomEventDelegate> delegate;
- (instancetype)initWithParameter:(NSDictionary*)adParameter;
@optional
- (void)setBidDelegate:(id<OMBidCustomEventDelegate>)bidDelegate;
- (void)loadAd;
- (void)loadAdWithBidPayload:(NSString*)bidPayload;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;
- (void)setBidParameters:(id)parameters;
@end

NS_ASSUME_NONNULL_END
