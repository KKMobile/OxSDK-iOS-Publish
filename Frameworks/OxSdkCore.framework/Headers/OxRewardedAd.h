//
//  OxRewardedAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RewardedAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxRewardedAd : NSObject

@property (nonatomic, weak) id<RewardedAdDelegate> mAdDelegate;
@property (nonatomic, strong) NSString *adUnitName;

- (instancetype)initWithAdUnitName:(NSString *)adUnitName;
- (instancetype)initWithAdUnitName:(NSString *)adUnitName viewController:(UIViewController *)viewController;

- (void)loadAd;
- (void)loadAdWithPlacement:(NSString *)placement;
- (void)showAd:(NSString *)placement;
- (void)showAd;
- (void)destoryAd;
- (BOOL)isReady;

- (void)setReloadAfterFailed:(BOOL)reload;

/// 设置ExtraParameters
/// - Parameters:
- (void)setExtraParameters:(NSString *)key value:(NSString *)value;

/// 得到展示广告的机会，但因客户端限制（如时间限制）而不去展示时，客户端可以调用此方法上报打点。
/// - Parameters:
///   - limitation: 限制本次广告的原因
- (void)onClientShowingLimitation:(NSString *)limitation;

/// 得到展示广告的机会，但因客户端限制（如时间限制）而不去展示时，客户端可以调用此方法上报打点。
/// - Parameters:
///   - placement: 场景名称
///   - limitation: 限制本次广告的原因
- (void)onClientShowingLimitation:(NSString *)placement limitation:(NSString *)limitation;

@end

NS_ASSUME_NONNULL_END
