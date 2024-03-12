//
//  BaseInterstitialAdHelper.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/5/31.
//

#import "BaseFullscreenAdHelper.h"
#import "InterstitialAdGroupDelegate.h"
#import "InterstitialInternalAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface BaseInterstitialAdHelper : BaseFullscreenAdHelper <IFullScreenAd,InterstitialInternalAdDelegate>


@property (nonatomic, weak) id<InterstitialAdGroupDelegate> mAdDelegate;

+ (BaseInterstitialAdHelper *)createAdHelpeWithAdUnitId:(NSString *)adUnitId mediationType:(OxSdkMediationType)mediationType;

@end

NS_ASSUME_NONNULL_END
