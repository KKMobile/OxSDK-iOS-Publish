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

/** 激励广告业务监听器；奖励仅以 onUserRewarded:reward: 为准。 */
@protocol RewardedAdDelegate <NSObject, AdDelegate>

- (void)onRewardedVideoStarted:(NSString*)adUnitId;

- (void)onRewardedVideoCompleted:(NSString*)adUnitId;

/// 网络确认用户获得奖励；在此处理游戏奖励。
- (void)onUserRewarded:(NSString*)adUnitId reward:(AdReward *) reward;

@end

NS_ASSUME_NONNULL_END
