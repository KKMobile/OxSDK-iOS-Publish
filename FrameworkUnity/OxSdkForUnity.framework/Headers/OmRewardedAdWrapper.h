//
//  OmRewardedAdWrapper.h
//  OxSDK-Game
//
//  Created by BJMM100001 on 2022/11/23.
//

#import <Foundation/Foundation.h>

@import OxMediation;

NS_ASSUME_NONNULL_BEGIN

@interface OmRewardedAdWrapper : NSObject

@property (nonatomic, strong) OMRewardedVideo* ad;
@property (nonatomic, assign) long loadedTimestamp;

- (instancetype)initWithAd:(OMRewardedVideo *)ad;

- (BOOL)isAvailable;

@end

NS_ASSUME_NONNULL_END
