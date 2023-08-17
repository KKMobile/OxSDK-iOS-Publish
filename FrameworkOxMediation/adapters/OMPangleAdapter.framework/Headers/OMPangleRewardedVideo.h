// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <PAGAdSDK/PAGAdSDK.h>
#import "OMRewardedVideoCustomEvent.h"
#import "OMBidCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMPangleRewardedVideo : NSObject<OMRewardedVideoCustomEvent,PAGRewardedAdDelegate>
@property (nonatomic, copy) NSString *pid;
@property (nonatomic, assign) BOOL adReadyFlag;
@property (nonatomic, weak) id<rewardedVideoCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

// 海外
@property (nonatomic, strong) PAGRewardedAd *pagRewardedVideoAd;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
