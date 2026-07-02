//
//  FacebookEventService.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FacebookEventService <NSObject>

- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
