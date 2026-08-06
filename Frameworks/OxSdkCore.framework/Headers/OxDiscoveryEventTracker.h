//
//  OxDiscoveryEventTracker.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxDiscoveryEventTracker : NSObject

+ (instancetype)sharedInstance;

- (void)logMaxImpressionRevenue:(nullable NSDictionary *)params;
- (void)logAdmobImpressionRevenue:(nullable NSDictionary *)params;
- (void)handlerEventValue:(NSString *)eventName params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
