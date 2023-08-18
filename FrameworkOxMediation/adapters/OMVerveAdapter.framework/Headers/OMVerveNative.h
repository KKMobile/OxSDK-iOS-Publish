//
//  OMHyBidNative.h
//  OMVerveAdapter
//
//  Created by Mavl_2023_100272 on 2023/7/3.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMNativeCustomEvent.h"

@import HyBid;

NS_ASSUME_NONNULL_BEGIN

@interface OMVerveNative : NSObject <OMNativeCustomEvent>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, weak) id<nativeCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

- (instancetype)initWithParameter:(NSDictionary *)adParameter rootVC:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
