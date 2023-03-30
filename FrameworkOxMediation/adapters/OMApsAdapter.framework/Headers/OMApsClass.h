//
//  OMAPSClass.h
//  OMAPSAdapter
//
//  Created by 耿志向 on 2022/11/15.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#ifndef OMAPSClass_h
#define OMAPSClass_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class DTBDebugProperties;
@class DTBSlotGroup;
@class DTBAdNetworkInfo;
@class DTBSlotGroup;
@class DTBAdResponse;
@class DTBAdSize;
@class DTBAdLoader;
@class DTBPricePoint;

#define BID_INFO                @"bidInfo"
#define PLACEMENT_HINT          @"pHint"
#define AMAZON_SLOTS            @"amznslots"
#define AMAZON_AD_INFO          @"amazon_ad_info"
#define EVENT_SERVER_PARAMETER  @"event_server_parameter"
#define LOAD_START_TIME         @"load_start"
#define EXPECTED_WIDTH          @"expected_width"
#define EXPECTED_HEIGHT         @"expected_height"
#define SKADNETWORK_PARAMS      @"skadn_params"
#define CLICKTRACKERS_ARRAY     @"clicktrackers"
#define IS_VIDEO                @"isVideo"

/// Sample error codes.
typedef NS_ENUM(NSInteger, DTBAdErrorCode) {
    SampleErrorCodeBadRequest,    ///< Bad request.
    SampleErrorCodeUnknown,       ///< Unknown error.
    SampleErrorCodeNetworkError,  ///< Network error.
    SampleErrorCodeNoInventory,   ///< No inventory.
};


typedef enum {
    NETWORK_ERROR = 81,
    NETWORK_TIMEOUT,
    NO_FILL,
    INTERNAL_ERROR,
    REQUEST_ERROR
} DTBAdError;

typedef enum
{
    DTBLogLevelAll   = 0,
    DTBLogLevelTrace = 10,
    DTBLogLevelDebug = 20,
    DTBLogLevelInfo  = 30,
    DTBLogLevelWarn  = 40,
    DTBLogLevelError = 50,
    DTBLogLevelFatal = 60,
    DTBLogLevelOff   = 70
} DTBLogLevel;

/* NOTE: these values have been decided based on the custom
 encoding scheme. We have chosen the following values for the
 consent status: Unknown = 1, Explicit Yes = 7, Explicit No = 0 */
typedef NS_ENUM(NSInteger, DTBConsentStatus)  {
    CONSENT_NOT_DEFINED = -1,
    UNKNOWN = 1,
    EXPLICIT_YES = 7,
    EXPLICIT_NO = 0
};

/* Same as above. These values have been decided based on the custom
 encoding protocol: Google = 1, MoPub = 2 */
typedef NS_ENUM(NSInteger, DTBCMPFlavor) {
    CMP_NOT_DEFINED = -1,
    GOOGLE_CMP = 1,
    MOPUB_CMP = 2
};

typedef enum
{
    // set as default use MoPub, then DFP
    AUTO_DETECT_MRAID,
    // set mraid version based on DFP
    DFP_MRAID,
    // set mraid version based on MOPUB
    MOPUB_MRAID,
    // ignore mraid version
    NONE_MRAID,
    // use application set MRAID version
    CUSTOM_MRAID
} DTBMRAIDPolicy;

@class DTBAdLoader;

@interface DTBAdErrorInfo : NSObject

@property DTBAdError dtbAdError;

@property DTBAdLoader * _Nullable dtbAdLoader;

-(DTBAdLoader *_Nullable) getAdLoader;

@end

NS_ASSUME_NONNULL_BEGIN

@protocol DTBAdCallback

@optional
-(void)onFailure: (DTBAdError)error;
-(void)onFailure: (DTBAdError)error
     dtbAdErrorInfo:(DTBAdErrorInfo *) dtbAdErrorInfo;
@required
- (void)onSuccess:(DTBAdResponse *)adResponse;

@end

NS_ASSUME_NONNULL_END

@interface DTBAds : NSObject

@property (nonatomic) BOOL useSecureConnection;
@property (nonatomic) BOOL testMode;
@property (nonatomic) BOOL useGeoLocation;
@property (nonatomic) DTBMRAIDPolicy mraidPolicy;
@property (nonatomic) NSArray<NSString *> *  _Nullable mraidCustomVersions;
@property (nonatomic) BOOL isReady;
@property (nonatomic) DTBDebugProperties * _Nonnull debugProperties;

// Serverless Environment Markers
@property (nonatomic) NSArray * _Nonnull serverlessMarkers;

/**
 * Use these APIs if your app is using Non-IAB GDPR Compliance (ex: AdMob, MoPub)
 */
- (void)setVendorList:(NSArray<NSNumber *> *_Nullable)vendorList;
- (void)setConsentStatus:(DTBConsentStatus)consentStatus;
- (void)setCmpFlavor:(DTBCMPFlavor)cmpFlavor;

// The client needs to call this API to determine if the consent status is unknown.
- (BOOL)isConsentStatusUnknown;

+ (DTBAds * _Nonnull)sharedInstance;

// Set the applicationId provided by the Amazon Appstore.
- (void)setAppKey:(NSString * _Nonnull)appKey;

// Set the Ad Network mediation name and it's info
- (void)setAdNetworkInfo:(DTBAdNetworkInfo *_Nullable) dtbAdNetworkInfo;

// Retrieves the appKey, if already stored, otherwise will throw an exception
- (NSString * _Nullable)appKey;

- (void)setLogLevel:(DTBLogLevel)logLevel;

+ (NSString * _Nonnull)version;

- (void)addSlotGroup:(DTBSlotGroup * _Nonnull)group;

- (DTBSlotGroup * _Nullable)slotGroupByName:(NSString * _Nullable)name;

- (BOOL)hasAdapters;

- (void)removeNonIAB;

- (void)setAPSPublisherExtendedIdFeatureEnabled:(BOOL)publisherExtendedIdFeatureEnabled;

/**
 * Use these APIs to add any custom attributes or parameters that might
 * be important for APS SDK to pick up.
 * The value type can be anything but please try to use NSString or NSDictionary for simplicity.
 */
- (void)addCustomAttribute:(NSString * _Nonnull)withKey value:(id _Nonnull)value;
- (void)removeCustomAttribute:(NSString * _Nonnull)forKey;

/*
 * Alternative method to store and retrieve the local extras.
 */
+ (NSDictionary * _Nullable)getLocalExtras:(NSString * _Nonnull)adUnitId;
+ (void)setLocalExtras:(NSString * _Nonnull)adUnitId localExtras:(NSDictionary * _Nonnull)localExtras;
+ (void)removeLocalExtras:(NSString * _Nonnull)key;
@end

#define A9_BID_ID_KEY @"amzn_b"
#define A9_HOST_KEY @"amzn_h"
#define A9_PRICE_POINTS_KEY @"amznslots"
#define A9_VID_KEY @"amzn_vid"
#define A9_SKADN_KEY @"amzn_skadn"
#define APS_VIDEO_FLAG @"isv"
#define APS_VIDEO_TYPE @"vtype"
#define APS_VIDEO_SKIP_AFTER @"skipafter"
#define APS_APP_KEY @"appkey"

@interface DTBAdLoader : NSObject

@property (nonatomic)NSString * _Nullable slotGroup;

- (void)setSizes:(DTBAdSize * _Nonnull)size,... NS_REQUIRES_NIL_TERMINATION;

- (void)setAdSizes:(NSArray * _Nonnull)adSizes;

- (void)putCustomTarget: (NSString * _Nonnull)value withKey: (NSString * _Nonnull)key;

- (void)loadAd: (id<DTBAdCallback>  _Nonnull) callback;

- (NSError * _Nullable)loadSmartBanner: (id<DTBAdCallback>  _Nonnull) callback;

- (void)setAutoRefresh;

- (void)stop;

- (void)setAutoRefresh: (int)seconds;

- (void)pauseAutorefresh;
- (void)resumeAutorefresh;

-(void) setRefreshFlag:(BOOL) flag;

@end

NS_ASSUME_NONNULL_BEGIN

@interface DTBAdResponse : NSObject

@property (nonatomic) NSString *bidId;

@property (nonatomic) BOOL isVideo;

@property NSDictionary *kvp;

@property (nullable) NSDictionary *skAdNetworkParams;

@property (nonatomic, nullable) NSArray *clickTrackersArray;

@property (nullable) DTBAdLoader *dtbAdLoader;

/** The number of seconds of video playback before a video can be skipped. If the value is zero, the video is not skippable.
 */
@property (nonatomic, assign, readonly) NSInteger videoSkipAfterDurationInSeconds;
/** This represents the video inventory type from AAX if video flag is set to true
 */
@property (nonatomic, copy, readonly) NSString *videoInventoryType;

/**
 Add a non-null price point into an internal array.
 @param pp A non-null  DTBPricePoint object to be added.
 */
- (void)addDTBPricePoint:(DTBPricePoint *)pp;

/**
 @return A nullable crid string.
 */
- (NSString * _Nullable)crid;

/**
 @return A host name string.
 */
- (NSString * _Nonnull)hostname;

/**
 @return An array of DTBAdSize objects from all DTBPricePoint objects in the internal array.
 */
- (NSArray *)adSizes;

/**
 @deprecated
 */
- (NSString * _Nullable)pricePoints:(DTBAdSize * _Nullable)adSize __deprecated;

/**
 @deprecated
 */
- (NSString * _Nullable)defaultPricePoints __deprecated;

/**
 @return A DTBAdSize of the first DTBPricePoint in the internal array.
 */
- (DTBAdSize * _Nullable)adSize;

/**
 @return A dictionary with string keys and values of custom targeting from all price points in the internal array.
 */
- (NSDictionary<NSString *, NSString *> * _Nullable)customTargeting;

/**
 @return A Mopub keyword string from the internal array of price points.
 */
- (NSString *)keywordsForMopub;

/**
 @return An ad loader object. Returns nil if the ad loader has not been previously set.
 */
-(DTBAdLoader *_Nullable)getAdLoader;


@end

@interface DTBAdResponse(Mediation)

-(NSString * _Nonnull)bidInfo;

-(NSString * _Nonnull)amznSlots;

-(DTBAdSize * _Nonnull)adSize;

-(NSDictionary * _Nonnull)mediationHints:(BOOL)isSmartBanner;

-(NSDictionary * _Nonnull)mediationHints;

-(void)setHostName:(NSString * _Nonnull)hostName;

-(void)setCrid: (NSString * _Nonnull) crid;

NS_ASSUME_NONNULL_END

@end


#endif /* OMAPSClass_h */
