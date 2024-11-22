//
//  OxFirebaseEventLogger.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/6/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxFirebaseEventLogger : NSObject

+ (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

+ (void)trackEventWithUserProperties:(NSString*)eventName params:(nullable NSDictionary<NSString*, NSObject*>*)params;

+ (void)setUserPropertyString:(nullable NSString *)value forName:(NSString *)name;

+ (NSString *)appInstanceID;

@end

NS_ASSUME_NONNULL_END
