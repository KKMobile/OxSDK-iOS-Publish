// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OMRewardedVideoDelegate.h"
#import "OMRewardedVideoAd.h"
#import "OMAdHelperCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN
@interface OMRewardedVideo : NSObject <RewardedVideoDelegate,OMAdHelperCustomEvent>

@property (nonatomic, weak)id<OMRewardedVideoDelegate> delegate;
@property (nonatomic, strong) OMRewardedVideoAd *rewardedVideoAd;

- (instancetype)initWithPlacementId:(NSString *)placementId;

- (void)loadAd;

- (BOOL)isReady;

- (void)showWithViewController:(UIViewController *)viewController;


@end

NS_ASSUME_NONNULL_END
