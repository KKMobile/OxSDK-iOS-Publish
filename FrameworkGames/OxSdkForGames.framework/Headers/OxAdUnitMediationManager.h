//
//  OxAdUnitMediationManager.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/3/11.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdUnitMediationManager : NSObject

+ (nonnull instancetype)sharedInstance;

/// 获取广告位聚合
- (Platform)getMediationWithAdUnitName:(NSString *)adUnitName;


@end

NS_ASSUME_NONNULL_END
