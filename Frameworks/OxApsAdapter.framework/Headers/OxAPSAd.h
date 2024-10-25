//
//  OxAPSAdRequest.h
//  OxApsAdapter
//
//  Created by Mavl_2023_100272 on 2024/10/25.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DTBiOSSDK/DTBiOSSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAPSAd : NSObject

- (void)initApsSdk:(NSString *)appId testMode:(BOOL)testMode completion:(nullable void (^)(NSError *error))completion;
- (void)loadApsAd:(NSString *)amazonAdSlotId adFormat:(APSAdFormat)adFormat ompletion:(nullable void (^)(BOOL success,id info)) completion;

@end

NS_ASSUME_NONNULL_END
