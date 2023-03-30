//
//  OMInMobiNativeClass.h
//  OxMediation
//
//  Created by 耿志向 on 2022/11/13.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#ifndef OMInMobiNativeClass_h
#define OMInMobiNativeClass_h
#import "OMInMobiClass.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class IMNative;
@protocol IMNativeDelegate <NSObject>
@optional
/**
 * Notifies the delegate that the native ad has finished loading
 */
-(void)nativeDidFinishLoading:(IMNative*)native;
/**
 * Notifies the delegate that the native ad has failed to load with error.
 */
-(void)native:(IMNative*)native didFailToLoadWithError:(IMRequestStatus*)error;
/**
 * Notifies the delegate that the native ad would be presenting a full screen content.
 */
-(void)nativeWillPresentScreen:(IMNative*)native;
/**
 * Notifies the delegate that the native ad has presented a full screen content.
 */
-(void)nativeDidPresentScreen:(IMNative*)native;
/**
 * Notifies the delegate that the native ad would be dismissing the presented full screen content.
 */
-(void)nativeWillDismissScreen:(IMNative*)native;
/**
 * Notifies the delegate that the native ad has dismissed the presented full screen content.
 */
-(void)nativeDidDismissScreen:(IMNative*)native;
/**
 * Notifies the delegate that the user will be taken outside the application context.
 */
-(void)userWillLeaveApplicationFromNative:(IMNative*)native;
/**
 * Notifies the delegate that the native ad impression has been tracked
 */
-(void)nativeAdImpressed:(IMNative*)native;
/**
 * Notifies the delegate that the native ad has been interacted with.
 */
-(void)native:(IMNative*)native didInteractWithParams:(NSDictionary*)params;
/**
 * Notifies the delegate that the native ad has finished playing media.
 */
-(void)nativeDidFinishPlayingMedia:(IMNative*)native;
/**
 * Notifies the delegate that the user has skipped the playing media.
 */
-(void)userDidSkipPlayingMediaFromNative:(IMNative*)native;
/**
 * Notifies the delegate that the media audio state has been changed - mute/unmute.
 * @param audioStateMuted is YES when audio is turned off and NO when audio is turned on.
 */
-(void)native:(IMNative*)native adAudioStateChanged:(BOOL)audioStateMuted;
@end

@interface IMNative : NSObject
/**
 * The primary view of the native ad. This view is rendered by InMobi and should be used by the publisher to display the ad. Impressions will be computed on this view.
 * @param width The width of the primary view. Typically this should be the screen width.
 */
-(UIView*)primaryViewOfWidth:(CGFloat)width;
/**
 * The placement ID for this Native Ad..
 */
@property (nonatomic, assign) long long placementId;
/**
 * The content of the native ad.
 */
@property (nonatomic, strong, readonly) NSString* customAdContent;
/**
 * The title of the native ad.
 */
@property (nonatomic, strong, readonly) NSString* adTitle;
/**
 * The description of the native ad.
 */
@property (nonatomic, strong, readonly) NSString* adDescription;
/**
 * The icon url of the ad.
 */
@property (nonatomic, strong, readonly) UIImage* adIcon;
/**
 * The text to be specified for the cta. Typically this should be the text of the button.
 */
@property (nonatomic, strong, readonly) NSString* adCtaText;
/**
 * A custom rating field for the native ad.
 */
@property (nonatomic, strong, readonly) NSString* adRating;
/**
 * The landing page url of the Native ad.
 */
@property (nonatomic, strong, readonly) NSURL* adLandingPageUrl;
/**
 * Indicates if the ad is an app download ad.
 */
@property (nonatomic, readonly) BOOL isAppDownload;
/**
 * The delegate to receive callbacks
 */
@property (nonatomic, weak) id<IMNativeDelegate> delegate;
/**
 * A free form set of keywords, separated by ',' to be sent with the ad request.
 * E.g: "sports,cars,bikes"
 */
@property (nonatomic, strong) NSString* keywords;
/**
 * Any additional information to be passed to InMobi.
 */
@property (nonatomic, strong) NSDictionary* extras;
/**
 * A unique identifier for the creative.
 */
@property (nonatomic, strong, readonly) NSString* creativeId;
/**
 * contentUrl for OMSDK
 */
@property (nonatomic, strong) NSString* contentUrl;
/**
 * init and new methods are unavailable for this class
 * use "initWithPlacementId:" or "initWithPlacementId:delegate:" method.
 */
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Initialize a Native ad with the given PlacementId
 * @param placementId The placementId for loading the native ad
 */
-(instancetype)initWithPlacementId:(long long)placementId;
/**
 * Initialize a Native ad with the given PlacementId
 * @param placementId The placementId for loading the native ad
 * @param delegate The delegate to receive callbacks from IMNative
 */
-(instancetype)initWithPlacementId:(long long)placementId delegate:(id<IMNativeDelegate>)delegate NS_DESIGNATED_INITIALIZER;
/**
 * Loads a Native ad
 */
-(void)load;
/**
 * Loads a Native Ad with a response Object. This is used for Open Auction use cases
 * @param response An NSData object which contains the InMobi Native Ad
 */
-(void)load:(NSData*)response;
/**
 * Indicates if the native ad is ready to be displayed.
 */
-(BOOL)isReady;
/**
 * Reports the click action to the native ad and open the landing page.
 */
-(void)reportAdClickAndOpenLandingPage;
/**
 * Recycle the view that was presented by the native ad
 */
-(void)recyclePrimaryView;
/**
 * Contains additional information of ad.
 */
- (NSDictionary *)getAdMetaInfo;

@end




#endif /* OMInMobiNativeClass_h */

NS_ASSUME_NONNULL_END
