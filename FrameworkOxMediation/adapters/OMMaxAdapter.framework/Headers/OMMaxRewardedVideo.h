//
//  OMMaxRewardedVideo.h
//  OMMaxAdapter
//
//  Created by 耿志向 on 2022/11/13.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMRewardedVideoCustomEvent.h"
#import "OMMaxRewardedVideoClass.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMMaxRewardedVideo : NSObject <OMRewardedVideoCustomEvent>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, weak) id<rewardedVideoCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;
@property (nonatomic, strong) MARewardedAd *rewardedAd;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
