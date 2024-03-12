//
//  BaseRewaedAdHelper.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/1.
//

#import "BaseFullscreenAdHelper.h"
#import "RewardedInternalAdDelegate.h"
#import "RewardedAdGroupDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface BaseRewaedAdHelper : BaseFullscreenAdHelper <IFullScreenAd,RewardedInternalAdDelegate>

@property (nonatomic, weak) id<RewardedAdGroupDelegate> mAdDelegate;
@property (nonatomic, assign) bool mUserRewarded;
@property (nonatomic, assign) double mOnRewardedVideoStartedTime;

+ (BaseRewaedAdHelper *)createAdHelpeWithAdUnitId:(NSString *)adUnitId mediationType:(OxSdkMediationType)mediationType;

@end

NS_ASSUME_NONNULL_END
