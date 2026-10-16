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
 *  去除字符串两端的空白字符（包括空格、制表符、换行符等）
 */
- (NSString *)trimWhitespace;

/**
 *  去除字符串中所有的空格（仅去除空格字符）
 */
- (NSString *)trimAllSpaces;

/**
 *  去除字符串中所有的空白字符（包括空格、制表符、换行符等）
 */
- (NSString *)trimAllWhitespace;


@end

NS_ASSUME_NONNULL_END
