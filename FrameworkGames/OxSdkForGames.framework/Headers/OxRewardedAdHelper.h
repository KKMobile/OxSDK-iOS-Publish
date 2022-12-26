//
//  OxRewardedAdHelper.h
//  OxSDK-Game
//
//  Created by BJMM100001 on 2022/11/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RewardedAdDelegate.h"
#import "OxAdUnitIds.h"
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxRewardedAdHelper : NSObject

@property (nonatomic, weak) id<RewardedAdDelegate> mAddelegate;

- (instancetype)initWithCurrentVC:(UIViewController *)VC adUnitIds:(OxAdUnitIds *)adUnitIds;

- (void)loadAd;

- (void)loadAd:(NSString *)placement;

- (void)loadAdWithPlatform:(Platform)platform;

- (void)loadAdWithPlatform:(Platform)platform placement:(NSString *)placement;

- (void)showAd;

- (void)showAd:(NSString *)placement;

- (void)destoryAd;

- (BOOL)isReady;

- (void) setReloadAfterFailed:(BOOL)reload;

- (void)onClientShowingLimitation:(NSString *)limitation;

- (void)onClientShowingLimitation:(NSString *)placement limitation:(NSString *)limitation;

- (void)setExtraParameters:(NSString *)key value:(NSString *)value;

@end

NS_ASSUME_NONNULL_END
