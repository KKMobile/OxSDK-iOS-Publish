// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMIronSourceRouter.h"
#import "OMInterstitialCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMIronSourceInterstitial : NSObject<OMInterstitialCustomEvent,ISInterstitialDelegate>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, weak) id<interstitialCustomEventDelegate> delegate;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;


@end

NS_ASSUME_NONNULL_END
