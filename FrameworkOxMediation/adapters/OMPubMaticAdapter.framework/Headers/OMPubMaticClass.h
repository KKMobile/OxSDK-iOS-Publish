//
//  OMPubMaticClass.h
//  OMPubMaticAdapter
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

#ifndef OMPubMaticClass_h
#define OMPubMaticClass_h


@class POBUserInfo;
@class POBExternalUserId;

extern NSString * const kPOBErrorDomain;

/*!
 *  Various Ad Event Types
 */
typedef NS_ENUM(NSUInteger, POBVideoAdEvent) {
    
    /// Event Type Impression occured
    POBVideoAdEventImpression,
    
    /// Event Type video paused
    POBVideoAdEventPause,
    
    /// Event Type video resumed
    POBVideoAdEventResume,
    
    /// Event Type First Quartile occured
    POBVideoAdEventFirstQuartile,
    
    /// Event Type Midpoint occured
    POBVideoAdEventMidpoint,
    
    /// Event Type Third Quartile occured
    POBVideoAdEventThirdQuartile,
    
    /// Event Type Video skipped
    POBVideoAdEventSkip,
    
    /// Event Type Video finished
    POBVideoAdEventComplete,
    
    /// Event Type Video muted
    POBVideoAdEventMute,
    
    /// Event Type Video unmuted
    POBVideoAdEventUnmute,
    
    /// Event Type Video clicked
    POBVideoAdEventClicked,
    
    /// Event Type Industry icon clicked
    POBVideoAdEventIconClicked
};


/// Error codes PubMatic SDK gives in error callback.
typedef NS_ENUM(NSInteger, POBErrorCode)  {
    
    /// Invalid ad request. e.g, missing or invalid parameters
    POBErrorInvalidRequest = 1001,
    
    /// There was no ads available to deliver for ad request.
    POBErrorNoAds,
    
    /// There was an error while retrieving the data from the network.
    POBErrorNetworkError,
    
    /// Failed to process ad request by Ad Server.
    POBErrorServerError,
    
    /// Ad request was timed out
    POBErrorTimeout,
    
    /// Internal error
    POBErrorInternalError,
    
    /// Invalid ad response. SDK does not able to parse the response received from Server.
    POBErrorInvalidResponse,
    
    /// Ad request gets cancelled.
    POBErrorRequestCancelled,
    
    /// There was some issue while rendering the creative.
    POBErrorRenderError,
    
    /// Ad server SDK sent unexpectd/delayed partner bid win response
    POBSignalingError,
    
    /// Indicates ad is expired
    POBErrorAdExpired,
    
    /// Indicates ad is already shown
    POBErrorAdAlreadyShown = 2001,
    
    /// Indicated ad is not ready to show yet
    POBErrorAdNotReady = 2002,
    
    /// Bid lost the client auction between OpenWrap  server side partners and client side partners-
    POBErrorClientSideAuctionLost = 3001,
    
    /// Bid won the auction between OpenWrap partners but lost the primary ad server's auction
    POBErrorAdServerAuctionLost,
    
    /// Bid won the auction but never used.
    POBErrorAdNotUsed,
    
    /// Indicates that partner details are not found
    POBErrorNoPartnerDetails = 4001,
    
    /// Indicates invalid reward selection
    POBErrorInvalidRewardSelected = 5001
};

/// Bid targeting type
typedef NS_ENUM(NSInteger, POBBidTargetingType) {
    
    /// By default, winning targeting will be returned. Only winning targeting i.e. without partner name suffix
    POBBidTargetingTypeWinning,
    /// Partner specific targeting i.e. with partner name suffix
    POBBidTargetingTypePartnerSpecific,
    /// Both winning and partner specific targeting i.e. with and without partner name suffix
    POBBidTargetingTypeBoth,
};

/*!
 List of supported API frameworks for this impression. If an API is not
 explicitly listed, it is assumed not to be supported.
 */
typedef NS_ENUM(NSInteger, POBAPI) {
    /// API VPAID 1.0
    POBAPI_VPAID_1_0 = 1,
    
    /// API VPAID 2.0
    POBAPI_VPAID_2_0,
    
    /// API MRAID-1
    POBAPI_MRAID_1,
    
    /// API ORMMA
    POBAPI_ORMMA,
    
    /// API MRAID-2
    POBAPI_MRAID_2,
    
    /// API MRAID-3
    POBAPI_MRAID_3,
    
    /// API OMSDK
    POBAPI_OMSDK
};

/// Gender to help deliver more relevant ads.
typedef NS_ENUM(NSInteger, POBGender) {
    
    /// Other gender
    POBGenderOther = 0,
    /// Gender male
    POBGenderMale,
    /// Gender female
    POBGenderFemale
};

/// Video ad placement type with respect to main content
typedef NS_ENUM(NSInteger, POBPlacement){
    /// In-stream video ad
    POBPlacementInStream = 1,
    /// Video ad as a Banner
    POBPlacementInBanner,
    /// Video ad in Article
    POBPlacementInArticle,
    /// Video ad in App feeds
    POBPlacementInFeed,
    /// Video ad as an Interstitial
    POBPlacementInterstitial
};

/// Expected video linearity type by Vast Player
typedef NS_ENUM(NSInteger, POBLinearity){
    
    /// Video Linearity type Any
    POBLinearityAny = 0,
    /// Video Linearity type In stream
    POBLinearityLinearInStream,
    /// Video Linearity type Overlay
    POBLinearityNonLinearOverlay
};

/*!
 Specify the bid event error
 */
typedef NS_ENUM(NSUInteger, POBBidEventErrorCode) {
    
    /**
     *  Indicates clien-side auction loss
     */
    POBBidEventErrorClientSideAuctionLoss,
    
    /**
     *  Indicates bid expiry
     */
    POBBidEventErrorAdExpiry,

    /**
     *  Other error, for custom usecases
     */
    POBBidEventErrorOther
};

/// Indicates the ad format to request/render
typedef NS_ENUM(NSInteger, POBAdType) {
    /// Banner
    POBAdTypeBanner = 0,
    /// Interstitial
    POBAdTypeInterstitial,
    /// Rewarded
    POBAdTypeRewarded
};

NSString *POBBidEventErrorString(POBBidEventErrorCode errorCode);

typedef NSInteger POBBOOL;
typedef NSString POBBidderId;

extern POBBOOL const POBBOOLYes;
extern POBBOOL const POBBOOLNo;


//! Project version number for OpenWrapSDK.
FOUNDATION_EXPORT double OpenWrapSDKVersionNumber;

//! Project version string for OpenWrapSDK.
FOUNDATION_EXPORT const unsigned char OpenWrapSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <OpenWrapSDK/PublicHeader.h>

/*!
 *  Log levels to filter logs.
 */
typedef NS_ENUM(NSUInteger, POBSDKLogLevel){
    /**
     *  No logs
     */
    POBSDKLogLevelOff       = 0,
    
    /**
     *  Error logs only
     */
    POBSDKLogLevelError,
    
    /**
     *  Error and warning logs
     */
    POBSDKLogLevelWarning,
    
    /**
     *  Error, warning and info logs
     */
    POBSDKLogLevelInfo,
    
    /**
     *  Error, warning, info and debug logs
     */
    POBSDKLogLevelDebug,
    
    /**
     *  Error, warning, info, debug and verbose logs
     */
    POBSDKLogLevelVerbose,
    
    /**
     *  All logs
     */
    POBSDKLogLevelAll,
};

/*!
Location source
*/
typedef NS_ENUM(NSInteger, POBLocSource)  {
    
    /// Location is determined from GPS
    POBLocSourceGPS = 1,
    /// Location is determined from IP address
    POBLocSourceIPAddress,
    /// Location is provided by user
    POBLocSourceUserProvided
    
};

@interface POBApplicationInfo : NSObject

/*!
 @abstract Indicates the domain of the mobile application (e.g. “mygame.foo.com”)
 */
@property(nonatomic, strong) NSString *domain;

/*!
 @abstract Valid URL of the application on App store
 
 It is mandatory to pass a valid storeURL, containing the itunes id of your app, It is very important for platform identification.
 
 Example : https://itunes.apple.com/us/app/pubmatic-sdk-app/id1175273098?mt=8
 */
@property(nonatomic, strong) NSURL *storeURL;

/*!
 @abstract Indicates whether the mobile application is a paid version or not.
 Possible values are:
 
 POBBOOLNo - Free version
 
 POBBOOLYes - Paid version
 */
@property(nonatomic, assign) POBBOOL paid;

/*!
 @abstract Comma separated list of IAB categories for the application. e.g. "IAB-1, IAB-2"
 */
@property(nonatomic, strong) NSString *categories;

/*!
 @abstract A comma-separated list of keywords giving more information about the publisher app.
 */
@property (nonatomic, strong) NSString *keywords;

@end

@interface OpenWrapSDK : NSObject


/**
 ------------------------------------------------------------------------------------
 @name Instance Methods
 ------------------------------------------------------------------------------------
 */

/*!
 @abstract Returns the OpenWrap SDK's version.
 */
+ (NSString*)version;

/*!
 @abstract Sets log level across all ad formats. Default log level is POBSDKLogLevelWarn
 @param logLevel log level to set.
 @see POBSDKLogLevel
 */
+ (void)setLogLevel:(POBSDKLogLevel)logLevel;

/*!
 
 @abstract Sets GDPR compliance, it indicates whether or not the ad request is GDPR(General Data Protection Regulation) compliant.
 @param gdprEnabled boolean value
 - YES : indicates GDPR compliant requests
 - NO : indicates that the request is not GDPR compliant
 
 By default, this parameter is omitted in the ad request, indicating Unknown.
 */
+ (void)setGDPREnabled:(BOOL)gdprEnabled;

/*!
 @abstract Sets GDPR consent string, A valid Base64 encoded consent string as per https://github.com/InteractiveAdvertisingBureau/GDPR-Transparency-and-Consent-Framework.
 @discussion The user consent string is optional, but highly recommended if the request is subject to GDPR regulations (i.e. gdpr = YES). The default sense of consent under GDPR is “opt-out” and as such, an omitted consent string in a request subject to GDPR would be interpreted as equivalent to the user fully opting out of all defined purposes for data use by all parties.
 @param gdprConsent consent string to convey user consent when GDPR regulations are in effect.
 */
+ (void)setGDPRConsent:(NSString *)gdprConsent;

/*!
 @abstract Used to enable/disable location access.
 @discussion This value decides whether the OpenWrap SDK should access device location usings Core Location APIs to serve location-based ads. When set to NO, the SDK will not attempt to access device location. When set to YES, the SDK will periodically try to fetch location efficiently.
 Note that, this only occurs if location services are enabled and the user has already authorized the use of location services for the application. The OpenWrap SDK never asks permission to use location services by itself.
 
 The default value is YES.
 
 @param allow YES/NO value
 */
+ (void)allowLocationAccess:(BOOL)allow;

/*!
 @abstract Tells OpenWrap SDK to use internal SDK browser, instead of the default device browser, for opening landing pages when the user clicks on an ad.
 By default, use of internal browser is enabled.
 @param use BOOL value that enables/disables the use of internal browser.
 */
+ (void)useInternalBrowser:(BOOL)use;

/*!
 @abstract Sets user's location and its source. It is useful in delivering geographically relevant ads.
 @discussion
 If your application is already accessing the device location, it is highly recommended to set the location coordinates inferred from the device GPS. If you are inferring location from any other source, make sure you set the appropriate location source.
 
 @see POBLocSource
 @param location User's current location
 @param source Source of user's location.
 */
+ (void)setLocation:(CLLocation *)location source:(POBLocSource)source;

/*!
 @abstract Indicates whether the visitor is COPPA-specific or not. For COPPA (Children's Online Privacy Protection Act) compliance, if the visitor's age is below 13, then such visitors should not be served targeted ads.

 @param enable boolean value

 - No : Indicates that the visitor is not COPPA-specific and can be served targeted ads.
 - Yes : Indicates that the visitor is COPPA-specific and should be served only COPPA-compliant ads.
 */
+ (void)setCoppaEnabled:(BOOL)enable;

/*!
 @abstract Enable/disable secure ad calls.
 @discussion By default, OpenWrap SDK initiates secure ad calls from an application to the ad server and delivers only secure ads. You can allow non secure ads by passing NO to this method.
 
 @param enable boolean value
 */
+ (void)setSSLEnabled:(BOOL)enable;

/*!
 @abstract Indicates whether Advertisment ID(IDFA) should be sent in the request.
 
 @param allow boolean value

 - YES : Advertising Identifier will be sent in the request.
 - NO : Advertising Identifier will be masked in the request.
 
 */
+ (void)allowAdvertisingId:(BOOL)allow;

/*!
 @abstract Indicates whether the OW SDK is allowed to access the shared AVAudioSession
 @note This method disables the audio session access only for OpenWrap SDK. You may have to use a similar provision from ad server sdk, if available, to restrict it from potentially interfering with your app's audio.
 @param allow boolean value

 - YES(Default) : SDK may access the shared AVAudioSession
 - NO : SDK should not access the shared AVAudioSession
 */
+ (void)allowAVAudioSessionAccess:(BOOL)allow;

/*!
 @abstract Sets Application information, which contains various attributes about app, such as application category, store URL, domain, etc, for more relevant ads.
 @param appInfo POBApplicationInfo object having application information
 @see POBApplicationInfo
 */
+ (void)setApplicationInfo:(POBApplicationInfo *)appInfo;

/*!
 @abstract Application information, which contains various attributes about app, such as application category, store URL, domain, etc, for more relevant ads.
 @see POBApplicationInfo
 */
@property (class, nonatomic, readonly) POBApplicationInfo *applicationInfo;

/*!
 @abstract Sets user information, such as birth year, gender, region, etc, for more relevant ads.
 @param userInfo User object having user related information
 @see POBUserInfo
 */
+ (void)setUserInfo:(POBUserInfo *)userInfo;

/*!
 @abstract User information, such as birth year, gender, region, etc, for more relevant ads.
 @see POBUserInfo
 */
@property (class, nonatomic, readonly) POBUserInfo *userInfo;

/*!
@abstract Set the CCPA compliant string, it helps publisher toward compliance with the California Consumer Privacy Act (CCPA).

@discussion For more details refer https://www.iab.com/guidelines/ccpa-framework/

Make sure that the string value you use is compliant with the IAB Specification, refer https://iabtechlab.com/wp-content/uploads/2019/11/U.S.-Privacy-String-v1.0-IAB-Tech-Lab.pdf

If this is not set, SDK looks for app's NSUserDefault with key 'IABUSPrivacy_String'
If CCPA is applied through both options, the SDK will honour only API property.
If both are not set then CCPA parameter is omitted from an ad request.
 
@param ccpaString is the CCPA compliant string
*/
+ (void)setCCPA:(NSString *)ccpaString;

/**
 @abstract Add user's raw/hashed data required by identity partners which will be passed in the ad request.
 @discussion Ususally the application fetches the user ids from identity vendors and it should be
 passed to OpenWrap SDK using this API.
 
 This external user id passed to OpenWrap SDK will persist for an app session only.
 
 @param externalUserId Instance of POBExternalUserId storing user's data received from identity vendors.
 */
+ (void)addExternalUserId:(POBExternalUserId *)externalUserId;

/**
 @abstract API to get all the added user Ids in OpenWrap SDK using API addExternalUserId.
 @return List of all the POBExternalUserId
 */
+ (NSArray <POBExternalUserId *>*)externalUserIds;

/**
 @abstract API to remove the external user id containg user's data received from identity partners,
 passed to OpenWrap SDK using addExternalUserId.
 
 @param source Source of the user id to which is to be removed.
 */
+ (void)removeExternalUserIdsWithSource:(NSString *)source;

/**
 @abstract API to remove all the external user ids containg user's data received from identity partners,
 passed to OpenWrap SDK using addExternalUserId.
*/
+ (void)removeAllExternalUserIds;

@end

@interface POBExternalUserId : NSObject

/**
 @abstract Name of the data partner
 */
@property (nonatomic, readonly) NSString *source;

/**
 @abstract Id of the pata partner
 */
@property (nonatomic, readonly) NSString *externalUserId;

/**
 @abstract Custom key-value data.
 @discussion The extension can have keys as string and values should be NSString, NSNumber, NSArray, NSDictionary etc.
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSObject *> *extension;

/**
 @abstract A non-zero value for user agent type
 @discussion Please refer the [IAB document](https://github.com/InteractiveAdvertisingBureau/AdCOM/blob/master/AdCOM%20v1.0%20FINAL.md#list_agenttypes) for more details.
 */
@property (nonatomic, assign) int atype;

/**
 @abstract Method to instantiate POBExternalUserId
 @param source Name of the data partner. It is a mandatory parameter.
 @param externalUserId Id of the pata partner. It is a mandatory parameter.
 @return Instance of POBExternalUserId
 */
- (instancetype)initWithSource:(NSString *)source
                         andId:(NSString *)externalUserId;

@end

@interface POBAdSize : NSObject
/*!
 @abstract Initializes size with a given CGSize
 @param size A CGSize to initialize POBAdSize with
 @result instance of POBAdSize
*/
- (instancetype)initWithCGSize:(CGSize)size;
/*!
 @abstract Returns a CGSize respective to this size
 @result CGSize
 */
- (CGSize)cgSize;
/*!
 @abstract Tells whether the size is CGSizeZero
 @result YES, if the size is equal to CGSizeZero.
          NO, if the size is not equal to CGSizeZero.
 */
- (BOOL)isZero;
/*
 Returns width for this size
 @result CGFloat value indicating width
 */
- (CGFloat)width;
/*
 Returns height for this size
 @result CGFloat value indicating height
 */
- (CGFloat)height;
@end

@interface POBRequest : NSObject


@property (nonatomic, assign, getter=isTestModeEnabled) BOOL testModeEnabled NS_SWIFT_NAME(testModeEnabled);
@property (nonatomic, assign) BOOL bidSummaryEnabled;

@end



@class POBAdSize;
POBAdSize *POBAdSizeMakeFromCGSize(CGSize size);
POBAdSize *POBAdSizeMake(CGFloat width, CGFloat height);

#pragma mark - PMAdSize

// Most used Banner Ad Size for both iphone and ipad
#define POBBannerAdSize320x50  POBAdSizeMake(320, 50)
#define POBBannerAdSize320x100  POBAdSizeMake(320, 100)
#define POBBannerAdSize300x250  POBAdSizeMake(300, 250)
#define POBBannerAdSize250x250  POBAdSizeMake(250, 250)

// Most used Banner Ad Size for ipad
#define POBBannerAdSize468x60  POBAdSizeMake(468, 60)
#define POBBannerAdSize768x90 POBAdSizeMake(768, 90)
#define POBBannerAdSize120x600  POBAdSizeMake(120, 600)

#endif /* OMPubMaticClass_h */
