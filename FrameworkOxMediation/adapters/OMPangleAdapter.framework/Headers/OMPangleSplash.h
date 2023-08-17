// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <PAGAdSDK/PAGAdSDK.h>
#import "OMSplashCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMPangleSplash : NSObject<OMSplashCustomEvent,PAGLAppOpenAdDelegate>

@property (nonatomic, weak) id <splashCustomEventDelegate>delegate;
@property (nonatomic, copy) NSString *pid;

// 海外
@property (nonatomic, strong) PAGLAppOpenAd *splashAd;
@property (nonatomic, assign) BOOL isSplashReady;

- (instancetype)initWithParameter:(NSDictionary *)adParameter adSize:(CGSize)size;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)showWithWindow:(UIWindow *)window customView:(UIView *)customView;

@end

NS_ASSUME_NONNULL_END
