//
//  BaseMrecAdHelper.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/1.
//

#import "OxAdHelper.h"
#import "IBannerAd.h"
#import "MrecAdDelegate.h"
#import "MrecInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface BaseMrecAdHelper : OxAdHelper<IBannerAd,MrecInternalAdDelegate>

@property (nonatomic, weak) id<MrecAdDelegate> mAdDelegate;
@property (nonatomic, assign) bool  mIsReady;
@property (nonatomic, assign) bool  mAutoRefresh;
@property (nonatomic, strong) NSString *loadPlacement;

+ (BaseMrecAdHelper *)createAdHelpeWithAdUnitId:(NSString *)adUnitId mediationType:(OxSdkMediationType)mediationType;

@end

NS_ASSUME_NONNULL_END
