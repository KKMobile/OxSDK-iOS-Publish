//
//  OMApsBanner.h
//  OMApsAdapter
//
//  Created by 耿志向 on 2022/11/15.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DTBiOSSDK/DTBiOSSDK.h>
#import "OMBannerCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMApsBanner : UIView <OMBannerCustomEvent>
@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;
- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
@end

NS_ASSUME_NONNULL_END
