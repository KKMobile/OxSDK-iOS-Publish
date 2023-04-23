// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3


#import <Foundation/Foundation.h>
#import <InMobiSDK/InMobiSDK.h>
#import "OMRewardedVideoCustomEvent.h"
#import "OMBidCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMInMobiRewardedVideo : NSObject<OMRewardedVideoCustomEvent,IMInterstitialDelegate>
@property (nonatomic, copy) NSString *pid;
@property (nonatomic, strong) IMInterstitial *rewardedVideo;
@property (nonatomic, weak) id<rewardedVideoCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
