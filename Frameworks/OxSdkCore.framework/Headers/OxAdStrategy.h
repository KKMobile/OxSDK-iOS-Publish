//
//  OxAdStrategy.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/6/5.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdEvents.h"

@protocol OxAdLoaderDelegate;
@class OxAdUnit,OxAdLoader,OxAd,AdReward;

NS_ASSUME_NONNULL_BEGIN

@protocol OxAdStrategyLoadDelegate <NSObject>

/// 获取到可用广告
- (void)onAdStrategyReceived:(NSString *)adUnitName;
- (void)onAdStrategyFinished:(NSString *)adUnitName errorType:(OxErrorType)errorType error:(nullable NSError *)error;

@end

@interface OxAdStrategy : NSObject

@property(nonatomic, copy,readonly) NSString *adUnitName;
@property(nonatomic, assign,readonly) NSInteger loadCount;
@property (nonatomic, assign) OxSdkAdFormat adFormat;


- (instancetype)initWithAdUnitName:(NSString *)adUnitName;
- (void)load:(NSInteger)count delegate:(nullable id<OxAdStrategyLoadDelegate>)delegate;
- (void)setReloadAfterFailed:(BOOL)isReloadAfterFailed;

/// 获取可用Ad  这个位置要加策略等
- (OxAd *)getAvailableAd;
- (NSInteger)fetchAd;

@end

NS_ASSUME_NONNULL_END
