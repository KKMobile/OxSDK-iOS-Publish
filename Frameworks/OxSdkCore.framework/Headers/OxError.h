//
//  OxError.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/5/31.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSInteger {
    OxErrorCodeDefault = 0, //没有错误
    OxErrorCodeNotFoundAdapter = -1000001, //not found adapter
    OxErrorCodeAdLoaderIsLoading = -1000002, // ad loader is loading
    OxErrorCodeAdEnough = -1000003, // ad enough
    OxErrorCodeInvalidLoadParameter = -1000004, // ad loader is loading
    OxErrorCodeNoAd = -1000005, // no ad
    OxErrorCodeAdNotReady = -1000006, // ad not ready
    OxErrorCodeAdMemoryLimitReached = -1000007, // ad memory limit reached
//    OxErrorCodeNoInitialed = -1001,// SDK 没有初始化
//    OxErrorCodeAdLoaderTimeout = -1002,  // 广告 AdLoader 超时
//    OxErrorCodeNotFoundPlacement = -1004,// 找不到 placement
//    OxErrorCodeNotUnknowError = -1099,
} OxErrorCode;

NS_ASSUME_NONNULL_BEGIN

@interface OxError : NSObject

+ (NSString *)errorMessage:(OxErrorCode)code;
+ (NSError *)errorWithDomain:(NSString *)domain code:(OxErrorCode)code;

@end

NS_ASSUME_NONNULL_END
