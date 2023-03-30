// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OMInterstitialDelegate.h"
#import "OMInterstitialAd.h"
#import "OMAdHelperCustomEvent.h"


NS_ASSUME_NONNULL_BEGIN

@interface OMInterstitial : NSObject <InterstitialDelegate,OMAdHelperCustomEvent>

@property (nonatomic, weak) id<OMInterstitialDelegate> delegate;
@property (nonatomic, strong) OMInterstitialAd *interstitialAd;

- (instancetype)initWithPlacementId:(NSString *)placementId;

- (void)loadAd;

- (BOOL)isReady;

- (void)showWithViewController:(UIViewController *)viewController;


@end

NS_ASSUME_NONNULL_END
