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

@class OxRewardedAd;

@interface OxRewardedAdHelper : OxAdHelper<IFullScreenAd>

@property (nonatomic, weak) id<RewardedAdDelegate> mAddelegate;
@property (nonatomic, weak) id<RewardedInternalAdDelegate> mInternalAddelegate;

// 缓存
@property (nonatomic, strong) NSMutableArray<OxRewardedAd *> *cacheAds;
// 判断是否请求中又来请求
@property (nonatomic, assign) BOOL isLoading;
@property(nonatomic, assign) LoadStatus loadStatus;

@property (nonatomic, assign) bool mUserRewarded;

@property (nonatomic, assign) double mOnRewardedVideoStartedTime;

@property (nonatomic, assign) NSInteger retryAttempt;
@property (nonatomic, assign) BOOL mReload;
@property (nonatomic, assign) BOOL mIsReloadingInLoadFailed;
@property (nonatomic, assign) BOOL mIsReloadingInDisplayFailed;

- (void)createAd;


@end

NS_ASSUME_NONNULL_END
