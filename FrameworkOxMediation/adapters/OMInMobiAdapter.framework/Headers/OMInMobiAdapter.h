// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMMediationAdapter.h"
#import "OMInMobiClass.h" 

NS_ASSUME_NONNULL_BEGIN

static NSString * const InMobiAdapterVersion = @"2.0.5";

@interface OMInMobiAdapter : NSObject<OMMediationAdapter>

+ (NSString*)adapterVerison;

+ (void)initSDKWithConfiguration:(NSDictionary *)configuration completionHandler:(OMMediationAdapterInitCompletionBlock)completionHandler;

+ (void)setConsent:(BOOL)consent;
+ (void)setUserAgeRestricted:(BOOL)restricted;

@end

NS_ASSUME_NONNULL_END

