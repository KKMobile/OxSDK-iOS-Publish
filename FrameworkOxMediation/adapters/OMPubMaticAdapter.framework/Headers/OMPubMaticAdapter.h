//
//  OMPubMaticAdapter.h
//  OMPubMaticAdapter
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMMediationAdapter.h"

NS_ASSUME_NONNULL_BEGIN

static NSString * const PubMaticAdapter = @"1.1.4";

@interface OMPubMaticAdapter : NSObject<OMMediationAdapter>

+ (NSString*)adapterVerison;

+ (void)initSDKWithConfiguration:(NSDictionary *)configuration completionHandler:(OMMediationAdapterInitCompletionBlock)completionHandler;
@end

NS_ASSUME_NONNULL_END
