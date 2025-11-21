//
//  OxTaskController.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/9/30.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OxAd;

NS_ASSUME_NONNULL_BEGIN

@protocol OxTaskControllerDelegate <NSObject>
- (void)onSuccess:(OxAd *)ad;
- (void)onFailure:(OxAd *)ad error:(nullable NSString *)error;
- (void)onAllTasksFinished:(OxAd *)ad;
@end

/// 任务控制器
@interface OxTaskController : NSObject

@property (nonatomic, strong) NSOperationQueue *mOperationQueue;

- (instancetype)initWithMaxConcurrent:(NSInteger)maxConcurrent delegate:(id<OxTaskControllerDelegate>)delegate;
- (void)updateMaxConcurrentOperationCount:(NSInteger)maxConcurrentOperationCount;
- (void)addTasks:(NSArray<OxAd *> *)ads;

NS_ASSUME_NONNULL_END

@end
