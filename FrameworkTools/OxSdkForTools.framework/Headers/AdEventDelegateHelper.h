//
//  AdEventDelegateHelper.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/9/2.
//

#import <Foundation/Foundation.h>
#import "OxAdjustTokens.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdEventDelegateHelper : NSObject

+ (OxAdjustTokens *)getAdjustTokens;

+ (void)onTrackEvent:(nonnull NSString *)name params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
