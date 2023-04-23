// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <BUAdSDK/BUAdSDK.h>
#import <PAGAdSDK/PAGAdSDK.h>
#import <BUAdSDK/BUSplashAdView.h>
#import "OMSplashCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMPangleSplash : NSObject<OMSplashCustomEvent,BUSplashAdDelegate,PAGLAppOpenAdDelegate>

@property (nonatomic, weak) id <splashCustomEventDelegate>delegate;
@property (nonatomic, copy) NSString *pid;

@property (nonatomic, strong) BUSplashAdView *buSplashAd;
@property (nonatomic, assign) CGRect AdFrame;
@property (nonatomic, assign) BOOL isSplashAdReady;

// 海外
@property (nonatomic, strong) PAGLAppOpenAd *splashAd;
@property (nonatomic, assign) BOOL isSplashReady;

- (instancetype)initWithParameter:(NSDictionary *)adParameter adSize:(CGSize)size;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)showWithWindow:(UIWindow *)window customView:(UIView *)customView;

@end

NS_ASSUME_NONNULL_END
