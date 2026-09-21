#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "GADInMobiExtras.h"
#import "GADMAdapterInMobi.h"
#import "GADMAdapterInMobiBannerAd.h"
#import "GADMAdapterInMobiConstants.h"
#import "GADMAdapterInMobiDelegateManager.h"
#import "GADMAdapterInMobiInitializer.h"
#import "GADMAdapterInMobiInterstitialAd.h"
#import "GADMAdapterInMobiRewardedAd.h"
#import "GADMAdapterInMobiUnifiedNativeAd.h"
#import "GADMAdapterInMobiUtils.h"
#import "GADMediationAdapterInMobi.h"
#import "GADMInMobiConsent.h"
#import "InMobiAdapter.h"
#import "NativeAdKeys.h"
#import "OxInmobiAdapter.h"

FOUNDATION_EXPORT double OxInmobiAdapterVersionNumber;
FOUNDATION_EXPORT const unsigned char OxInmobiAdapterVersionString[];

