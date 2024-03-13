//
//  OxBannerAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import "OxBaseAd.h"
#import "BaseBannerAdHelper.h"
#import "BannerAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxBannerAdHelper : OxBaseAd

@property (nonatomic, weak) id<BannerAdDelegate> mAdDelegate;
@property (nonatomic, strong) NSMutableDictionary<NSNumber *,BaseBannerAdHelper *> *mAdHelpersMap;

- (void)showAd:(nonnull UIView *)adContainerV;
- (void)showAd:(nonnull UIView *)adContainerV placement:(nonnull NSString *)placement;
- (void)hideAd;
- (BOOL)isReady;
- (void)startAutoRefresh;
- (void)stopAutoRefresh;



@end

NS_ASSUME_NONNULL_END
