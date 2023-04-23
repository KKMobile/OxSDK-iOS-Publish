// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <HeliumSdk/HeliumSdk.h>
NS_ASSUME_NONNULL_BEGIN

@protocol OMHeliumAdapterDelegate <NSObject>

- (void)omHeliumDidLoadWithError:(nullable HeliumError *)error;
- (void)omHeliumDidShowWithError:(HeliumError *)error;
- (void)omHeliumDidClickWithError:(HeliumError *)error;
- (void)omHeliumDidCloseWithError:(HeliumError *)error;
- (void)omHeliumDidLoadWinningBidWithInfo:(NSDictionary*)bidInfo;
@optional
- (void)omHeliumDidGetReward:(NSInteger)reward;

@end

@interface OMHeliumRouter : NSObject <CHBHeliumInterstitialAdDelegate,CHBHeliumRewardedAdDelegate>
@property (nonatomic, strong) NSMapTable *placementDelegateMap;
@property (nonatomic, strong) NSMutableDictionary *placementAdMap;

+ (instancetype)sharedInstance;
- (void)registerPidDelegate:(NSString*)pid delegate:(id)delegate;
- (void)loadInterstitialWithPlacmentID:(NSString *)pid;
- (void)loadRewardedVideoWithPlacmentID:(NSString *)pid;
- (BOOL)isReady:(NSString *)pid;
- (void)showAd:(NSString *)pid withVC:(UIViewController*)vc;
- (BOOL)isCanLoad:(id)adpter pid:(NSString *)pid;

@end

NS_ASSUME_NONNULL_END
