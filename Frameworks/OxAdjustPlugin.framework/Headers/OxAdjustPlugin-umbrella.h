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

#import "OxAdjustEventTracker.h"
#import "OxAdjustPlugin.h"

FOUNDATION_EXPORT double OxAdjustPluginVersionNumber;
FOUNDATION_EXPORT const unsigned char OxAdjustPluginVersionString[];

