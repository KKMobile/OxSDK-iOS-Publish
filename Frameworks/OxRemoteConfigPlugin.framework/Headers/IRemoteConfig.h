//
//  IRemoteConfig.h
//  Adjust
//
//  Created by Mavl_2023_100272 on 2024/7/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IRemoteConfig <NSObject>

- (NSString *)getString:(NSString *)key defaultValue:(NSString *)defaultValue;
- (NSNumber *)getDouble:(NSString *)key defaultValue:(double)defaultValue;
- (NSNumber *)getInt:(NSString *)key defaultValue:(int)defaultValue;
- (NSNumber *)getBool:(nonnull NSString *)key defaultValue:(BOOL)defaultValue;

@end

NS_ASSUME_NONNULL_END
