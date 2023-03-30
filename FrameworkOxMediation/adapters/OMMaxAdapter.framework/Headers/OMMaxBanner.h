//
//  OMMaxBanner.h
//  OMMaxAdapter
//
//  Created by 耿志向 on 2022/11/13.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OMBannerCustomEvent.h"
#import "OMMaxBannerClass.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMMaxBanner : UIView <OMBannerCustomEvent,MAAdViewAdDelegate,MAAdRevenueDelegate,MAAdReviewDelegate>

@property (nonatomic, copy) NSString *pid;
@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;
- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
