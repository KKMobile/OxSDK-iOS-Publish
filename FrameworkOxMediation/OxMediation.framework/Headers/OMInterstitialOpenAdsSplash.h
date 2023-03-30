//
//  OMInterstitialOpenAdsInterstitial.h
//  OxMediation
//
//  Created by 耿志向 on 2023/3/14.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMSplashCustomEvent.h"
#import "OMInterstitialDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMInterstitialOpenAdsSplash : NSObject <OMSplashCustomEvent>

@property (nonatomic, weak) id<splashCustomEventDelegate>delegate;
@property (nonatomic, copy) NSString *pid;

- (instancetype)initWithParameter:(NSDictionary *)adParameter adSize:(CGSize)size;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)showWithWindow:(UIWindow *)window customView:(UIView *)customView;
@end

NS_ASSUME_NONNULL_END
