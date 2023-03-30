// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import "OMBaseCustomEvent.h"
NS_ASSUME_NONNULL_BEGIN

@protocol OMSplashCustomEvent;

@protocol splashCustomEventDelegate <OMCustomEventDelegate>

- (void)splashCustomEventDidShow:(id<OMSplashCustomEvent>)adapter;
- (void)splashCustomEventDidClick:(id<OMSplashCustomEvent>)adapter;
- (void)splashCustomEventDidClose:(id<OMSplashCustomEvent>)adapter;
- (void)splashCustomEventFailToShow:(id<OMSplashCustomEvent>)adapter error:(NSError*)error;
@end

@protocol OMSplashCustomEvent<OMBaseCustomEvent>
@property(nonatomic, weak, nullable) id<splashCustomEventDelegate> delegate;
- (instancetype)initWithParameter:(NSDictionary *)adParameter adSize:(CGSize)size;
@optional
- (BOOL)isReady;
- (void)showWithWindow:(UIWindow *)window customView:(UIView *)customView;
@end

NS_ASSUME_NONNULL_END
