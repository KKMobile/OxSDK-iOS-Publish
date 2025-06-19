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

+ (OxRewardedAdHelper *)createAdWithCurrentVC:(UIViewController *)currentVC adUnitID:(NSString *)adUnitID;


@end

NS_ASSUME_NONNULL_END
