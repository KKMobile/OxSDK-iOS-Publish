//
//  OxLevelPlayBannerRouter.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2023/8/21.
//

#import <Foundation/Foundation.h>
#import "OxLevelPlayAdapterDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxLevelPlayBannerRouter : NSObject<LevelPlayBannerDelegate>

@property (nonatomic, strong) NSPointerArray *levelPlayDelegates;

+ (instancetype)sharedInstance;
- (void)addDelegate:(id<OxLevelPlayBannerAdapterDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
