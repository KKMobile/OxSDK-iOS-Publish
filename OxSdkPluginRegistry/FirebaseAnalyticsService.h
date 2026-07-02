//
//  FirebaseAnalyticsService.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FirebaseAnalyticsService <NSObject>

- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;
- (void)setUserProperty:(nullable NSString *)key value:(nullable NSString *)value;
- (void)logFirebaseAdImp:(nullable NSDictionary *)params;
- (NSString *)getFirebaseId;

@end

NS_ASSUME_NONNULL_END
