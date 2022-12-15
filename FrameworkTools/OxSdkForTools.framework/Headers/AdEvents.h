//
//  AdEvents.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/14.
//

#ifndef AdEvents_h
#define AdEvents_h

#ifdef DEBUG
#define OXLog(fmt, ...) NSLog((@"OXSDK:%s " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__);
#else
#define OXLog(...)
#endif

#define OX_IS_IPAD  ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
#define OX_FACTOR_WIDTH (OX_IS_IPAD ? 1: (OX_SCREEN_WIDTH / 375.0))
#define OX_SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)

// Adformat
static NSString * const AdFormat_BANNER = @"banner";
static NSString * const AdFormat_MREC = @"mrec";
static NSString * const AdFormat_INTERSTITIAL = @"interstitial";
static NSString * const AdFormat_NATIVE = @"native";
static NSString * const AdFormat_REWARDED = @"rewarded";

static NSString * const AdStatus_IDLE = @"Ad is idle";
static NSString * const AdStatus_LOADING = @"Ad is loading";
static NSString * const AdStatus_LOAD_FAILED = @"Ad load failed";
static NSString * const AdStatus_LOAD_SUCCESS = @"Ad load success";
static NSString * const AdStatus_SHOWN = @"Ad has already shown";

typedef NS_ENUM(NSInteger, DailyLevel) {
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2
};

typedef NS_ENUM(NSInteger, CountedEvents) {
    TOP10 = 1,
    TOP20 = 2,
    TOP30 = 3,
    TOP40 = 4,
    TOP50 = 5,
    TOP60 = 6
};

// EventLevel
typedef NS_ENUM(NSInteger, EventLevel) {
    NONE = 0,
    BASIC = 1,
    SDK = 2,
    MEDIATION = 3
 };

// NetWorkState
typedef NS_ENUM(NSInteger, NetWorkState) {
    UNAVAILABLE = 0,
    AVAILABLE = 1
};

// NetWorkType
typedef NS_ENUM(NSInteger, NetWorkType) {
    UNWORK = 0,
    DATA_2G,
    DATA_3G,
    DATA_4G,
    DATA_5G,
    WIFI,
    DATA
};

//VPNState
typedef NS_ENUM(NSInteger, VPNState) {
    DISCONNECTED = 0,
    CONNECTED = 10
};

typedef NS_ENUM(NSInteger, Platform) {
    PlatForm_Max = 0,
    PlatForm_Admob
};

// Required
static NSString * const EVENT_TOP10 = @"AdLTV_OneDay_Top10Percent";
static NSString * const EVENT_TOP20 = @"AdLTV_OneDay_Top20Percent";
static NSString * const EVENT_TOP30 = @"AdLTV_OneDay_Top30Percent";
static NSString * const EVENT_TOP40 = @"AdLTV_OneDay_Top40Percent";
static NSString * const EVENT_TOP50 = @"AdLTV_OneDay_Top50Percent";
static NSString * const EVENT_TOP60 = @"AdLTV_OneDay_Top60Percent";
static NSString * const EVENT_TOTAL_ADS_REVENUE_001 = @"Total_Ads_Revenue_001";
static NSString * const EVENT_AD_IMPRESSION_REVENUE = @"Ad_Impression_Revenue";
// Basic
static NSString * const EVENT_AD_REQUEST = @"Ad_Request";
static NSString * const EVENT_AD_LOADED = @"Ad_Loaded";
static NSString * const EVENT_AD_FAILED = @"Ad_Failed";
static NSString * const EVENT_AD_SHOW = @"Ad_Show";
static NSString * const EVENT_AD_SHOWING = @"Ad_Showing";
static NSString * const EVENT_AD_IMPRESSION = @"Ad_Impression";
static NSString * const EVENT_AD_SHOW_FAILED = @"Ad_Show_Failed";
static NSString * const EVENT_AD_CLICK = @"Ad_Click";
static NSString * const EVENT_AD_GOTTEN_CREDIT = @"Ad_GottenCredit";
static NSString * const EVENT_AD_CLOSE = @"Ad_Close";
// Sdk
static NSString * const EVENT_SHOW_SDK_CONSENT_PRIVACY = @"show_sdk_consent_privacy";
static NSString * const EVENT_CLICK_SDK_CONSENT_BACK_KEY = @"click_sdk_consent_back_key";
static NSString * const EVENT_CLICK_SDK_CONSENT_SAVE_ACCEPT = @"click_sdk_consent_save_accept";
static NSString * const EVENT_CLICK_SDK_CONSENT_SAVE_REJECT = @"click_sdk_consent_save_reject";
static NSString * const EVENT_CLICK_SDK_CONSENT_MORE = @"click_sdk_consent_more";
static NSString * const EVENT_CONSENT_GDPR_YES = @"consent_gdpr_yes";
static NSString * const EVENT_CONSENT_GDPR_NO = @"consent_gdpr_no";
static NSString * const EVENT_SHOW_SDK_CONSENT_OPTION = @"show_sdk_consent_option";
// Param keys
static NSString * const PARAM_AD_UNIT_ID = @"AdUnitId";
static NSString * const PARAM_AD_FORMAT = @"AdFormat";
static NSString * const PARAM_PLACEMENT = @"Placement";
static NSString * const PARAM_VERSION = @"Version";
static NSString * const PARAM_NETWORK_TYPE = @"NetworkType";
static NSString * const PARAM_NETWORK_STATE = @"NetworkState";
static NSString * const PARAM_LOADED_DURATION = @"LoadedDuration";
static NSString * const PARAM_SIZE = @"Size";
static NSString * const PARAM_NETWORK_NAME = @"NetworkName";
static NSString * const PARAM_WATERFALL_NAME = @"WaterfallName";
static NSString * const PARAM_NETWORK_RESPONSES = @"NetworkResponses";
static NSString * const PARAM_LATENCY_MILLIS = @"LatencyMillis";
static NSString * const PARAM_CREATIVE_ID = @"CreativeId";
static NSString * const PARAM_REVENUE = @"Revenue";
static NSString * const PARAM_ERROR = @"Error";
static NSString * const PARAM_FAILED_DURATION = @"FailedDuration";
static NSString * const PARAM_SHOWING_DURATION = @"ShowingDuration";
static NSString * const PARAM_LIMITATION = @"Limitation";
// Only for Firebase ad impression
static NSString * const EVENT_FIREBASE_AD_IMPRESSION = @"ad_impression";
static NSString * const PARAM_FIREBASE_AD_PLATFORM = @"ad_platform";
static NSString * const PARAM_FIREBASE_AD_SOURCE = @"ad_source";
static NSString * const PARAM_FIREBASE_AD_FORMAT = @"ad_format";
static NSString * const PARAM_FIREBASE_AD_UIT_NAME = @"ad_unit_name";
static NSString * const PARAM_FIREBASE_CURRENCY = @"currency";
static NSString * const PARAM_FIREBASE_VALUE = @"value";



#endif /* AdEvents_h */
