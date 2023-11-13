//
//  OxBannerAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import "OxBaseAd.h"
#import "BaseMrecAdHelper.h"
#import "MrecAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxMrecAdHelper : OxBaseAd

@property (nonatomic, weak) id<MrecAdDelegate> mAdDelegate;
@property (nonatomic, strong) NSMutableDictionary<NSNumber *,BaseMrecAdHelper *> *mAdHelpersMap;

- (void)showAd:(nonnull UIView *)adContainerV;
- (void)showAd:(nonnull UIView *)adContainerV placement:(nonnull NSString *)placement;
- (void)hideAd;
- (BOOL)isReady;
- (void)startAutoRefresh;
- (void)stopAutoRefresh;


@end

NS_ASSUME_NONNULL_END
