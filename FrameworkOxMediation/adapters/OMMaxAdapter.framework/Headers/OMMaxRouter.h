//
//  OMMaxRouter.h
//  OMMaxAdapter
//
//  Created by 耿志向 on 2023/3/20.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMRewardedVideoCustomEvent.h"
#import "OMMaxRewardedVideoClass.h"

NS_ASSUME_NONNULL_BEGIN

@protocol OMMaxRouterDelegate <NSObject>

- (void)oMMaxDidReceiveReward;
- (void)oMMaxDidload:(MAAd *)ad;
- (void)oMMaxDidFailToLoad:(MAError*)error;
- (void)oMMaxDidOpen;
- (void)oMMaxDidStart;
- (void)oMMaxDidClick;
- (void)oMMaxVideoEnd;
- (void)oMMaxDidFinish;
- (void)oMMaxDidFailToShow:(MAError *)error;
@end

@interface OMMaxRouter : NSObject<MARewardedAdDelegate,MAAdRevenueDelegate,MAAdReviewDelegate>

@property (nonatomic, strong) NSMapTable *placementDelegateMap;

+ (instancetype)sharedInstance;
- (void)registerPidDelegate:(NSString*)pid delegate:(id)delegate;
- (BOOL)isCanLoad:(id)adpter pid:(NSString *)pid;
- (void)loadRewardeWithPlacmentID:(NSString *)pid;
- (void)show:(UIViewController *)vc;
- (BOOL)isReady;

@end

NS_ASSUME_NONNULL_END
