// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMMediationAdapter.h"
#import "OMMaxClass.h"

NS_ASSUME_NONNULL_BEGIN

static NSString * const MaxAdapterVersion = @"1.0.0";

@interface OMMaxAdapter : NSObject<OMMediationAdapter>
+ (NSString*)adapterVerison;
+ (void)initSDKWithConfiguration:(NSDictionary *)configuration completionHandler:(OMMediationAdapterInitCompletionBlock)completionHandler;
+ (UIWindow *)currentWindow;
+ (void)setConsent:(BOOL)consent;
+ (void)setUSPrivacyLimit:(BOOL)privacyLimit;
+ (void)setUserAgeRestricted:(BOOL)restricted;
@end

NS_ASSUME_NONNULL_END