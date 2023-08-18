//
//  OMHyBidBanner.h
//  OMVerveAdapter
//
//  Created by Mavl_2023_100272 on 2023/7/3.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OMBannerCustomEvent.h"

@import HyBid;

NS_ASSUME_NONNULL_BEGIN

@interface OMVerveBanner : UIView <OMBannerCustomEvent>

@property (nonatomic, copy) NSString *pid;
@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
