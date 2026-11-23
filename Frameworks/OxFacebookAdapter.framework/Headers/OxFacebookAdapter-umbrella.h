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

#import "FacebookAnBidSession.h"
#import "OxFacebookBannerAd.h"
#import "OxFacebookInterstitialAd.h"
#import "OxFacebookMrecAd.h"
#import "OxFacebookNativeAd.h"
#import "OxFacebookRewardedAd.h"
#import "OxFacebookSdkManager.h"
#import "OxFacebookAd.h"
#import "OxFacebookAdapter.h"

FOUNDATION_EXPORT double OxFacebookAdapterVersionNumber;
FOUNDATION_EXPORT const unsigned char OxFacebookAdapterVersionString[];

