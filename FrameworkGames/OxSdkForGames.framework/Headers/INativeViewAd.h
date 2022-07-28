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

@protocol INativeViewAd <NSObject, IViewAd>

- (void)setViewBinder:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
