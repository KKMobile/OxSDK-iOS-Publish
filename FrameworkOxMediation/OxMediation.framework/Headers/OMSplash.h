// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "OMSplashDelegate.h"
#import "OMSplashAd.h"
#import "OMAdHelperCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMSplash : NSObject <splashDelegate,OMAdHelperCustomEvent>

@property (nonatomic, weak)id<OMSplashDelegate> delegate;
@property (nonatomic, strong) OMSplashAd *splashAd;


- (instancetype)initWithPlacementId:(NSString *)placementId adSize:(CGSize)size;

- (void)loadAd;

- (BOOL)isReady;

- (void)showWithWindow:(UIWindow *)window customView:(nullable UIView *)customView;

@end

NS_ASSUME_NONNULL_END
