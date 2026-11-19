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

#import "OxDiscovery.h"
#import "OxDiscoveryAdValueUtils.h"
#import "OxDiscoveryConstants.h"
#import "OxDiscoveryDelegate.h"
#import "OxDiscoveryPlugin.h"
#import "OxDiscoveryPrefMamager.h"

FOUNDATION_EXPORT double OxDiscoveryPluginVersionNumber;
FOUNDATION_EXPORT const unsigned char OxDiscoveryPluginVersionString[];

