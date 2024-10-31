//
//  OxFBEventLogger.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/3/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxFBEventLogger : NSObject

+ (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
