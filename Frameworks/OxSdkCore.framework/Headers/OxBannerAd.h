//
//  OxBannerAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import "OxBaseAd.h"
#import "BannerAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxBannerAd : OxBaseAd

@property (nonatomic, weak) id<BannerAdDelegate> mAdDelegate;

- (void)showAd:(nonnull UIView *)adContainerV;
- (void)showAd:(nonnull UIView *)adContainerV placement:(nonnull NSString *)placement;
- (void)hideAd;
- (BOOL)isReady;
- (void)startAutoRefresh;
- (void)stopAutoRefresh;

- (void)destoryAd;


@end

NS_ASSUME_NONNULL_END
