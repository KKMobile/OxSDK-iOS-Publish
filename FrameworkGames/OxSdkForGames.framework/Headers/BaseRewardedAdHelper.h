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

@interface BaseRewardedAdHelper : OxAdHelper<IFullScreenAd>

@property (nonatomic, weak) id<RewardedAdDelegate> mAddelegate;
@property (nonatomic, weak) id<RewardedInternalAdDelegate> mInternalAddelegate;

@property (nonatomic, assign) bool mUserRewarded;

@property (nonatomic, assign) double mOnRewardedVideoStartedTime;

@property (nonatomic, assign) NSInteger retryAttempt;
@property (nonatomic, assign) BOOL mReload;
@property (nonatomic, assign) BOOL mIsReloadingInLoadFailed;
@property (nonatomic, assign) BOOL mIsReloadingInDisplayFailed;

- (void)createAd:(Platform)platform;
- (void)resetLoadStatus:(NSString *)placement;
- (void)resetLoadStatus:(NSString *)placement requestSource:(nullable NSString *)requestSource;


@end

NS_ASSUME_NONNULL_END
