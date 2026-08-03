//
//  OxAdConfigTracker.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAdConfigTracker : NSObject

+ (instancetype)sharedInstance;

- (NSInteger)getInt:(NSString *)key defaultValue:(NSInteger)defaultValue;
- (NSString *)getString:(NSString *)key fallback:(nullable NSString *)fallback;
- (double)getDouble:(NSString *)key defaultValue:(double)defaultValue;
- (BOOL)getBool:(NSString *)key defaultValue:(BOOL)defaultValue;

@end

NS_ASSUME_NONNULL_END
