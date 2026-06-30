//
//  OxFirebaseEventTracker.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxFirebaseEventTracker : NSObject

+ (instancetype)sharedInstance;

- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;
- (void)logEventWithUserProperties:(NSString *)eventName params:(nullable NSDictionary *)params;
- (void)setUserPropertyString:(nullable NSString *)value forName:(NSString *)name;
- (void)logFirebaseAdImp:(nullable NSDictionary *)params;
- (NSString *)getFirebaseId;

@end

NS_ASSUME_NONNULL_END
