//
//  ApplovinNativeAdHolder.h
//  NativeInterstitial
//
//  Created by BJMM100001 on 2022/8/19.
//

#import <Foundation/Foundation.h>
@import AppLovinSDK;

NS_ASSUME_NONNULL_BEGIN

@interface ApplovinNativeAdHolder : NSObject

@property (nonatomic, strong, nullable) MANativeAdView *nativeAdView;

@property (nonatomic, strong, nullable) id<MAInterstitialAdapterDelegate> interstitialAdDelegate;


+ (nonnull instancetype)sharedInstance;

- (void)destroy;

@end

NS_ASSUME_NONNULL_END
