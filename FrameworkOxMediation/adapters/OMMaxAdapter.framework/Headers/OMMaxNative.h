//
//  OMMaxNative.h
//  OMMaxAdapter
//
//  Created by 耿志向 on 2022/11/14.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMNativeCustomEvent.h"
#import <AppLovinSDK/AppLovinSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface OMMaxNative : NSObject <OMNativeCustomEvent,MANativeAdDelegate>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, weak) id<nativeCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

- (instancetype)initWithParameter:(NSDictionary*)adParameter rootVC:(UIViewController*)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (void)setViewBinder:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
