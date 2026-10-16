//
//  OxAdCacheModel.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/10/9.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 广告缓存模式，High：保留高价，New：保留最新
typedef NSString *OxAdCacheModel NS_STRING_ENUM;

FOUNDATION_EXPORT OxAdCacheModel const OxAdCacheModelNew;
FOUNDATION_EXPORT OxAdCacheModel const OxAdCacheModelHigh;

NS_ASSUME_NONNULL_END
