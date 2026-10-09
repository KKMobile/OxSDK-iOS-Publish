//
//  OxAdmobExtrasRequtst.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/5/10.
//

#import <Foundation/Foundation.h>

@class GADRequest;
@class IdConfig, OxPlacementParams;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdmobExtrasRequtst : NSObject

+ (GADRequest *)request;
+ (GADRequest *)requestWithIdConfig:(nullable IdConfig *)idConfig
                     placementParams:(nullable OxPlacementParams *)placementParams
                              logTag:(NSString *)logTag
                              adType:(NSString *)adType;

@end

NS_ASSUME_NONNULL_END
