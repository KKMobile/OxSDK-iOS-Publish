//
//  OMApsInterstitial.h
//  OMApsAdapter
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMRewardedVideoCustomEvent.h"
#import "OMApsClass.h"
#import "OMApsInterstitialClass.h"
#import "OMApsBannerClass.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMApsRewardedVideo : NSObject <OMRewardedVideoCustomEvent>

@property(nonatomic, weak, nullable) id<rewardedVideoCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;
- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;
@end

NS_ASSUME_NONNULL_END
