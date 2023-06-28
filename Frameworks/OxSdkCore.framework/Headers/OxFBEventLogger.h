//
//  OxFBEventLogger.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2023/6/14.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxFBEventLogger : NSObject

+ (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
