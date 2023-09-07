//
//  OxNativeAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "BaseNativeAdHelper.h"
#import "NativeAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxNativeAd : NSObject

@property (nonatomic, weak)id<NativeAdDelegate> mAdDelegate;
@property (nonatomic, strong) NSString *adUnitName;

- (instancetype)initWithAdUnitName:(NSString *)adUnitName;
- (instancetype)initWithAdUnitName:(NSString *)adUnitName viewController:(UIViewController *)viewController;

/// 绑定 Native 样式
/// - Parameter view: max 平台须继承 MANativeAdView  admob 平台须继承 GADNativeAdView
- (void)setMaxViewBinder:(UIView *)view;
- (void)setAdmobViewBinder:(UIView *)view;

- (void)loadAd;
- (void)loadAdWithPlacement:(NSString *)placement;
- (void)showAd:(nonnull UIView *)adContainerV;
- (void)showAd:(nonnull UIView *)adContainerV placement:(nonnull NSString *)placement;
- (void)hideAd;
- (BOOL)isReady;

- (void)destoryAd;


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
