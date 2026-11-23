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

#import "OxPangleBannerAd.h"
#import "OxPangleInterstitialAd.h"
#import "OxPangleMrecAd.h"
#import "OxPangleNativeAd.h"
#import "OxPangleOpenAdsAd.h"
#import "OxPangleRewardedAd.h"
#import "OxPangleSdkManager.h"
#import "PangleAdUtils.h"
#import "OxCustomPangleAdapter.h"
#import "OxPangleAdapter.h"

FOUNDATION_EXPORT double OxPangleAdapterVersionNumber;
FOUNDATION_EXPORT const unsigned char OxPangleAdapterVersionString[];

