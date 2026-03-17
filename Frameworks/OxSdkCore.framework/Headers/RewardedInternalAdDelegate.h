//
//  RewardedInternalAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>
#import "AdInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@class AdReward;

@protocol RewardedInternalAdDelegate <NSObject, AdInternalAdDelegate>

- (void)oxUserRewarded:(AdReward *)reward ad:(nullable id)ad;

@end

NS_ASSUME_NONNULL_END
