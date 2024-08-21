//
//  BaseInterstitialAdHelper.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/5/31.
//

#import "BaseFullscreenAdHelper.h"
#import "InterstitialAdDelegate.h"
#import "InterstitialInternalAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface BaseInterstitialAdHelper : BaseFullscreenAdHelper <IFullScreenAd,InterstitialInternalAdDelegate>


@property (nonatomic, weak) id<InterstitialAdDelegate> mAdDelegate;

+ (BaseInterstitialAdHelper *)createAdHelpeWithAdUnitId:(NSString *)adUnitId mediation:(Platform)mediation;

@end

NS_ASSUME_NONNULL_END
