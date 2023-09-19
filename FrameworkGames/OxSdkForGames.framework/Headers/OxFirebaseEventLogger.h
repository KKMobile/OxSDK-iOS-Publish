//
//  OxFirebaseEventLogger.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/6/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxFirebaseEventLogger : NSObject

+ (void)logEventWithName:(nonnull NSString *)eventName params: (nullable NSDictionary<NSString*, NSObject*>*) params;

+ (void)logEventWithUserProperties:(NSString*)eventName params:(nullable NSDictionary<NSString*, NSObject*>*)params;

@end

NS_ASSUME_NONNULL_END
