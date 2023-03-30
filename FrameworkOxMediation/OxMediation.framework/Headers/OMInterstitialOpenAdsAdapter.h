//
//  OMInterstitialOpenAdsAdapter.h
//  OxMediation
//
//  Created by 耿志向 on 2023/3/14.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMMediationAdapter.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMInterstitialOpenAdsAdapter : NSObject <OMMediationAdapter>

+ (void)initSDKWithConfiguration:(NSDictionary *)configuration completionHandler:(OMMediationAdapterInitCompletionBlock)completionHandler;
+ (NSString *)adapterVerison;


@end

NS_ASSUME_NONNULL_END
