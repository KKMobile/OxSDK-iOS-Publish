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

- (void)onRewardedVideoStartedWithAdUnitName:(NSString *)adUnitName;

- (void)onRewardedVideoCompletedWithAdUnitName:(NSString *)adUnitName;

- (void)onUserRewardedWithAdUnitName:(NSString *)adUnitName reward:(AdReward *) reward;

@end

NS_ASSUME_NONNULL_END
