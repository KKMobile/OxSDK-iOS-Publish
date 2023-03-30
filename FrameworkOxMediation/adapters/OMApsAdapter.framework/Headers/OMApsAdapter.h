//
//  OMApsAdapter.h
//  OMApsAdapter
//
//  Created by 耿志向 on 2022/11/15.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMMediationAdapter.h"

NS_ASSUME_NONNULL_BEGIN

static NSString * const ApsAdapterVersion = @"1.0.0";

@interface OMApsAdapter : NSObject<OMMediationAdapter>
+ (NSString*)adapterVerison;
+ (void)initSDKWithConfiguration:(NSDictionary *)configuration completionHandler:(OMMediationAdapterInitCompletionBlock)completionHandler;
@end

NS_ASSUME_NONNULL_END
