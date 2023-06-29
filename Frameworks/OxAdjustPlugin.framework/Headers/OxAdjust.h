//
//  OxAdjust.h
//  OxAdjust
//
//  Created by Mavl_2023_100272 on 2023/6/12.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

#define OxAdjustPlugin_SDK_VERSION    @"1.0.0-202306291800"


NS_ASSUME_NONNULL_BEGIN

@protocol OxAdjustDelegate <NSObject>

- (NSDictionary<NSString *,NSString *> *)getAdjustTokens;

@end

@interface OxAdjust : NSObject

- (void)setAdjustDelegate:(id<OxAdjustDelegate>)delegate;

+ (nonnull instancetype)sharedInstance;

- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
