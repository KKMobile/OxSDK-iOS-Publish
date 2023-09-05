//
//  GADMCustomAdapterGoogleAdmobNativeAd.h
//  OxSDK-Game_Example
//
//  Created by Mavl_2023_100272 on 2023/6/20.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMobileAds/GoogleMobileAds.h>

NS_ASSUME_NONNULL_BEGIN

@interface GADMCustomAdapterGoogleAdmobNativeAd : NSObject <GADMediationNativeAd>

- (void)loadNativeAdForAdConfiguration:(GADMediationNativeAdConfiguration *)adConfiguration completionHandler:(GADMediationNativeLoadCompletionHandler)completionHandler;

@end

NS_ASSUME_NONNULL_END
