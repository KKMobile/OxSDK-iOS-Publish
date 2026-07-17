//
//  OxUserValueUtil.h
//  Adjust
//
//  Created by Mavl_2023_100272 on 2025/1/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxUserValueUtil : NSObject

+ (NSArray<NSNumber *> *)stringToFloatArray:(NSString *)input delimiter:(NSString *)delimiter;
+ (NSArray<NSNumber *> *)convertToIntArray:(NSString *)periods;

+ (NSInteger)findTarget:(NSArray<NSNumber *> *)nums target:(NSNumber *)target;
+ (NSInteger)findInsertOrPosition:(NSArray<NSNumber *> *)nums target:(NSNumber *)target;

+ (NSInteger)calculateDaysBetween:(NSTimeInterval)startTimeMillis currentTime:(NSTimeInterval)currentTime;

+ (float)floatDivisionNumerator:(float)numerator denominator:(NSInteger)denominator;

+ (BOOL)canBeConvertedToFloat:(NSString *)str;
+ (float)floatFormatting:(float)value;

@end

NS_ASSUME_NONNULL_END
