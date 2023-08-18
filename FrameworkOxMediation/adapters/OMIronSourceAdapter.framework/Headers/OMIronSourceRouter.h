// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <IronSource/IronSource.h>
#import "OMIronSourceAdapter.h"

NS_ASSUME_NONNULL_BEGIN

@protocol OMIronSourceAdapterDelegate <NSObject>

- (void)OMIronSourceDidReceiveReward;
- (void)OMIronSourceDidload;
- (void)OMIronSourceDidFailToLoad:(NSError*)error;
- (void)OMIronSourceDidStart;
- (void)OMIronSourceDidClick;
- (void)OMIronSourceVideoEnd;
- (void)OMIronSourceDidFinish;
- (void)OMIronSourceDidFailToShow:(NSError *)error;

- (void)OMIronSourceBannerDidload:(ISDemandOnlyBannerView *)bannerView;
@end

@protocol OMIronSourceBannerAdapterDelegate <NSObject>

- (void)OMIronSourceDidFailToLoad:(NSError*)error;
- (void)OMIronSourceDidClick;
- (void)OMIronSourceBannerDidload:(ISDemandOnlyBannerView *)bannerView;
@end


@interface OMIronSourceRouter : NSObject<ISDemandOnlyInterstitialDelegate,ISDemandOnlyRewardedVideoDelegate,ISDemandOnlyBannerDelegate>

@property (nonatomic, strong) NSMapTable *placementDelegateMap;

+ (instancetype)sharedInstance;
- (void)registerPidDelegate:(NSString*)pid delegate:(id)delegate;
- (BOOL)isCanLoad:(id)adpter pid:(NSString *)pid;

@end

NS_ASSUME_NONNULL_END
