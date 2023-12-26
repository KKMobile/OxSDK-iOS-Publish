//
//  OxNativeAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import "OxBaseAd.h"
#import "NativeAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxNativeAd : OxBaseAd

@property (nonatomic, weak)id<NativeAdDelegate> mAdDelegate;

/// 绑定 Native 样式
/// - Parameter view: max 平台须继承 MANativeAdView  admob 平台须继承 GADNativeAdView
- (void)setMaxViewBinder:(UIView *)view;
- (void)setAdmobViewBinder:(UIView *)view;
- (void)showAd:(nonnull UIView *)adContainerV;
- (void)showAd:(nonnull UIView *)adContainerV placement:(nonnull NSString *)placement;
- (void)hideAd;
- (BOOL)isReady;

@end

NS_ASSUME_NONNULL_END
