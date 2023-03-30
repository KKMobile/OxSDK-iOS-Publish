//
//  OMPubMaticRewardedVideoClass.h
//  OMPubMaticAdapter
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import "OMPubMaticBannerClass.h"
#import "OMPubMaticClass.h"

#ifndef OMPubMaticRewardedVideoClass_h
#define OMPubMaticRewardedVideoClass_h


@class POBRewardedAd;
@class POBReward;
@protocol POBRewardedAdEvent;

NS_ASSUME_NONNULL_BEGIN
@protocol POBRewardedAdDelegate <NSObject>

@optional

/*!
 @abstract Notifies the delegate that an rewarded ad has been received successfully.
 @param rewardedAd The POBRewardedAd instance sending the message.
 */
-(void) rewardedAdDidReceiveAd:(POBRewardedAd *)rewardedAd;

/*!
 @abstract Notifies the delegate of an error encountered while loading an ad.
 @param rewardedAd The POBRewardedAd instance sending the message.
 @param error The error encountered while attempting to receive or render the ad.
 */
-(void) rewardedAd:(POBRewardedAd *)rewardedAd didFailToReceiveAdWithError:(NSError *)error;

/*!
 @abstract Notifies the delegate of an error encountered while showing an ad.
 @param rewardedAd The POBRewardedAd instance sending the message.
 @param error The error encountered while attempting to render the ad.
 */
-(void) rewardedAd:(POBRewardedAd *)rewardedAd didFailToShowAdWithError:(NSError *)error;

/*!
 @abstract Notifies the delegate that the rewarded ad will be presented as a modal on top of the current view controller.
 @param rewardedAd The POBRewardedAd instance sending the message.
 */
-(void) rewardedAdWillPresentAd:(POBRewardedAd *)rewardedAd;

/*!
 @abstract Notifies the delegate that the rewarded ad is presented as a modal on top of the current view controller.
 @param rewardedAd The POBRewardedAd instance sending the message.
 */
-(void) rewardedAdDidPresentAd:(POBRewardedAd *)rewardedAd;

/*!
 @abstract Notifies the delegate that the rewarded ad has been animated off the screen.
 @param rewardedAd The POBRewardedAd instance sending the message.
 */
-(void) rewardedAdDidDismissAd:(POBRewardedAd *)rewardedAd;

/*!
 @abstract Notifies the delegate of ad click
 @param rewardedAd The POBRewardedAd instance sending the message.
 */
-(void) rewardedAdDidClickAd:(POBRewardedAd *)rewardedAd;

/*!
 @abstract Notifies the delegate that a user interaction will open another app (e.g. App Store), leaving the current app. To handle user clicks that open the
 landing page URL in the internal browser, use 'RewardedAdDidClickAd:'
 instead.
 @param rewardedAd The POBRewardedAd instance sending the message.
 */
-(void) rewardedAdWillLeaveApplication:(POBRewardedAd *)rewardedAd;

/*!
 @abstract Notifies the delegate of an ad expiration. After this callback, this 'POBRewardedAd' instance is marked as invalid & will not be shown.
 @param rewardedAd The POBRewardedAd instance sending the message.
 */
-(void) rewardedAdDidExpireAd:(POBRewardedAd *)rewardedAd;

/*!
 @abstract Notifies the delegate that a user will be rewarded once the ad is completely viewed.
 @param rewardedAd The POBRewardedAd instance sending the message.
 @param reward The POBReward instance to reward.
 */
-(void) rewardedAd:(POBRewardedAd *)rewardedAd shouldReward:(POBReward *)reward;

@end

extern NSString *const kPOBAdServerCustomDataKey;
extern NSString *const kPOBSelectedRewardKey;

/**
 ------------------------------------------------------------------------------------
 POBRewardedAd Class
 ------------------------------------------------------------------------------------
 */

/*!
 Displays Rewarded Ads.
 */
@interface POBRewardedAd : NSObject<POBBidEvent>
/*!
 @abstract Initializes & returns a newly created Rewarded ad instance
 @param publisherId Unique identifier assigned at the time of publisher onboarding.
 @param profileId profile id
 @param adUnitId OpenWrap ad unit id used to identify unique placement on screen
 @return Instance of POBRewardedAd
 */
+ (POBRewardedAd*_Nullable)rewardedAdWithPublisherId:(NSString *)publisherId
                                           profileId:(NSNumber *)profileId
                                            adUnitId:(NSString *)adUnitId;

/*!
 @abstract Creates & maps a POBRewardedAd instance for an ad server ad unit id used while creating the handler.
 @discussion This is a convenient way of creating & maintaining a single rewarded ad instance per ad server ad unit(used while creating the handler).
 @param publisherId Unique identifier assigned at the time of publisher onboarding.
 @param profileId profile id
 @param adUnitId OpenWrap ad unit id used to identify unique placement on screen
 @param eventHandler Object conforming to POBRewardedAdEvent protocol
 @return Instance of POBRewardedAd
*/
+ (POBRewardedAd*_Nullable)rewardedAdWithPublisherId:(NSString *)publisherId
                                           profileId:(NSNumber *)profileId
                                            adUnitId:(NSString *)adUnitId
                                        eventHandler:(id<POBRewardedAdEvent>)eventHandler;
/*!
 @warning Use one of the convinience initializers instead of default init
 */
- (instancetype)init NS_UNAVAILABLE;

/*!
@abstract Initiates the loading of a rewarded ad
*/
- (void)loadAd NS_SWIFT_NAME(loadAd());

/*!
 @abstract Returns the winning bid that will be used to render the ad
 */
- (POBBid *)bid;

/*!
 @abstract Sets title, message & button texts to be used while showing the skip alert.
 @discussion If any of the parameters is empty the SDK discards all the values & shows a default skip alert.
 @param title alert title
 @param message alert message
 @param closeTitle title of the close button
 @param resumeTitle title of the resume button
 */
- (void)setSkipAlertInfoWithTitle:(NSString*)title
                          message:(NSString*)message
                 closeButtonTitle:(NSString*)closeTitle
                resumeButtonTitle:(NSString*)resumeTitle;

/*!
 @abstract Presents an rewarded ad in full screen view until the user dismisses it. Calling this method has no effect until the ad is received(rewardedAdDidReceiveAd:) and is ready to show, i.e. 'isReady' flag is true.
 @param controller UIViewController to be used for presenting the rewarded ad.
 */
- (void)showFromViewController:(UIViewController *)controller;

/*!
 @abstract Presents an rewarded ad in full screen view until the user dismisses it. Calling this method has no effect until the ad is received(rewardedAdDidReceiveAd:) and is ready to show, i.e. 'isReady' flag is true.
 @param controller UIViewController to be used for presenting the rewarded ad.
 @param customData Additional custom data to be used for showing rewarded ad.
 @discussion to pass any custom data to the ad server, use kPOBAdServerCustomDataKey
 To pass selected reward, use kPOBSelectedRewardKey
 */
- (void)showFromViewController:(UIViewController *)controller
                withCustomData:(NSDictionary*_Nullable)customData;

/*!
 @abstract Add custom data to be used by a client side partner/bidder.
 @param extra Partner extra object conforming to POBPartnerExtra protocol
*/
- (void)addPartnerExtra:(id<POBPartnerExtra>)extra;

/*!
 @abstract Available rewards when multiple rewards are configured for a rewarded ad
 @discussion When multiple rewards are configured, you can use this property to get the available rewards for a valid rewarded ad. You need to set selectedReward property to offer a reward to the user who watches ad till completion.
 Calling this method has no effect until the ad is received(rewardedAdDidReceiveAd:) and is ready to show, i.e. 'isReady' flag is true.
 */
@property (nonatomic, strong, readonly) NSArray<POBReward*> * _Nullable availableRewards;

/*!
 @abstract Sets the POBRewardedAdDelegate delegate receiver for the rewarded ad
 @warning Proper reference management practices should be observed when using delegates.
 @warning Ensure that the delegate is set to nil prior to setting nil to POBRewardedAd's object reference.
 */
@property (nonatomic, weak) id<POBRewardedAdDelegate> delegate;

/*!
 @abstract Object representing bid request
 @discussion You may set some additional targeting parameters on this object
 */
@property (nonatomic, readonly) POBRequest *request;

/*!
 @abstract Managed impression object created internally. It provides APIs to set PubMatic zone id and other custom parameterss
 */
@property (nonatomic, readonly) POBImpression *impression;

/*!
 @abstract Returns YES if the rewarded ad is ready to be displayed. The delegate’s rewardedAdDidReceiveAd: will be called after this property switches from NO to YES.
 */
@property (nonatomic, assign, readonly) BOOL isReady;

@end

NS_ASSUME_NONNULL_END

#endif /* OMPubMaticRewardedVideoClass_h */
