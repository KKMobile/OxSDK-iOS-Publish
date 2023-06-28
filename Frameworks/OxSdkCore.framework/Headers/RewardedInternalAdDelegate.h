//
//  RewardedInternalAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>
#import "AdInternalAdDelegate.h"
#import "AdReward.h"
NS_ASSUME_NONNULL_BEGIN

@protocol RewardedInternalAdDelegate <NSObject, AdInternalAdDelegate>

- (void)onRewardedVideoStarted;

- (void)onRewardedVideoCompleted;

- (void)onUserRewarded:(AdReward *)reward adunitId:(nonnull NSString*)adunitId placement:(nullable NSString*)placement  networkName:(nullable NSString*)networkName waterfallName:(nullable NSString*)waterfallName networkResponses:(NSInteger)networkResponses creativeId:(nullable NSString*)creativeId revenue:(double)revenue;

@end

NS_ASSUME_NONNULL_END
