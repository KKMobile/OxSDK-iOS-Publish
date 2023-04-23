// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMMediationAdapter.h"

static NSString * const FacebookAdapterVersion = @"1.1.2";

@interface OMFacebookAdapter : NSObject<OMMediationAdapter>

+ (NSString*)adapterVerison;
+ (void)initSDKWithConfiguration:(NSDictionary *)configuration completionHandler:(OMMediationAdapterInitCompletionBlock)completionHandler;
+ (void)setUSPrivacyLimit:(BOOL)privacyLimit;
+(void)setUserAgeRestricted:(BOOL)restricted;
@end
