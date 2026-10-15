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

+ (NSInteger)appVersionToSegment;

/// 根据info.plist中的id组，进行adapter的初始化操作
+ (NSDictionary *)getAppIdFormInfoPlist;

+ (NSString *)getAdapterAppId:(NSString *)key;

+ (NSString *)getStringFromPlist:(NSString *)key;

+ (NSNumber *)getNumberFormPlist:(NSString *)key;

// app 内存显示
+ (double)getAppMemoryLimit;
// 应用剩余内存
+ (double)getFreeSize;
// app 已用内存
+ (double)memoryUsage;
// 可用内存
+ (double)getAvailableMemory;

// 判断 聚合是否在枚举区域内
+ (BOOL)platformInRange:(NSInteger)platform;

/// 格式化聚合
+ (NSInteger)formatPlatform:(NSInteger)platform;

+ (UIViewController *)mavlVisibleViewController;

+ (double)getDuration:(double)latestTimestamp;

+ (BOOL)isNetworkAvailable;

+ (BOOL)isDouble:(NSString *)str;
+ (BOOL)isWebViewInstalled;
+ (CGFloat)getScreenWidthInDp;

// 获取 网络类型 + Vpn 状态。
+ (NSInteger)getNetworkTypeWithVpnState;

// 获取网络连接状态。
+ (NSInteger)getNetworkState;

@end

NS_ASSUME_NONNULL_END
