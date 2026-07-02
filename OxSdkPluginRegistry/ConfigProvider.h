//
//  ConfigProvider.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ConfigProvider <NSObject>

- (NSInteger)getInt:(NSString *)key defaultValue:(NSInteger)defaultValue;
- (nullable NSString *)getString:(NSString *)key fallback:(nullable NSString *)fallback;
- (double)getDouble:(NSString *)key defaultValue:(double)defaultValue;
- (BOOL)getBool:(NSString *)key defaultValue:(BOOL)defaultValue;

@end

NS_ASSUME_NONNULL_END
