//
//  OMHeliumBanner.h
//  OMHeliumAdapter
//
//  Created by 耿志向 on 2022/11/11.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMHeliumClass.h"
#import "OMBannerCustomEvent.h"
#import "OMHeliumRouter.h"
#import "OMBidCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMHeliumBanner : UIView <OMBannerCustomEvent,CHBHeliumBannerAdDelegate>

@property (nonatomic) HeliumBannerView *bannerAd;
@property (nonatomic, copy) NSString *pid;
@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
