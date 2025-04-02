//
//  OxConstants.h
//  OxDiscoveryPlugin
//
//  Created by Mavl_2023_100272 on 2023/6/6.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

static NSString * const OXD_PARAM_KEY_VALUE = @"value";
static NSString * const OXD_PARAM_KEY_CURRENCY = @"currency";
static NSString * const OXD_PARAM_KEY_REVENUE = @"revenue";
static NSString * const OXD_PARAM_KEY_NETWORK_NAME = @"networkName";
static NSString * const OXD_PARAM_KEY_AD_UNIT_IDENTIFIER = @"adUnitIdentifier";
static NSString * const OXD_PARAM_KEY_PLACEMENT = @"placement";
static NSString * const OXD_PARAM_KEY_NETWORK_PLACEMENT = @"networkPlacement";
static NSString * const OXD_PARAM_KEY_CREATIVE_IDENTIFIER = @"creativeIdentifier";
static NSString * const OXD_PARAM_KEY_ADFORMAT = @"adformat";
static NSString * const OXD_PARAM_KEY_COUNTRY = @"country";
static NSString * const OXD_PARAM_KEY_AD_PLATFORM = @"ad_platform";
static NSString * const OXD_PARAM_KEY_PRECISION_TYPE = @"precisionType";
static NSString * const OXD_PARAM_KEY_ADNETWORK = @"adNetwork";
static NSString * const OXD_PARAM_KEY_CORE_LEVEL= @"core_level";
static NSString * const OXD_AD_PLATFORM_ADMOB = @"AdMob";
static NSString * const OXD_AD_PLATFORM_MAX = @"MAX";
static NSString * const OXD_PARAM_USER_REVENUE = @"Ad_User_Revenue";
static NSString * const OXD_PARAM_KEY_EVENT_TYPE = @"event_type";


// EVENT
static NSString * const OXD_EVENT_TOP10 = @"AdLTV_OneDay_Top10Percent";
static NSString * const OXD_EVENT_TOP20 = @"AdLTV_OneDay_Top20Percent";
static NSString * const OXD_EVENT_TOP30 = @"AdLTV_OneDay_Top30Percent";
static NSString * const OXD_EVENT_TOP40 = @"AdLTV_OneDay_Top40Percent";
static NSString * const OXD_EVENT_TOP50 = @"AdLTV_OneDay_Top50Percent";
static NSString * const OXD_EVENT_TOP60 = @"AdLTV_OneDay_Top60Percent";
static NSString * const OXD_EVENT_TOTAL_ADS_REVENUE_001 = @"Total_Ads_Revenue_001";
static NSString * const OXD_EVENT_TOTAL_ADS_REVENUE_01 = @"Total_Ads_Revenue_01";
static NSString * const OXD_EVENT_AD_IMPRESSION_REVENUE = @"Ad_Impression_Revenue";
static NSString * const OXD_EVENT_TOTAL_REVENUE = @"total_revenue";

static NSString * const OXD_CONFIG_TOP10 = @"s_ad_top10percent";
static NSString * const OXD_CONFIG_TOP20 = @"s_ad_top20percent";
static NSString * const OXD_CONFIG_TOP30 = @"s_ad_top30percent";
static NSString * const OXD_CONFIG_TOP40 = @"s_ad_top40percent";
static NSString * const OXD_CONFIG_TOP50 = @"s_ad_top50percent";
static NSString * const OXD_CONFIG_TOP60 = @"s_ad_top60percent";

// total_ads_revenue_fb 打点阈值。
static NSString * const OXD_CONFIG_ADSDK_FB_THRESHOLD = @"adsdk_fb_threshold";


static NSString  * _Nonnull OXD_DAILY_REPORT_EVENTS[] = {
    @"AdLTV_OneDay_Top10Percent",
    @"AdLTV_OneDay_Top20Percent",
    @"AdLTV_OneDay_Top30Percent",
    @"AdLTV_OneDay_Top40Percent",
    @"AdLTV_OneDay_Top50Percent",
    @"AdLTV_OneDay_Top60Percent"
};

static double OXD_DEFAULT_THRESHOLD[] = {
    0.4,
    0.3,
    0.2,
    0.1,
    0.08,
    0.05
};

NS_ASSUME_NONNULL_END
