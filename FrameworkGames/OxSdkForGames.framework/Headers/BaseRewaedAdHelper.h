//
//  BaseRewaedAdHelper.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/1.
//

#import "BaseFullscreenAdHelper.h"
#import "RewardedAdDelegate.h"
#import "RewardedInternalAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface BaseRewaedAdHelper : BaseFullscreenAdHelper <IFullScreenAd,RewardedInternalAdDelegate>

@property (nonatomic, weak) id<RewardedAdDelegate> mAdDelegate;
@property (nonatomic, assign) bool mUserRewarded;
@property (nonatomic, assign) double mOnRewardedVideoStartedTime;

+ (BaseRewaedAdHelper *)createAdHelpeWithAdUnitId:(NSString *)adUnitId mediation:(Platform)mediation;

@end

NS_ASSUME_NONNULL_END
