//
//  RewardedAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>
#import "AdDelegate.h"
#import "AdReward.h"
NS_ASSUME_NONNULL_BEGIN

@protocol RewardedAdDelegate <NSObject, AdDelegate>

- (void)onRewardedVideoStarted;

- (void)onRewardedVideoCompleted;

- (void)onUserRewarded:(AdReward *) reward;

@end

NS_ASSUME_NONNULL_END
