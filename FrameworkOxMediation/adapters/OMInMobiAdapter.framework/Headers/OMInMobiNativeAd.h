//
//  OMInMobiNativeAd.h
//  OMInMobiAdapter
//
//  Created by 耿志向 on 2022/11/15.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <InMobiSDK/InMobiSDK.h>
#import "OMMediatedNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMInMobiNativeAd : NSObject <OMMediatedNativeAd>

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


@property (nonatomic, strong) IMNative *adObject;

- (instancetype)initWithHybidNativeAd:(IMNative*)iMNative;

@end

NS_ASSUME_NONNULL_END
