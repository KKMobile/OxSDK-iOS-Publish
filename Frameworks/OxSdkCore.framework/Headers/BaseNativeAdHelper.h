//
//  BaseNativeAdHelper.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/7.
//

#import "OxAdHelper.h"
#import "INativeViewAd.h"
#import "NativeInternalAdDelegate.h"
#import "NativeAdGroupDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface BaseNativeAdHelper : OxAdHelper<INativeViewAd,NativeInternalAdDelegate>

@property (nonatomic, weak) id<NativeAdGroupDelegate> mAdDelegate;
@property (nonatomic, assign) bool  mIsReady;
@property (nonatomic, strong) NSString *loadPlacement;

+ (BaseNativeAdHelper *)createAdHelpeWithAdUnitId:(NSString *)adUnitId mediationType:(OxSdkMediationType)mediationType;

@end

NS_ASSUME_NONNULL_END
