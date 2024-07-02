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
- (double)getDouble:(NSString *)key defaultValue:(double)defaultValue;
- (int)getInt:(NSString *)key defaultValue:(int)defaultValue;
- (BOOL)getBool:(NSString *)key defaultValue:(bool)defaultValue;

@end

NS_ASSUME_NONNULL_END
