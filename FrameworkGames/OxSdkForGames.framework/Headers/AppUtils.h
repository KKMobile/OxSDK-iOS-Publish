//
//  AppUtils.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppUtils : NSObject

/// 根据info.plist中的id组，进行adapter的初始化操作
- (NSDictionary *)getAppIdFormInfoPlist;

- (NSString *)getAdapterAppId:(NSString *)key;

- (NSString *)getStringFromPlist:(NSString *)key;

- (NSNumber *)getNumberFormPlist:(NSString *)key;

/// 网络是否可用
+ (BOOL)isNetworkAvailable;
// app 内存显示
+ (double)getAppMemoryLimit;
// 应用剩余内存
+ (double)getFreeSize;
// app 已用内存
+ (double)memoryUsage;
// 可用内存
+ (double)getAvailableMemory;

+ (UIViewController *)mavlVisibleViewController;

/// 是否是大于 iOS 13  包含 iOS13
+ (BOOL)isGreateriOS13;

@end

NS_ASSUME_NONNULL_END
