//
//  OxClassLoader.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/5/31.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OxAdUnit.h"

@class BaseAdManager;
@class OxAdAdapter;

NS_ASSUME_NONNULL_BEGIN

@interface OxClassLoader : NSObject

+ (NSString *)adapterClass:(OxAdUnit *)adUnit;

+ (NSString *)formatName:(OxSdkAdFormat)format;

+ (NSString *)mediationName:(OxSdkMediationType)mediation;

+ (NSString *)adapterAdClass:(OxAdUnit *)adUnit;

@end

NS_ASSUME_NONNULL_END
