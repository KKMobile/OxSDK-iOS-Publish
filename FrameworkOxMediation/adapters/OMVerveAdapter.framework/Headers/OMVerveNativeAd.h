//
//  OMVerveNativeAd.h
//  OMVerveAdapter
//
//  Created by Mavl_2023_100272 on 2023/7/3.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMMediatedNativeAd.h"

@import HyBid;

NS_ASSUME_NONNULL_BEGIN

@interface OMVerveNativeAd : NSObject <OMMediatedNativeAd>

/// Title.
@property (nonatomic, copy) NSString *title;

/// Body.
@property (nonatomic, copy) NSString *body;

/// Icon image.
@property (nonatomic, copy) NSString *iconUrl;

/// Text that encourages user to take some action with the ad. For example "Install".
@property (nonatomic, copy) NSString *callToAction;

/// App store rating (0 to 5).
@property (nonatomic, assign) double rating;

/// Native view class string.
@property (nonatomic, copy) NSString *nativeViewClass;

@property (nonatomic, strong) HyBidNativeAd *adObject;

@property (nonatomic, weak)id<HyBidNativeAdDelegate> delegate;

- (instancetype)initWithHyBidNativeAd:(HyBidNativeAd *)hyBidNativeAd;

@end

NS_ASSUME_NONNULL_END
