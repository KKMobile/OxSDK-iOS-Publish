//
//  OMPubMaticBannerClass.h
//  OMPubMaticAdapter
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#ifndef OMPubMaticBannerClass_h
#define OMPubMaticBannerClass_h

#import "OMPubMaticClass.h"
#import <UIKit/UIKit.h>

@class POBBannerView;
@class POBRequest;
@class POBImpression;
@class POBAdSize;
@class POBBid;
@class POBImpression;

#define BID_STATUS_OK  @1

@class POBBidSummary, POBRequest;

@protocol POBBidEventDelegate;
@protocol POBBannerEvent;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kPOBWDealIdKey;
extern NSString *const kPOBBidIdKey;
extern NSString *const kPOBBidPriceKey;
extern NSString *const kPOBBidStatusKey;
extern NSString *const kPOBBidPartnerKey;
extern NSString *const kPOBBidSizeKey;
extern NSString *const kPOBWrapperPlatformKey;
extern NSString *const kPOBBidRequestPubmaticPartnerId;
extern NSString *const kPOBImpressionId;
extern NSString *const kPOBBidId;
extern NSString *const kPOBBidPrice;
extern NSString *const kPOBBidNetECPM;
extern NSString *const kPOBBidRequestPartner;
extern NSString *const kPOBBidRequestedAdSize;
extern NSString *const kPOBBidTypeStatic;
extern NSString *const kPOBBidCrTypeExtPath;

@protocol POBBidEvent <NSObject>

@property (nonatomic, weak) id<POBBidEventDelegate> bidEventDelegate;

- (BOOL)proceedToLoadAd;
- (void)proceedOnError:(POBBidEventErrorCode )code andDescription:(NSString *)description;
@end
/*!
 Protocol for bit notificatrions
 
 All messages are guaranteed to occur on the main thread.
 */
@protocol POBBidEventDelegate <NSObject>
/*!
 @abstract Notifies the delegate that bid has been successfully received
 @param bidEventObject Instance of object conforming to POBBidEvent (e.g. POBBannerView or POBInterstitial etc)
 @param bid POBBid object
 */
- (void)bidEvent:(id<POBBidEvent>)bidEventObject didReceiveBid:(POBBid *)bid;

/*!
 @abstract Notifies the delegate of an error encountered while fetching the bid
 @param bidEventObject Instance of object conforming to POBBidEvent (e.g. POBBannerView or POBInterstitial etc)
 @param error The error encountered while attempting to receive the bid.
 */
- (void)bidEvent:(id<POBBidEvent>)bidEventObject didFailToReceiveBidWithError:(NSError *)error;
@end


@protocol POBBannerViewDelegate<NSObject>

@required

/** @name Methods */
/*!
 @abstract Asks the delegate for a view controller instance to use for presenting modal views as a result of user interaction on an ad. Usual implementation may simply return self, if it is a view controller class.
 */
- (UIViewController *)bannerViewPresentationController;

@optional


/*!
 @abstract Notifies the delegate that an ad has been successfully loaded and rendered..
 @param bannerView The POBBannerView instance sending the message.
 */
- (void)bannerViewDidReceiveAd:(POBBannerView *)bannerView;

/*!
 @abstract Notifies the delegate of an error encountered while loading or rendering an ad.
 @param bannerView The POBBannerView instance sending the message.
 @param error The error encountered while attempting to receive or render the
 ad.
 */
- (void)bannerView:(POBBannerView *)bannerView
didFailToReceiveAdWithError:(NSError *)error;

/*!
 @abstract Notifies the delegate whenever current app goes in the background due to user click.
 @param bannerView The POBBannerView instance sending the message.
 */
- (void)bannerViewWillLeaveApplication:(POBBannerView *)bannerView;

/*!
 @abstract Notifies delegate that the banner view will launch a modal on top of the current view controller, as a result of user interaction.
 @param bannerView The POBBannerView instance sending the message.
 */
- (void)bannerViewWillPresentModal:(POBBannerView *)bannerView;

/*!
 @abstract Notifies delegate that the banner view has dismissed the modal on top of
 the current view controller.
 @param bannerView The POBBannerView instance sending the message.
 */
- (void)bannerViewDidDismissModal:(POBBannerView *)bannerView;

/*!
 @abstract Notifies the delegate that the banner view was clicked.
 @param bannerView The POBBannerView instance sending the message.
 */
- (void)bannerViewDidClickAd:(POBBannerView *)bannerView;


@end


@protocol POBPartnerExtra <NSObject>

/*!
 @discussion Partner ID for the partner
 */
- (NSString* _Nonnull)partnerId;
@end

@interface POBBannerView : UIView <POBBidEvent>

/*!
 @abstract Initializes & returns a newly allocated banner view object.
 @param publisherId Unique identifier assigned at the time of publisher onboarding.
 @param profileId Profile id of the ad tag.
 @param adUnitId Ad unit id used to identify unique placement on screen.
 @param eventHandler Object conforming to POBBannerEvent protocol
 @result Instance of POBBannerView
 */
- (instancetype _Nullable)initWithPublisherId:(NSString *)publisherId
                          profileId:(NSNumber *)profileId
                           adUnitId:(NSString *)adUnitId
                            eventHandler:(id<POBBannerEvent>)eventHandler;

/*!
 @abstract Initializes & returns a newly allocated banner view object for supporting 'No Ad Server Configuration'.
 @param publisherId Unique identifier assigned at the time of publisher onboarding.
 @param profileId Profile id of the ad tag.
 @param adUnitId Ad unit id used to identify unique placement on screen.
 @param adSizes List of banner ad sizes for this impression
 @result Instance of POBBannerView
 */
- (instancetype _Nullable)initWithPublisherId:(NSString *)publisherId
                          profileId:(NSNumber *)profileId
                           adUnitId:(NSString *)adUnitId
                            adSizes:(NSArray<POBAdSize *> *)adSizes;

/*!
 @abstract Initiates the loading of the banner ad
 */
- (void)loadAd;

/*!
 Pauses the auto refresh, By default, banner refreshes automatically as per
 configured refresh interval on openwrap portal. Calling this method
 prevents the refresh cycle to happen even if a refresh interval has been specified.
 
 It is recommended to use this method whenever the ad view is about to be hidden
 from the user for any period of time, to avoid unnecessary ad requests. You can
 then call `resumeAutoRefresh` to resume the refresh when banner becomes
 visible.
 @see resumeAutoRefresh
 */
- (void)pauseAutoRefresh;

/*!
 Resumes the autorefresh as per configured refresh interval on openwrap portal, call this method only if you have previously paused autorefresh using `pauseAutoRefresh`. This method has no effect if a refresh interval has not been set.
 @see pauseAutoRefresh
 */
- (void)resumeAutoRefresh;

/*!
 @abstract Cancels existing ad requests and initiates new ad request
 @warning It may skip force refresh if ad creative is being loaded, user interacting with ad (Opening Internal browser or expanding ad) or waiting response from ad server SDK if applicable.
 @result Status YES/NO, about force refresh, as described it can skip in few cases by returning 'NO'
*/
- (BOOL)forceRefresh;

/*!
 @abstract Add custom data to be used by a client side partner/bidder.
 @param extra Partner extra object conforming to POBPartnerExtra protocol
*/
- (void)addPartnerExtra:(id<POBPartnerExtra>)extra;

/*!
 @abstract Sets the POBBannerViewDelegate receiver for the ad view.
 @warning Proper reference management practices should be observed when using delegates.
 @warning Ensure that the delegate is set to nil prior to setting nil to banner view's object reference.
 */
@property (nonatomic, weak) id <POBBannerViewDelegate> _Nullable delegate;

/*!
 @abstract Object representing bid request
 @discussion You may set some additional targeting parameters on this object
 @see POBRequest
 */
@property (nonatomic, readonly)  POBRequest *request;

/*!
 @abstract Managed impression object created internally. It provides APIs to set pubmatic zone id and other custom parameters.
 */
@property (nonatomic, readonly)  POBImpression *impression;

/*!
 @abstract Size of the rendered ad creative
 */
- (POBAdSize *)creativeSize;

/*!
@abstract Returns the winning bid that will be used to render the ad
 */
- (POBBid *)bid;
@end


@protocol POBAdDescriptor <NSObject>
- (NSString *)renderableContent;
- (CGSize )contentSize;

/// Returns type of descriptor (e.g. video, banner ...etc )
- (NSString *)type;

- (BOOL)isVideo;
- (NSDictionary*)rawBidJson;
// Returns current refresh interval
- (NSTimeInterval)adRefreshInterval;
@end

@interface POBBid : NSObject<POBAdDescriptor>

@property (nonatomic, readonly) NSNumber *price;

@end


NS_ASSUME_NONNULL_END

#endif /* OMPubMaticBannerClass_h */
