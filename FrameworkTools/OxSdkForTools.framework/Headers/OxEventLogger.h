//
//  OxEventLogger.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/6/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxEventLogger : NSObject

+ (void)logEventWithName:(nonnull NSString *)eventName;

+ (void)logEventWithName:(nonnull NSString *)eventName params: (nullable NSDictionary<NSString*, NSObject*>*) params;

+ (void)logFacebookEventWithName:(NSString*)eventName params:(nullable NSDictionary<NSString*, NSObject*>*)params;

@end

NS_ASSUME_NONNULL_END
