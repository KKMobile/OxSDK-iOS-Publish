//
//  NSString+OxCategory.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/8/9.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (OxCategory)

/**
 *  去除字符串中所有的空格（仅去除空格字符）
 */
- (NSString *)trimAllSpaces;

/// 限制字符串长度为99 超过99 打点的时候上报会有问题
- (NSString *)limitTo99Chars;



@end

NS_ASSUME_NONNULL_END
