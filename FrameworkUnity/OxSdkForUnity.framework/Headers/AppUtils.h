//
//  AppUtils.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppUtils : NSObject

/// 根据info.plist中的id组，进行adapter的初始化操作
- (NSDictionary *)getAppIdFormInfoPlist;

- (NSString *)getAdapterAppId:(NSString *)key;

- (BOOL)getAdpterAppEnvironment:(NSString *)key;

- (NSString *)getStringFromPlist:(NSString *)key;

- (NSNumber *)getNumberFormPlist:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
