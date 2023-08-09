//
//  RewardedAdGroupDelegate.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2023/7/10.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import "AdGroupDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class AdReward;

@protocol RewardedAdGroupDelegate <AdGroupDelegate>

- (void)onGroupRewardedVideoStarted:(NSString *)adUnitId;

- (void)onGroupRewardedVideoCompleted:(NSString *)adUnitId;

- (void)onGroupUserRewarded:(NSString *)adUnitId reward:(AdReward *) reward;

@end

NS_ASSUME_NONNULL_END
