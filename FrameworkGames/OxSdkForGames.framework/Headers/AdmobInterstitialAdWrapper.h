//
//  AdmobInterstitialAdWrapper.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/11/22.
//

#import <Foundation/Foundation.h>
@import GoogleMobileAds;

NS_ASSUME_NONNULL_BEGIN

@interface AdmobInterstitialAdWrapper : NSObject

@property (nonatomic, strong) GADInterstitialAd* ad;
@property (nonatomic, assign) long loadedTimestamp;

- (instancetype)initWithAd:(GADInterstitialAd *)ad;

- (BOOL)isAvailable;

@end

NS_ASSUME_NONNULL_END
