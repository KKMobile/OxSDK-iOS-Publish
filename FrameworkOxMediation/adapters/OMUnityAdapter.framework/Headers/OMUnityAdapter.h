// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMMediationAdapter.h"
#import <UnityAds/UnityAds.h>

NS_ASSUME_NONNULL_BEGIN

static NSString * const UnityAdapterVersion = @"1.1.4";

@interface OMUnityAdapter : NSObject<OMMediationAdapter,UnityAdsInitializationDelegate>
@property (nonatomic, copy, nullable) OMMediationAdapterInitCompletionBlock initBlock;

+ (NSString*)adapterVerison;
+ (void)initSDKWithConfiguration:(NSDictionary *)configuration completionHandler:(OMMediationAdapterInitCompletionBlock)completionHandler;
+ (void)setConsent:(BOOL)consent;
+ (void)setUSPrivacyLimit:(BOOL)privacyLimit;
+ (void)setUserAgeRestricted:(BOOL)restricted;
@end

NS_ASSUME_NONNULL_END