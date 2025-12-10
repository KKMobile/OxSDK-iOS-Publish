//
//  OxAdRetryManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/11/4.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class OxAdConfigManager;

@interface OxAdRetryManager : NSObject


- (void)setConfig:(OxAdConfigManager *)adConfigManager;

- (void)retryOnLoadFailedIsMaxAd:(BOOL)isMaxAd
                    canRetryHandler:(void(^)(BOOL canRetry))canRetryHandler;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
