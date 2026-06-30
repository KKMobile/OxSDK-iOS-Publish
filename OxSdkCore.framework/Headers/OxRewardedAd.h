//
//  OxRewardedAd.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/4/8.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import "OxAd.h"

@class AdReward;

NS_ASSUME_NONNULL_BEGIN

@interface OxRewardedAd : OxAd

- (void)handleAdLoaded;
- (void)handleAdLoadFailed:(NSString *)error;
- (void)handleAdDisplayed;
- (void)handleAdDisplayFailed:(NSString *)error errorCode:(NSInteger)errorCode;
- (void)handleAdClicked;
- (void)handleAdClosed;
- (void)handleUserRewarded:(AdReward *)reward;
- (void)showAdWithDelay:(dispatch_block_t)showBlock;

@end

NS_ASSUME_NONNULL_END
