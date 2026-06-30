//
//  OxNativeInterUtil.h
//  OxSDK-Game
//
//  Created by BJMM100001 on 2023/3/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxNativeInterUtil : NSObject

+ (UIColor *)colorFromHexString:(NSString *)hexString;

+ (UIColor *)colorFromHexString:(NSString *)hexString alpha:(float)alpha;

+ (UIImage *)imageWithColor:(UIColor *)color;

+ (BOOL)isUS;

@end

NS_ASSUME_NONNULL_END
