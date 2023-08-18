//
//  OMHyBidRewardedVideo.h
//  OMVerveAdapter
//
//  Created by Mavl_2023_100272 on 2023/7/3.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMRewardedVideoCustomEvent.h"

@import HyBid;

NS_ASSUME_NONNULL_BEGIN

@interface OMVerveRewardedVideo : NSObject <OMRewardedVideoCustomEvent>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, weak) id<rewardedVideoCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
