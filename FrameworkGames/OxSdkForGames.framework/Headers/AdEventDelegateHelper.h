//
//  AdEventDelegateHelper.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/9/2.
//

#import <Foundation/Foundation.h>
#import "OxAdjustTokens.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdEventDelegateHelper : NSObject

+ (OxAdjustTokens *)getAdjustTokens;

/**
 * 安装应用的第 n 天，安装当天为 1。
 */
+ (int)getDayCountSinceInstall;

+ (void)onTrackEvent:(nonnull NSString *)name params:(nullable NSDictionary *)params;

+ (NSArray *)getTopValuesConfig;

@end

NS_ASSUME_NONNULL_END
