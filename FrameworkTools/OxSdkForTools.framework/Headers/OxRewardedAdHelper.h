//
//  OxRewardedAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import "OxAdHelper.h"
#import "IFullScreenAd.h"
#import "RewardedAdDelegate.h"
#import "RewardedInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxRewardedAdHelper : OxAdHelper<IFullScreenAd>

@property (nonatomic, weak) id<RewardedAdDelegate> mAddelegate;
@property (nonatomic, weak) id<RewardedInternalAdDelegate> mInternalAddelegate;

@property (nonatomic, assign) bool mUserRewarded;

@property (nonatomic, assign) double mOnRewardedVideoStartedTime;

@property (nonatomic, strong) NSString *loadPlacement;

@property (nonatomic, assign) NSInteger retryAttempt;
@property (nonatomic, assign) BOOL mReload;

- (void)createAd;

@end

NS_ASSUME_NONNULL_END
