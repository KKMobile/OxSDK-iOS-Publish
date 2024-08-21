//
//  BaseBannerAdHelper.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/1.
//
#import "OxAdHelper.h"
#import "IBannerAd.h"
#import "BannerAdDelegate.h"
#import "BannerInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface BaseBannerAdHelper : OxAdHelper<IBannerAd,BannerInternalAdDelegate>

@property (nonatomic, weak) id<BannerAdDelegate> mAdDelegate;
@property (nonatomic, assign) bool  mIsReady;
@property (nonatomic, assign) bool  mAutoRefresh;
@property (nonatomic, strong) NSString *loadPlacement;
@property (nonatomic, assign) bool mAdaptive;


+ (BaseBannerAdHelper *)createAdHelpeWithAdUnitId:(NSString *)adUnitId mediation:(Platform)mediation;

@end

NS_ASSUME_NONNULL_END
