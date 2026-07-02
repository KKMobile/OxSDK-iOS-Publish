//
//  DiscoveryService.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DiscoveryService <NSObject>

- (void)logMaxImpressionRevenue:(nullable NSDictionary *)params;
- (void)logAdmobImpressionRevenue:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
