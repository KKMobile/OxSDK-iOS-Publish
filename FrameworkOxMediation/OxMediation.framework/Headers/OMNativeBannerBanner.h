//
//  OmNativeBanner.h
//  OxMediation
//
//  Created by 耿志向 on 2023/3/14.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OMBannerCustomEvent.h"
#import "OMBidCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMNativeBannerBanner : UIView <OMBannerCustomEvent>

@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
