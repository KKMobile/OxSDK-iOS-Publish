//
//  ThreadSafeAdStatusManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/12/5.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    OxAdLoadStatus_IDLE = 0,
    OxAdLoadStatus_RUNNING = 1,
    OxAdLoadStatus_SUCCESS = 2,
    OxAdLoadStatus_SHOW = 3,
    OxAdLoadStatus_SHOWING = 4
} OxAdLoadStatus;

@class OxAd;


@interface ThreadSafeAdStatusManager : NSObject

- (instancetype)initWithAdFormat:(NSString *)adFormat;

//#pragma mark - 公共接口
//- (void)updateLoadStateWithAdUnitID:(NSString *)adUnitID loadState:(OxAdLoadStatus)loadState;
//- (OxAdLoadStatus)getAdState:(NSString *)adUnitId;
//
//#pragma mark - AdUnit 状态逻辑
//- (void)initializeAdUnitStates:(NSArray<NSString *> *)adUnitIds;
//
//// 获取所有可请求的广告ID
//- (NSArray<NSString *> *)getIdleAdUnitIds;
//
//// 判断是否请求结束
//- (BOOL)isAllIdle;


- (OxAd *)getAd:(NSString *)adUnitId;

- (void)putAd:(OxAd *)ad adunitId:(NSString *)adunitId;

- (NSDictionary<NSString *, NSNumber *> *)currentStateSnapshot;

- (void)clearAllData;

@end

NS_ASSUME_NONNULL_END
