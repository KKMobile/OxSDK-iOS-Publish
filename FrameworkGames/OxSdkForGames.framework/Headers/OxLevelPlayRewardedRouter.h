//
//  OxLevelPlayRewardedRouter.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2023/8/18.
//

#import <Foundation/Foundation.h>
#import "OxLevelPlayAdapterDelegate.h"

@import IronSource;

NS_ASSUME_NONNULL_BEGIN


@interface OxLevelPlayRewardedRouter : NSObject<LevelPlayRewardedVideoManualDelegate>

@property (nonatomic, strong) NSPointerArray *levelPlayDelegates;

+ (instancetype)sharedInstance;
- (void)registerLevelPlayRewarded;
- (void)addDelegate:(id<OxLevelPlayAdapterDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
