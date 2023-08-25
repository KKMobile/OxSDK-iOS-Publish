//
//  OxInterstitialAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <UIKit/UIKit.h>
#import "OxBaseAd.h"
#import "InterstitialAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxInterstitialAd : OxBaseAd

@property (nonatomic, weak) id<InterstitialAdDelegate> mAdDelegate;

- (void)showAd:(NSString *)placement;
- (void)showAd;
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
