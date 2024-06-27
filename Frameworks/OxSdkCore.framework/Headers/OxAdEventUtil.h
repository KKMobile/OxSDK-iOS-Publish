//
//  OxAdEventUtil.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/6/1.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OxAdUnit;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdEventUtil : NSObject

+ (void)trackAdRequestEvent:(OxAdUnit *)adUnit error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
