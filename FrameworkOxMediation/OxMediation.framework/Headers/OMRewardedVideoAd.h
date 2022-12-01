// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import "OMAdBasePrivate.h"
#import "OMAdBase.h"
#import "OMRewardedVideoCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@class OMRewardedVideoAd;

@protocol RewardedVideoDelegate <NSObject>

- (void)rewardedVideoDidLoad:(NSString *)instanceId;
- (void)rewardedVideoDidFailToLoadWithError:(NSError *)error;

- (void)rewardedVideoDidOpen:(OMRewardedVideoAd*)video;

- (void)rewardedVideoDidStart:(OMRewardedVideoAd*)video;

- (void)rewardedVideoDidEnd:(OMRewardedVideoAd*)video;

- (void)rewardedVideoDidClick:(OMRewardedVideoAd*)video;

- (void)rewardedVideoDidReceiveReward:(OMRewardedVideoAd*)video;

- (void)rewardedVideoDidClose:(OMRewardedVideoAd*)video;

- (void)rewardedVideoDidFailToShow:(OMRewardedVideoAd*)video error:(NSError*)error;

@end

@interface OMRewardedVideoAd : OMAdBase <rewardedVideoCustomEventDelegate>

@property (nonatomic, weak)id<RewardedVideoDelegate> delegate;

- (instancetype)initWithPlacementID:(NSString*)placementID;
- (void)show:(UIViewController*)viewController;
@end

NS_ASSUME_NONNULL_END
