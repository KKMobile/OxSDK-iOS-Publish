// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMSplashCustomEvent.h"
#import "OMVungleRouter.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMVungleSplash : NSObject<OMSplashCustomEvent,OMVungleAdapterDelegate>

@property (nonatomic, weak) id<splashCustomEventDelegate>delegate;
@property (nonatomic, copy) NSString *pid;

- (instancetype)initWithParameter:(NSDictionary *)adParameter adSize:(CGSize)size;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)showWithWindow:(UIWindow *)window customView:(UIView *)customView;

@end

NS_ASSUME_NONNULL_END
