//
//  OxExtraParameters.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2026/1/26.
//  Copyright © 2026 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxExtraParameters : NSObject

+ (instancetype)sharedInstance;

- (void)addExtraParameterMapWithValue:(NSString *)value forKey:(NSString *)key;
- (NSDictionary<NSString *,NSString *> *)getExtraParameterMap;

@end

NS_ASSUME_NONNULL_END
