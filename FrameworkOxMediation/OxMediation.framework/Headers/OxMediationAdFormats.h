// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#ifndef OxMediationAdFormats_h
#define OxMediationAdFormats_h

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSInteger, OxMediationAdFormat) {
    OxMediationAdFormatNone = 0,
    OxMediationAdFormatBanner = (1 << 0),
    OxMediationAdFormatNative = (1 << 1),
    OxMediationAdFormatRewardedVideo = (1 << 2),
    OxMediationAdFormatInterstitial = (1 << 3),
    OxMediationAdFormatSplash = (1 << 4),
    OxMediationAdFormatCrossPromotion = (1 << 5),
};

#endif /* OxMediationAdFormats_h */
