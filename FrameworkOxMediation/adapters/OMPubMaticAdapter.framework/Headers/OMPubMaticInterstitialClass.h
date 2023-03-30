//
//  OMPubMaticInterstitialClass.h
//  OMPubMaticAdapter
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import "OMPubMaticBannerClass.h"
#import "OMPubMaticClass.h"

@protocol POBInterstitialRendering;
@protocol POBFullscreenAdInteractionDelegate;
@protocol POBInterstitialEventDelegate;

#ifndef OMPubMaticInterstitialClass_h
#define OMPubMaticInterstitialClass_h

@class POBInterstitial;

NS_ASSUME_NONNULL_BEGIN

@protocol POBInterstitialEvent<NSObject>
@required

/*!
 @abstract OpenWrap SDK calls this method when it has valid bid/s to pass to the ad server.
 @discussion Note that, if the OpenWrap SDK does not have valid bids, `requestAdWithBid:` will be called with a `nil` bid value.
 @param bid bid details object having price and other useful information that can be passed to the ad server SDK
 */
- (void)requestAdWithBid:(POBBid *_Nullable)bid;

/*!
 @abstract OpenWrap SDK calls this method to set POBInterstitialEventDelegate, so that the interstitial custom event handler can inform the OpenWrap SDK about the events related to the ad server communication.
 @discussion Save the `delegate` to use it in later phases of ad server events execution
 @param delegate object of POBInterstitialEventDelegate implmentation
 */
- (void)setDelegate:(id<POBInterstitialEventDelegate>) delegate;

/*!
 @abstract OpenWrap SDK calls this method to show the interstitial ad from the ad server SDK
 @param controller view controller to be used for presenting the interstitial ad
*/
- (void)showFromViewController:(UIViewController * _Nonnull)controller;

@optional
/*!
 Optional delegate to provide implementation of POBInterstitialRendering protocol to render ad in custom rendering component. If not implemented, the OpenWrap SDK internally creates its own renderer capable of handling simple HTML and MRAID creatives
 @param partner name of the partner associated with the winning bid
 */
- (id<POBInterstitialRendering> _Nullable)rendererForPartner:(NSString *)partner;

/*!
 @abstract Return a delegate object to receive all the ad lifecycle events.
 @discussion OW SDK will inform the ad lifecycle events to this object. This is mostly useful when ad servers are integrated using mediation waterfall.
 @return id<POBFullscreenAdInteractionDelegate> interaction delegate
 */
- (id<POBFullscreenAdInteractionDelegate>)interactionDelegate;

@end

@protocol POBInterstitialDelegate<NSObject>
@optional
/*!
 @abstract Notifies the delegate that an ad has been received successfully.
 @param interstitial The POBInterstitial instance sending the message.
 */
- (void)interstitialDidReceiveAd:(POBInterstitial *)interstitial;

/*!
 @abstract Notifies the delegate of an error encountered while loading an ad.
 @param interstitial The POBInterstitial instance sending the message.
 @param error The error encountered while loading an ad.
 */
- (void)interstitial:(POBInterstitial *)interstitial
didFailToReceiveAdWithError:(NSError *)error;

/*!
 @abstract Notifies the delegate of an error encountered while showing an ad.
 @param interstitial The POBInterstitial instance sending the message.
 @param error The error encountered while showing an ad.
 */
- (void)interstitial:(POBInterstitial *)interstitial didFailToShowAdWithError:(NSError *)error;


/*!
 @abstract Notifies the delegate that the interstitial ad will be presented as a modal on top of the current view controller.
 @param interstitial The POBInterstitial instance sending the message.
 */
- (void)interstitialWillPresentAd:(POBInterstitial *)interstitial;

/*!
 @abstract Notifies the delegate that the interstitial ad is presented as a modal on top of the current view controller.
 @param interstitial The POBInterstitial instance sending the message.
 */
- (void)interstitialDidPresentAd:(POBInterstitial *)interstitial;

/*!
 @abstract Notifies the delegate that the interstitial ad has been animated off the screen.
 @param interstitial The POBInterstitial instance sending the message.
 */
- (void)interstitialDidDismissAd:(POBInterstitial *)interstitial;

/*!
 @abstract Notifies the delegate that a user interaction will open another app (e.g. App Store), leaving the current app. To handle user clicks that open the
 landing page URL in the internal browser, use 'interstitialDidClickAd:'
 instead.
 @param interstitial The POBInterstitial instance sending the message.
 */
- (void)interstitialWillLeaveApplication:(POBInterstitial *)interstitial;

/*!
 @abstract Notifies the delegate of ad click
 @param interstitial The POBInterstitial instance sending the message.
 */
- (void)interstitialDidClickAd:(POBInterstitial *)interstitial;

/*!
 @abstract Notifies the delegate of an ad expiration. After this callback, this 'POBInterstitial' instance is marked as invalid & will not be shown.
 @param interstitial The POBInterstitial instance sending the message.
 */
- (void)interstitialDidExpireAd:(POBInterstitial *)interstitial;
@end

/*!
 Protocol for VAST based video ad events
 All messages are guaranteed to occur on the main thread.
 */
@protocol POBInterstitialVideoDelegate<NSObject>
@optional
/*!
 @abstract Notifies the delegate that playback has completed
 @param interstitial The POBInterstitial instance sending the message.
 */
- (void)interstitialDidFinishVideoPlayback:(POBInterstitial *)interstitial;
@end

/* ------------------------------------------------------------------------------------
 POBInterstitial Class
 ------------------------------------------------------------------------------------
 */

/*!
 Displays Interstitial Ads.
 */
@interface POBInterstitial : NSObject<POBBidEvent>
/*!
 @abstract Initializes & returns a newly initialized Interstitial object with the specified POBInterstitialEvent implementaion and other details.
 @param publisherId Unique identifier assigned at the time of publisher onboarding.
 @param profileId Profile id.
 @param adUnitId Ad unit id used to identify unique placement on screen.
 @param eventHandler Object conforming to POBInterstitialEvent protocol
 @result Instance of POBInterstitial
 */
- (instancetype _Nullable)initWithPublisherId:(NSString *)publisherId
                                    profileId:(NSNumber *)profileId
                                     adUnitId:(NSString *)adUnitId
                                 eventHandler:(id<POBInterstitialEvent>)eventHandler;

/*!
 @abstract Initializes & returns a newly initialized Interstitial object for supporting 'No Ad Server Configuration'.
 @param publisherId Unique identifier assigned at the time of publisher onboarding.
 @param profileId Profile id.
 @param adUnitId Ad unit id used to identify a unique placement on screen.
 @result Instance of POBInterstitial
 */
- (instancetype _Nullable)initWithPublisherId:(NSString *)publisherId
                                    profileId:(NSNumber *)profileId
                                     adUnitId:(NSString *)adUnitId;

/*!
 @abstract Initiates the loading of an interstitial ad
 */
- (void)loadAd;

/*!
 @abstract Returns the winning bid that will be used to render the ad
 */
- (POBBid *)bid;

/*!
 @abstract Presents an interstitial ad in full screen view until the user dismisses it. Calling this method has no effect until the ad is received(interstitialDidReceiveAd:) and is ready to show, i.e. 'isReady' flag is true.
 @param controller UIViewController to be used for presenting the interstitial ad.
 */
- (void)showFromViewController:(UIViewController*)controller;

/*!
 @abstract Add custom data to be used by a client side partner/bidder.
 @param extra Partner extra object conforming to POBPartnerExtra protocol
*/
- (void)addPartnerExtra:(id<POBPartnerExtra>)extra;

/*!
 @abstract Sets the POBInterstitialDelegate delegate receiver for the interstitial ad
 @warning Proper reference management practices should be observed when using delegates.
 @warning Ensure that the delegate is set to nil prior to setting nil to POBInterstitial's object reference.
 */
@property (nonatomic, weak) id <POBInterstitialDelegate> _Nullable delegate;

/*!
 @abstract Object representing bid request
 @discussion You may set some additional targeting parameters on this object
 @see POBRequest
 */
@property (nonatomic, readonly) POBRequest *request;

/*!
 @abstract Managed impression object created internally. It provides APIs to set PubMatic zone id and other custom parameterss
 */
@property (nonatomic, readonly) POBImpression *impression;

/*!
 @abstract Returns YES if the interstitial is ready to be displayed. The delegate’s interstitialDidReceiveAd: will be called after this property switches from NO to YES.
 */
@property (nonatomic, assign, readonly) BOOL isReady;

/*!
 @abstract Sets the POBInterstitialVideoDelegate delegate receiver for the interstitial ad which will notify about VAST based video events.
 Renderer which does not render VAST videos in Interstitial, may avoid setting this delegate.
 */
@property (nonatomic, weak) id <POBInterstitialVideoDelegate> videoDelegate;
@end

NS_ASSUME_NONNULL_END

#endif /* OMPubMaticInterstitialClass_h */
