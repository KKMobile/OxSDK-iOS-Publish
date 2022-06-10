//
//  OxUnityConstants.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/18.
//

#ifndef OxUnityConstants_h
#define OxUnityConstants_h

static NSString * const CALLBACK_CLASS_NAME = @"OxSdkCallbacks";
static NSString * const CALLBACK_METHOD_NAME = @"OnOxCallback";

static NSString * const CALLBACK_PROPS_TYPE = @"type";
static NSString * const CALLBACK_PROPS_AD_EVENT_KEY = @"ad_event_key";
static NSString * const CALLBACK_PROPS_AD_EVENT_PARAMS = @"ad_event_params";
static NSString * const CALLBACK_PROPS_AD_ID = @"ad_id";
static NSString * const CALLBACK_PROPS_ERROR = @"error";
static NSString * const CALLBACK_PROPS_REWARD_LABEL = @"reward_label";
static NSString * const CALLBACK_PROPS_REWARD_AMOUNT = @"reward_amount";

static NSString * const CALLBACK_TYPE_SDK_INITIALIZED = @"OnSdkInitializedCallback";
static NSString * const CALLBACK_TYPE_AD_EVENT = @"OnAdEventCallback";
// Interstitial
static NSString * const CALLBACK_TYPE_INTERSTITIAL_LOADED = @"OnInterstitialLoadedCallback";
static NSString * const CALLBACK_TYPE_INTERSTITIAL_LOAD_FAILED = @"OnInterstitialLoadFailedCallback";
static NSString * const CALLBACK_TYPE_INTERSTITIAL_DISPLAYED = @"OnInterstitialDisplayedCallback";
static NSString * const CALLBACK_TYPE_INTERSTITIAL_DISPLAY_FAILED = @"OnInterstitialDisplayFailedCallback";
static NSString * const CALLBACK_TYPE_INTERSTITIAL_CLICKED = @"OnInterstitialClickedCallback";
static NSString * const CALLBACK_TYPE_INTERSTITIAL_OPENED = @"OnInterstitialOpenedCallback";
static NSString * const CALLBACK_TYPE_INTERSTITIAL_CLOSED = @"OnInterstitialClosedCallback";
// Reward
static NSString * const CALLBACK_TYPE_RV_LOADED = @"OnRvLoadedCallback";
static NSString * const CALLBACK_TYPE_RV_LOAD_FAILED = @"OnRvLoadFailedCallback";
static NSString * const CALLBACK_TYPE_RV_DISPLAYED = @"OnRvDisplayedCallback";
static NSString * const CALLBACK_TYPE_RV_DISPLAY_FAILED = @"OnRvDisplayFailedCallback";
static NSString * const CALLBACK_TYPE_RV_CLICKED = @"OnRvClickedCallback";
static NSString * const CALLBACK_TYPE_RV_OPENED = @"OnRvOpenedCallback";
static NSString * const CALLBACK_TYPE_RV_CLOSED = @"OnRvClosedCallback";
static NSString * const CALLBACK_TYPE_RV_STARTED = @"OnRvStartedCallback";
static NSString * const CALLBACK_TYPE_RV_COMPLETED = @"OnRvCompletedCallback";
static NSString * const CALLBACK_TYPE_RV_REWARDED = @"OnRvRewardedCallback";
// Banner
static NSString * const CALLBACK_TYPE_BANNER_LOADED = @"OnBannerLoadedCallback";
static NSString * const CALLBACK_TYPE_BANNER_LOAD_FAILED = @"OnBannerLoadFailedCallback";
static NSString * const CALLBACK_TYPE_BANNER_DISPLAYED = @"OnBannerDisplayedCallback";
static NSString * const CALLBACK_TYPE_BANNER_DiSPLAY_FAILED = @"OnBannerDisplayFailedCallback";
static NSString * const CALLBACK_TYPE_BANNER_CLICKED = @"OnBannerClickedCallback";
static NSString * const CALLBACK_TYPE_BANNER_OPENED = @"OnBannerOpenedCallback";
static NSString * const CALLBACK_TYPE_BANNER_CLOSED = @"OnBannerClosedCallback";
static NSString * const CALLBACK_TYPE_BANNER_EXPANDED = @"OnBannerExpandedCallback";
static NSString * const CALLBACK_TYPE_BANNER_COLLAPSED = @"OnBannerCollapsedCallback";
// Mrec
static NSString * const CALLBACK_TYPE_M_REC_LOADED = @"OnMRecLoadedCallback";
static NSString * const CALLBACK_TYPE_M_REC_LOAD_FAILED = @"OnMRecLoadFailedCallback";
static NSString * const CALLBACK_TYPE_M_REC_DISPLAYED = @"OnMRecDisplayedCallback";
static NSString * const CALLBACK_TYPE_M_REC_DiSPLAY_FAILED = @"OnMRecDisplayFailedCallback";
static NSString * const CALLBACK_TYPE_M_REC_CLICKED = @"OnMRecClickedCallback";
static NSString * const CALLBACK_TYPE_M_REC_OPENED = @"OnMRecOpenedCallback";
static NSString * const CALLBACK_TYPE_M_REC_CLOSED = @"OnMRecClosedCallback";
static NSString * const CALLBACK_TYPE_M_REC_EXPANDED = @"OnMRecExpandedCallback";
static NSString * const CALLBACK_TYPE_M_REC_COLLAPSED = @"OnMRecCollapsedCallback";
//GDPR
static NSString * const CALLBACK_TYPE_GDPR_ACCEPT = @"OnGdprAccept";
static NSString * const CALLBACK_TYPE_GDPR_REJECT = @"OnGdprReject";
static NSString * const CALLBACK_TYPE_GDPR_UNSET = @"OnGdprUnset";


#endif /* OxUnityConstants_h */
