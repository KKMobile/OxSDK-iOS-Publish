//
//  AdValueUtils.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/16.
//

#import <Foundation/Foundation.h>
#import "OxAdSdkManager.h"
#import "AdEventUtil.h"
NS_ASSUME_NONNULL_BEGIN

static NSString* PARAM_KEY_VALUE = @"value";
static NSString* PARAM_KEY_CURRENCY = @"currency";
static NSString* PARAM_KEY_REVENUE = @"revenue";
static NSString* PARAM_KEY_NETWORK_NAME = @"networkName";
static NSString* PARAM_KEY_AD_UNIT_IDENTIFIER = @"adUnitIdentifier";
static NSString* PARAM_KEY_PLACEMENT = @"placement";
static NSString* PARAM_KEY_NETWORK_PLACEMENT = @"networkPlacement";
static NSString* PARAM_KEY_CREATIVE_IDENTIFIER = @"creativeIdentifier";
static NSString* PARAM_KEY_ADFORMAT = @"adformat";
static NSString* PARAM_KEY_COUNTRY = @"country";
static NSString* PARAM_KEY_AD_PLATFORM = @"ad_platform";
static NSString* PARAM_KEY_PRECISION_TYPE = @"precisionType";
static NSString* PARAM_KEY_ADNETWORK = @"adNetwork";
static NSString* PARAM_KEY_CORE_LEVEL= @"core_level";
static NSString* AD_PLATFORM_ADMOB = @"AdMob";
static NSString* AD_PLATFORM_MAX = @"MAX";
static NSString* AD_PLATFORM_LEVELPLAY = @"Level_Play";

@class ISImpressionData;
@class MAAd;
@class GADAdValue;

@interface AdValueUtils : NSObject

@property (nonatomic, strong) NSArray     *firebaseConfigValues;

+ (instancetype)shared;

- (void)logMaxImpressionRevenue:(MAAd *)ad placement:(NSString *)placement;

- (void)logAdmobImpressionRevenue:(NSString *)adUnitId adFormat:(NSString *)adFormat adNetwork:(NSString *)adNetwork advalue:(GADAdValue *)advalue placement:(NSString *)placement;

- (void)logLevelPlayImpressionRevenue:(ISImpressionData *)ad;
@end

NS_ASSUME_NONNULL_END
