//
//  OxAdData.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/6/19.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

@class OxAd;
NS_ASSUME_NONNULL_BEGIN

@interface OxAdData : NSObject

@property(nonatomic, assign) OxSdkAdFormat adFormat;
@property(nonatomic, copy) NSString *adFormatValue;
@property(nonatomic, copy) NSString *adUnitId;
@property(nonatomic, copy) NSString *adUnitName;
@property(nonatomic, copy) NSString *showPlacement;
@property(nonatomic, copy) NSString *networkName;
@property(nonatomic, copy) NSString *waterfallName;
@property(nonatomic, copy) NSString *creativeId;
@property(nonatomic, copy) NSString *errorMessage;
@property(nonatomic, copy) NSString *bannerSize;

@property(nonatomic, assign) double revenue;
@property(nonatomic, assign) NSInteger networkResponses;
@property(nonatomic, assign) long duration;
@property(nonatomic, assign) long loadStartTime;
@property(nonatomic, assign) double latencyMillis;

+ (OxAdData *)createAdData:(OxAd *)ad;

@end

NS_ASSUME_NONNULL_END
