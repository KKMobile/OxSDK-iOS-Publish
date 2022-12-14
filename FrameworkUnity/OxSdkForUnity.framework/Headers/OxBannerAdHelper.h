//
//  OxBannerAdHelper.h
//  OxSDK-Game
//
//  Created by BJMM100001 on 2022/11/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BannerAdDelegate.h"
#import "OxAdUnitIds.h"
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxBannerAdHelper : NSObject

@property (nonatomic, weak) id<BannerAdDelegate> mAdDelegate;

- (instancetype)initWithCurrentVC:(UIViewController *)VC adUnitIds:(OxAdUnitIds *)adUnitIds;

- (void)loadAd;

- (void)loadAd:(NSString *)placement;

- (void)loadAdWithPlatform:(Platform)platform;

- (void)loadAdWithPlatform:(Platform)platform placement:(NSString *)placement;

- (void)startAutoRefresh;

- (void)stopAutoRefresh;

- (void)hideAd;

- (void)showAd:(nonnull UIView *)adContainerV;

- (void)showAd:(nonnull UIView *)adContainerV placement:(nonnull NSString *)placement;

- (void)destoryAd;

- (BOOL)isReady;

- (void)onClientShowingLimitation:(NSString *)limitation;

- (void)onClientShowingLimitation:(NSString *)placement limitation:(NSString *)limitation;

- (void)setExtraParameters:(NSString *)key value:(NSString *)value;

@end

NS_ASSUME_NONNULL_END
