//
//  OxAdOperation.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/4/23.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OxAd;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdOperationTask : NSOperation

@property(nonatomic, strong) OxAd *ad;

- (instancetype)initWithAd:(OxAd *)ad;
- (void)destoryAD;
- (void)completeOperation;

@end

NS_ASSUME_NONNULL_END
