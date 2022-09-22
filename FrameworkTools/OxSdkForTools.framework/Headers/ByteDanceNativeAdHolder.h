//
//  ByteDanceNativeAdHolder.h
//  NativeInterstitial
//
//  Created by BJMM100001 on 2022/8/22.
//

#import <Foundation/Foundation.h>
@import BUAdSDK;
@import AppLovinSDK;

NS_ASSUME_NONNULL_BEGIN

@interface ByteDanceNativeAdHolder : NSObject

@property (nonatomic, strong, nullable) BUNativeAd *nativeAd;

@property (nonatomic, strong, nullable) id<MAInterstitialAdapterDelegate> interstitialAdDelegate;


+ (nonnull instancetype)sharedInstance;

- (void)destroy;

@end

NS_ASSUME_NONNULL_END
