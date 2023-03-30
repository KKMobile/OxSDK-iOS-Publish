//
//  OMPubMaticRewardedVideo.h
//  OMPubMaticAdapter
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMRewardedVideoCustomEvent.h"
#import "OMPubMaticRewardedVideoClass.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMPubMaticRewardedVideo : NSObject <OMRewardedVideoCustomEvent,POBRewardedAdDelegate,POBBidEventDelegate>

@property (nonatomic, weak) id<rewardedVideoCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;
@property (nonatomic) POBRewardedAd *rewardedAd;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
