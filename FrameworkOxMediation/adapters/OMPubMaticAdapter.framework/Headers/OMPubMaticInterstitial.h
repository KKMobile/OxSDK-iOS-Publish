//
//  OMPubMaticInterstitial.h
//  OMPubMaticAdapter
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMInterstitialCustomEvent.h"
#import "OMPubMaticInterstitialClass.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMPubMaticInterstitial : NSObject <OMInterstitialCustomEvent,POBInterstitialDelegate,POBBidEventDelegate>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, weak) id<interstitialCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;
@property (nonatomic, strong) POBInterstitial *interstitialAd;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
