//
//  OMPubMaticBanner.h
//  OMPubMaticAdapter
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OMBannerCustomEvent.h"
#import "OMBidCustomEvent.h"
#import "OMPubMaticClass.h"
#import "OMPubMaticBannerClass.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMPubMaticBanner : UIView<OMBannerCustomEvent,POBBannerViewDelegate,POBBidEventDelegate>

@property (nonatomic) POBBannerView *bannerView;
@property (nonatomic, copy) NSString *pid;
@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
