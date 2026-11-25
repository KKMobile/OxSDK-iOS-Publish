//
//  OxAdjustEventLogger.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^OxAdjustAttributionChangedHandler)(NSString * _Nullable channel, NSString * _Nullable campaign);

@interface OxAdjustEventLogger : NSObject

+ (instancetype)sharedInstance;

- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;
- (void)trackAdRevenue:(NSString *)mediation params:(nullable NSDictionary *)params;
- (nullable NSString *)getNetworkByAttribution;
- (nullable NSString *)getCampaignByAttribution;
- (nullable NSString *)getAdidByAttribution;
- (void)setAttributionChangedHandler:(OxAdjustAttributionChangedHandler _Nullable)handler;

@end

NS_ASSUME_NONNULL_END
