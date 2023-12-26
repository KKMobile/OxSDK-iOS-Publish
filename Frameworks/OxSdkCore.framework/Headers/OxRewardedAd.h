//
//  OxRewardedAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import "OxBaseAd.h"
#import "RewardedAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxRewardedAd : OxBaseAd

@property (nonatomic, weak) id<RewardedAdDelegate> mAdDelegate;

- (void)showAd:(NSString *)placement;
- (void)showAd;
- (BOOL)isReady;

- (void)setReloadAfterFailed:(BOOL)reload;

@end

NS_ASSUME_NONNULL_END
