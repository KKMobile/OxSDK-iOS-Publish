//
//  OxAdjustEventTracker.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAdjustEventTracker : NSObject

+ (instancetype)sharedInstance;

- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;
- (void)trackAdRevenue:(NSString *)mediation params:(nullable NSDictionary *)params;
- (nullable NSString *)getNetworkByAttribution;
- (nullable NSString *)getCampaignByAttribution;
- (nullable NSString *)getAdidByAttribution;

@end

NS_ASSUME_NONNULL_END
