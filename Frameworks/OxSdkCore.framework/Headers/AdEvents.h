//
//  AdEvents.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/14.
//

#ifndef AdEvents_h
#define AdEvents_h


#define OX_IS_IPAD  ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
#define OX_FACTOR_WIDTH (OX_IS_IPAD ? 1: (OX_SCREEN_WIDTH / 375.0))
#define OX_SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define USERVALUESEGMENTKEY @"120"
#define MILLISECOND_OF_ONE_MINUTE 60

// Adformat
static NSString * const AdFormat_BANNER = @"banner";
static NSString * const AdFormat_MREC = @"mrec";
static NSString * const AdFormat_INTERSTITIAL = @"interstitial";
static NSString * const AdFormat_NATIVE = @"native";
static NSString * const AdFormat_REWARDED = @"rewarded";
static NSString * const AdFormat_OPENADS = @"openads";

static NSString * const AdStatus_IDLE = @"Ad is idle";
static NSString * const AdStatus_LOADING = @"Ad is loading";
static NSString * const AdStatus_LOAD_FAILED = @"Ad load failed";
static NSString * const AdStatus_LOAD_SUCCESS = @"Ad load success";
static NSString * const AdStatus_SHOWN = @"Ad has already shown";

typedef enum : NSUInteger {
    OxAdLoadType_Normal,
    OxAdLoadType_Closed,
    OxAdLoadType_LoadFailed,
    OxAdLoadType_DesplayFailed,
} OxAdLoadType;

typedef enum : NSUInteger {
    AdUserValueErrorType_Default,
    AdUserValueErrorType_SetValue,
    AdUserValueErrorType_SetSegment,
    AdUserValueErrorType_GetSegment,
    AdUserValueErrorType_UpdateSegment
} AdUserValueErrorType;

typedef NS_ENUM(NSInteger, DailyLevel) {
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2
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
    PlatForm_Default = 0,
    PlatForm_Admob = 1,
    PlatForm_Max = 2,
    PlatForm_None = 999
};

typedef NS_ENUM(NSInteger, CountedEvents) {
    TOP10 = 1,
    TOP20 = 2,
    TOP30 = 3,
    TOP40 = 4,
    TOP50 = 5,
    TOP60 = 6
};

typedef NS_ENUM(NSInteger, OxAnalyticsProvider) {
    OxAnalyticsProviderNone = 0,
    OxAnalyticsProviderFirebase = 1 << 0, //二进制表示为 0001
    OxAnalyticsProviderAdjust = 1 << 1,   //二进制表示为 0010
    OxAnalyticsProviderFacebook = 1 << 2, //二进制表示为 0100
    OxAnalyticsProviderTA = 1 << 3        //二进制表示为 1000
};


//Basic
static NSString * const EVENT_TOP10 = @"AdLTV_OneDay_Top10Percent";
static NSString * const EVENT_TOP20 = @"AdLTV_OneDay_Top20Percent";
static NSString * const EVENT_TOP30 = @"AdLTV_OneDay_Top30Percent";
static NSString * const EVENT_TOP40 = @"AdLTV_OneDay_Top40Percent";
static NSString * const EVENT_TOP50 = @"AdLTV_OneDay_Top50Percent";
static NSString * const EVENT_TOP60 = @"AdLTV_OneDay_Top60Percent";
static NSString * const EVENT_SHOW_SDK_CONSENT_INIT = @"show_sdk_consent_init";
static NSString * const EVENT_TOTAL_ADS_REVENUE_001 = @"Total_Ads_Revenue_001";
static NSString * const EVENT_TOTAL_ADS_REVENUE_01 = @"Total_Ads_Revenue_01";
static NSString * const EVENT_AD_IMPRESSION_REVENUE = @"Ad_Impression_Revenue";
static NSString * const EVENT_AD_MEMORY_LIMITED = @"Ad_Memory_Limited";
static NSString * const EVENT_INIT_SDK = @"Init_Sdk";
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
static NSString * const EVENT_DELETE_EXPIRE_AD = @"Delete_Expire_Ad";
static NSString * const EVENT_DELETE_REPLACE_AD = @"Delete_Replace_Ad";

static NSString * const EVENT_AD_ADAPTER_REQUEST = @"Ad_Adapter_Request";
static NSString * const EVENT_AD_ADAPTER_LOADED = @"Ad_Adapter_Loaded";
static NSString * const EVENT_AD_ADAPTER_FAILED = @"Ad_Adapter_Failed";
static NSString * const EVENT_AD_ADAPTER_IMPRESSION = @"Ad_Adapter_Impression";
static NSString * const EVENT_AD_ADAPTER_SHOW_FAILED = @"Ad_Adapter_Show_Failed";
static NSString * const EVENT_AD_ADAPTER_GOTTEN_CREDIT = @"Ad_Adapter_GottenCredit";
static NSString * const EVENT_AD_ADAPTER_CLICK = @"Ad_Adapter_Click";
static NSString * const EVENT_AD_ADAPTER_CLOSE = @"Ad_Adapter_Close";
static NSString * const EVENT_LISTENER_INTERRUPT = @"Listener_Interrupt";
static NSString * const EVENT_FIREBASE_CONFIG_CHANGE = @"Ad_Firebase_Config_Change";
static NSString * const EVENT_GET_INSTALL_DAY_ERROR = @"Ad_Get_Install_Day_Error";


// uservalue event
static NSString * const EVENT_AD_USER_VALUE_ERROR = @"Ad_User_Value_Error";
static NSString * const EVENT_AD_USER_VALUE = @"Ad_User_Value";
static NSString * const EVENT_AD_USER_VALUE_SEGMENT = @"Ad_User_Value_Segment";
static NSString * const EVENT_AD_USER_VALUE_NO_SEGMENT = @"Ad_User_Value_No_Segment";
static NSString * const EVENT_AD_SET_SEGMENT = @"Ad_Set_Segment";

// Sdk
//static NSString * const EVENT_SHOW_SDK_CONSENT_PRIVACY = @"show_sdk_consent_privacy";
//static NSString * const EVENT_CLICK_SDK_CONSENT_BACK_KEY = @"click_sdk_consent_back_key";
//static NSString * const EVENT_CLICK_SDK_CONSENT_SAVE_ACCEPT = @"click_sdk_consent_save_accept";
//static NSString * const EVENT_CLICK_SDK_CONSENT_SAVE_REJECT = @"click_sdk_consent_save_reject";
//static NSString * const EVENT_CLICK_SDK_CONSENT_MORE = @"click_sdk_consent_more";
//static NSString * const EVENT_CONSENT_GDPR_YES = @"consent_gdpr_yes";
//static NSString * const EVENT_CONSENT_GDPR_NO = @"consent_gdpr_no";
//static NSString * const EVENT_SHOW_SDK_CONSENT_OPTION = @"show_sdk_consent_option";

// Param keys
static NSString * const PARAM_AD_UNIT_ID = @"AdUnitId";
static NSString * const PARAM_AD_FORMAT = @"AdFormat";
static NSString * const PARAM_PLACEMENT_ID = @"Placement_ID";
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
static NSString * const PARAM_CHANNEL = @"Channel";
static NSString * const PARAM_CAMPAIGN = @"Campaign";
static NSString * const PARAM_MEMORY_LIMIT_TYPE = @"MemoryLimitType";
static NSString * const PARAM_ATT_ACCEPTED = @"IsAttAccepted";
static NSString * const PARAM_AD_STATUS = @"ad_status";
static NSString * const PARAM_PRE_AD_ERROR_CODE = @"pre_ad_error_code";
static NSString * const PARAM_IS_LOAD_FAIL_RETRY = @"is_load_fail_retry";
static NSString * const PARAM_IS_Ready = @"is_ready";
static NSString * const PARAM_REQUEST_NUMBER = @"RequestNumber";
static NSString * const PARAM_REQUEST_TAG = @"Request_Tag";
static NSString * const PARAM_SESSION_ID = @"Session_ID";
static NSString * const PARAM_INSTALL_DAYS = @"Install_Days";
static NSString * const PARAM_AD_TAG = @"Ad_Tag";
static NSString * const PARAM_KEY_CORE_LEVEL= @"core_level";
static NSString * const PARAM_LISTENER_INTERRUPT= @"ListenerInterrupt";
static NSString * const PARAM_LISTENER_INTERRUPT_EVENT_NAME = @"event_name";
static NSString * const PARAM_INIT_SDK_DURATION = @"initSdkDuration";
static NSString * const PARAM_CACHE_SIZE = @"Cache_Size";
static NSString * const PARAM_DELETE_SIZE = @"Delete_Size";
static NSString * const PARAM_OLD_ID = @"old_id";
static NSString * const PARAM_OLD_VALUE = @"old_value";
static NSString * const PARAM_NEW_ID = @"new_id";
static NSString * const PARAM_NEW_VALUE = @"new_value";
static NSString * const PARAM_CACHE_MODEL = @"cache_model";
static NSString * const PARAM_CACHE_AD_SIZE = @"cache_ad_size";
static NSString * const PARAM_FLOOR_PRICE = @"floorPrice";
static NSString * const PARAM_JUMP_HEIGHT_PER = @"jumpHeightPer";
static NSString * const PARAM_IS_RELOAD = @"isReload";
static NSString * const PARAM_LOAD_STATUS = @"loadStatus";


static NSString * const PARAM_KEY_AD_UNIT_IDENTIFIER = @"adUnitIdentifier";
static NSString * const PARAM_KEY_ERROR = @"error";
static NSString * const PARAM_KEY_VALUE = @"value";
static NSString * const PARAM_KEY_CURRENCY = @"currency";
static NSString * const PARAM_KEY_REVENUE = @"revenue";
static NSString * const PARAM_KEY_NETWORK_NAME = @"networkName";
static NSString * const PARAM_KEY_PLACEMENT = @"placement";
static NSString * const PARAM_KEY_NETWORK_PLACEMENT = @"networkPlacement";
static NSString * const PARAM_KEY_CREATIVE_IDENTIFIER = @"creativeIdentifier";
static NSString * const PARAM_KEY_ADFORMAT = @"adformat";
static NSString * const PARAM_KEY_COUNTRY = @"country";
static NSString * const PARAM_KEY_AD_PLATFORM = @"ad_platform";
static NSString * const PARAM_KEY_PRECISION_TYPE = @"precisionType";
static NSString * const PARAM_KEY_ADNETWORK = @"adNetwork";
static NSString * const PARAM_KEY_AD_PLATFORM_ADMOB = @"AdMob";
static NSString * const PARAM_KEY_AD_PLATFORM_MAX = @"MAX";
static NSString * const PARAM_USER_REVENUE = @"Ad_User_Revenue";
static NSString * const PARAM_KEY_EVENT_TYPE = @"event_type";

// uservalue key
static NSString * const PARAM_KEY_COUNT = @"count";
static NSString * const PARAM_KEY_ORDER = @"order";
static NSString * const PARAM_KEY_FACTOR = @"factor";
static NSString * const PARAM_KEY_FUNCTION = @"function";
static NSString * const EVENT_AD_MAX_INITIALIZE = @"Ad_Max_Initialize";
static NSString * const EVENT_KEY_BEGIN_SEGMENT = @"begin_segment";
static NSString * const EVENT_KEY_SEGMENT_INITIALIZE_SUCCESS = @"segment_initialize_Success";
static NSString * const EVENT_KEY_SEGMENTED = @"isSegment";
static NSString * const PARAM_KEY_ORDER_TYPE = @"errorType";
static NSString * const PARAM_KEY_SEGMENT_KEY = @"segment_key";
static NSString * const PARAM_KEY_SEGMENT_VALUE = @"segment_value";
static NSString * const PARAM_KEY_SEGMENT = @"segment";
static NSString * const PARAM_KEY_PERIOD = @"isNewPeriod";
static NSString * const PARAM_KEY_LIST = @"list";
static NSString * const PARAM_AD_USER_VALUE_CONFIG = @"AdUserValueConfig";



static NSString * const META_KEY_CACHE_DISABLED_IDS = @"OxCacheDisabledIds";
static NSString * const META_KEY_IRONSOURCE_KEY = @"OxIronsourceKey";
static NSString * const MAX_DISABLE_CACHE_PARAM_KEY = @"disable_b2b_ad_unit_ids";
static NSString * const OX_MAX_DISABLE_AUTO_RETRIES = @"disable_auto_retries";
static NSString * const META_KEY_USERVALUE_IDS = @"OxUserValueIDs";
static NSString * const META_KEY_DEFAULT_VALUES = @"OxDefaultValues";

static NSString * const FAIL_KEY_ADSDK = @"AdSdkDiscovery";


static NSString * const AD_LOAD_ERROR_ADAPTER_REQUEST_TIMEOUT = @"Adapter request timeout";
static NSString * const AD_LOAD_ERROR_ADAPTER_REQUEST_FLOOR_TIMEOUT = @"_Floor_Timeout";
static NSString * const AD_LOAD_ERROR_AD_SHOW_RESTRICT = @"Ad Show Restrict";
static NSString * const AD_LOAD_ERROR_AD_LOAD_RESTRICT = @"Ad Load Restrict";
static NSString * const AD_LOAD_ERROR_AD_DISABLE_ID = @"Ad Disable ID";

#pragma mark - 消息通知
static NSString * const OX_MAG_NETWIRKCHANGE = @"OxNetworkChangeToReachable";
// remoteconfig 回来之后的监听，需要再更新一遍远端值，减少计算
static NSString * const OX_MAG_REMOTECONFIGCHANGE = @"OxRemoteConfigChange";

static NSString * const OX_MAX_EXTRA_PARAMETER_KEY = @"jC7Fp";

#pragma mark - GDPR
static NSString * const EVENT_ADSDK_GDPR_BEGIN_INIT = @"adsdk_gdpr_begin_init";
static NSString * const EVENT_ADSDK_GDPR_END_INIT = @"adsdk_gdpr_end_init";
static NSString * const EVENT_ADSDK_GET_ISSUBJECTTOGDPR = @"adsdk_gdpr_get_isSubjectToGDPR";
static NSString * const EVENT_ADSKD_GDPR_MAX_BEGIN_INIT = @"adsdk_gdpr_max_beigin_init";
static NSString * const EVENT_ADSKD_GDPR_MAX_INIT_SUCCESS = @"adsdk_gdpr_max_init_success";
static NSString * const EVENT_ADSKD_GDPR_GEO_CONSENT_UPDATE = @"adsdk_gdpr_geo_consent_update";
static NSString * const EVENT_ADSKD_GDPR_SHOW = @"adsdk_gdpr_show";
static NSString * const EVENT_ADSKD_GDPR_SHOWING = @"adsdk_gdpr_showing";
static NSString * const EVENT_ADSKD_GDPR_DISMISS = @"adsdk_gdpr_dismiss";
static NSString * const EVENT_ADSKD_GDPR_CMP_SHOW_PRIVACY = @"adsdk_gdpr_cmp_show_privacy";
static NSString * const EVENT_ADSKD_GDPR_CMP_SHOW_OPTION = @"adsdk_gdpr_cmp_show_option";
static NSString * const EVENT_ADSKD_GDPR_CMP_PRIVACY_ACCEPT = @"adsdk_gdpr_cmp_privacy_accept";
static NSString * const EVENT_ADSKD_GDPR_CMP_PRIVACY_MORE = @"adsdk_gdpr_cmp_privacy_more";
static NSString * const EVENT_ADSKD_GDPR_CMP_CHANGE_CONSENT_STATE = @"adsdk_gdpr_cmp_change_consent_state";
static NSString * const EVENT_ADSKD_GDPR_CMP_OPTION_BACK = @"adsdk_gdpr_cmp_option_back";
static NSString * const EVENT_ADSKD_GDPR_CMP_OPTION_SAVE = @"adsdk_gdpr_cmp_option_save";
static NSString * const EVENT_ADSKD_GDPR_EXIT = @"adsdk_gdpr_exit";


static NSString * const PARAM_GDPR_KEY_PLATFORM = @"platform";
static NSString * const PARAM_GDPR_KEY_TAG = @"tag";
static NSString * const PARAM_GDPR_KEY_ATT_STATE = @"att";
static NSString * const PARAM_GDPR_KEY_GDPR_TOOL = @"gdpr_tool";
static NSString * const PARAM_GDPR_KEY_UMP_GEO_STATE = @"ump_geo_state";
static NSString * const PARAM_GDPR_KEY_CMP_GEO_STATE = @"cmp_geo_state";
static NSString * const PARAM_GDPR_KEY_MAX_GEO_STATE = @"max_geo_state";
static NSString * const PARAM_GDPR_KEY_INIT_DURATION = @"init_duration";
static NSString * const PARAM_GDPR_KEY_IS_SUBJECT_TO_GDPR = @"isSubjectToGDPR";
static NSString * const PARAM_GDPR_KEY_FORCE = @"force";
static NSString * const PARAM_GDPR_KEY_CANSHOW = @"canShow";
static NSString * const PARAM_GDPR_KEY_ERROR = @"error";
static NSString * const PARAM_GDPR_KEY_GDPR_CONSENT_STATE = @"consent_state";
static NSString * const PARAM_GDPR_KEY_CMP_CONSENT_STATE = @"cmp_consent_state";
static NSString * const PARAM_GDPR_KEY_UMP_CONSENT_STATE = @"ump_consent_state";
static NSString * const PARAM_GDPR_KEY_CMP_INTYPE = @"cmp_in_type";

static NSString * const PARAM_GDPR_VALUE_CMP = @"cmp";
static NSString * const PARAM_GDPR_VALUE_UMP = @"ump";
#endif /* AdEvents_h */
