//
//  RewardedInternalAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>
#import "AdInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@class AdReward;

@protocol RewardedInternalAdDelegate <NSObject, AdInternalAdDelegate>

- (void)oxRewardedVideoStarted;

- (void)oxRewardedVideoCompleted;

- (void)oxUserRewarded:(AdReward *)reward adParams:(OxAdParams *)adParams;

@end

NS_ASSUME_NONNULL_END
