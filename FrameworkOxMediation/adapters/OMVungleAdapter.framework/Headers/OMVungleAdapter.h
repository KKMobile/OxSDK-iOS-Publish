// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <UIKit/UIKit.h>
#import "OMMediationAdapter.h"

NS_ASSUME_NONNULL_BEGIN

static NSString * const VungleAdapterVersion = @"1.1.2";

@interface OMVungleAdapter : NSObject<OMMediationAdapter>

@property (nonatomic, copy, nullable) OMMediationAdapterInitCompletionBlock initBlock;

+ (NSString*)adapterVerison;

+ (void)initSDKWithConfiguration:(NSDictionary *)configuration completionHandler:(OMMediationAdapterInitCompletionBlock)completionHandler;

+ (void)setConsent:(BOOL)consent;
+ (void)setUSPrivacyLimit:(BOOL)privacyLimit;
+ (void)setUserAgeRestricted:(BOOL)restricted;

+ (void)vungleSDKDidInitialize;
+ (void)vungleSDKFailedToInitializeWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
