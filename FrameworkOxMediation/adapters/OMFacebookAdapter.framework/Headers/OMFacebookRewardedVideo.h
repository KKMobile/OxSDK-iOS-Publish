// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <FBAudienceNetwork/FBAudienceNetwork.h>
#import "OMRewardedVideoCustomEvent.h"
NS_ASSUME_NONNULL_BEGIN

@interface OMFacebookRewardedVideo : NSObject<FBRewardedVideoAdDelegate,OMRewardedVideoCustomEvent>
@property (nonatomic, copy) NSString *pid;
@property (nonatomic, strong) FBRewardedVideoAd *faceBookPlacement;
@property (nonatomic, weak) id<rewardedVideoCustomEventDelegate> delegate;
@property (nonatomic, assign) BOOL ready;
@property (nonatomic, getter=isAdValid, readonly) BOOL adValid;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (void)loadAdWithBidPayload:(NSString *)bidPayload localExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;
@end

NS_ASSUME_NONNULL_END
