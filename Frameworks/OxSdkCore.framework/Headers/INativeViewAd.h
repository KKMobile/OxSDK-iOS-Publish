//
//  INativeViewAd.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>
#import <AppLovinSDK/AppLovinSDK.h>
#import "IViewAd.h"
NS_ASSUME_NONNULL_BEGIN

@class OxNativeViewBinder;

@protocol INativeViewAd <NSObject, IViewAd>

- (void)setViewBinder:(UIView *)view;
- (void)showAd:(nonnull UIView *)adContainerV viewBinder:(OxNativeViewBinder *)viewBinder placement:(nonnull NSString *)placement;

@end

NS_ASSUME_NONNULL_END
