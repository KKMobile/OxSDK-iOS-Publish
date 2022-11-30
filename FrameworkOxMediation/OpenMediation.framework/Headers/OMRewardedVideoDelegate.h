// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class OMRewardedVideo;

@protocol OMRewardedVideoDelegate <NSObject>

@optional

- (void)omRewardedVideoDidLoad:(OMRewardedVideo *)rewarded;

- (void)omRewardedVideoFailToLoad:(OMRewardedVideo *)rewarded withError:(NSError *)error;

/// Sent immediately when a rewarded video is opened.
- (void)omRewardedVideoDidOpen:(OMRewardedVideo*)rewardedVideo;

/// Sent immediately when a rewarded video starts to play.
- (void)omRewardedVideoPlayStart:(OMRewardedVideo*)rewardedVideo;

/// Send after a rewarded video has been completed.
- (void)omRewardedVideoPlayEnd:(OMRewardedVideo*)rewardedVideo;

/// Sent after a rewarded video has been clicked.
- (void)omRewardedVideoDidClick:(OMRewardedVideo*)rewardedVideo;

/// Sent after a user has been granted a reward.
- (void)omRewardedVideoDidReceiveReward:(OMRewardedVideo*)rewardedVideo;

/// Sent after a rewarded video has been closed.
- (void)omRewardedVideoDidClose:(OMRewardedVideo*)rewardedVideo;

/// Sent after a rewarded video has failed to play.
- (void)omRewardedVideoDidFailToShow:(OMRewardedVideo*)rewardedVideo withError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
