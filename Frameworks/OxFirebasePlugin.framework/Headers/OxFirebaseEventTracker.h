//
//  OxFirebaseEventTracker.h
//  OxFirebasePlugin
//
//  Created by Mavl_2023_100272 on 2024/10/23.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxFirebaseEventTracker : NSObject

+ (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;
+ (void)setUserPropertyString:(nullable NSString *)value forName:(NSString *)name;
+ (NSString *)appInstanceID;

@end

NS_ASSUME_NONNULL_END
