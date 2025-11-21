//
//  OxAdInfo.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/7/28.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdInfo : NSObject

@property(nonatomic, strong) NSString *adFormat;
@property(nonatomic, strong) NSString *adUnitId;

@end

NS_ASSUME_NONNULL_END
