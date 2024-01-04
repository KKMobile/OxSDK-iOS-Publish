// Copyright 2020 ADTIMING TECHNOLOGY COxPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OxLevelPlayAdapterDelegate.h"

@import IronSource;

NS_ASSUME_NONNULL_BEGIN

@interface OxLevelPlayInterstitalRouter : NSObject<LevelPlayInterstitialDelegate>

@property (nonatomic, strong) NSPointerArray *levelPlayDelegates;

+ (instancetype)sharedInstance;
- (void)addDelegate:(id<OxLevelPlayAdapterDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
