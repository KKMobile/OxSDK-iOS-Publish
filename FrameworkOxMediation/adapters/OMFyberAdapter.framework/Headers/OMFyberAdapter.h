// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMMediationAdapter.h"

NS_ASSUME_NONNULL_BEGIN

static NSString *  const FyberAdapterVersion = @"1.1.4";

@interface OMFyberAdapter : NSObject <OMMediationAdapter>

@property(nonatomic, strong) NSNumber *userAge;
@property(nonatomic, assign) NSInteger userGender;

+ (instancetype)sharedInstance;

+ (NSString*)adapterVerison;

+ (void)initSDKWithConfiguration:(NSDictionary *)configuration completionHandler:(OMMediationAdapterInitCompletionBlock)completionHandler;

@end

NS_ASSUME_NONNULL_END
