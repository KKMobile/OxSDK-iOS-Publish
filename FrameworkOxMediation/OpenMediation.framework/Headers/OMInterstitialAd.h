// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import "OMAdBasePrivate.h"
#import "OMAdBase.h"
#import "OMInterstitialCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@class OMInterstitialAd;

@protocol InterstitialDelegate<NSObject>

@optional
- (void)interstitialDidLoad:(NSString *)instanceId;
- (void)interstitialDidFailToLoadWithError:(NSError *)error;

/// Sent immediately before the impression of an OMInterstitialAdobject will be logged.
- (void)interstitialDidOpen:(OMInterstitialAd*)interstitial;

- (void)interstitialDidShow:(OMInterstitialAd*)interstitial;

/// Sent after an ad has been clicked by the person.
- (void)interstitialDidClick:(OMInterstitialAd*)interstitial;

/// Sent after an OMInterstitialAdobject has been dismissed from the screen, returning control to your application.
- (void)interstitialDidClose:(OMInterstitialAd*)interstitial;

- (void)interstitialDidFailToShow:(OMInterstitialAd*)interstitial error:(NSError*)error;

@end

@interface OMInterstitialAd : OMAdBase<interstitialCustomEventDelegate>

/// the delegate
@property (nonatomic, weak)id<InterstitialDelegate> delegate;

- (instancetype)initWithPlacementID:(NSString *)placementID;

- (void)showWithRootViewController:(UIViewController *)rootViewController scene:(NSString*)sceneName;


@end

NS_ASSUME_NONNULL_END
