//
//  OMFirebaseUtil.h
//  OxMediation
//
//  Created by 耿志向 on 2023/4/11.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OMFirebaseUtil : NSObject

+ (void)logInitEvent:(int)eventId error:(nullable NSError *)error;
+ (void)logEvent:(NSString *)eventName parameters:(nullable NSDictionary<NSString *, id> *)parameters;

@end

NS_ASSUME_NONNULL_END
