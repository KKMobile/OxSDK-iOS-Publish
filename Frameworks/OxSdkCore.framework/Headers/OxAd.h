//
//  OxAd.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/4/3.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OxMAAdRevenueDelegateImpl.h"
#import "OXLogMoudle.h"
#import "AdEvents.h"
#import "OxRemoteConfigHelper.h"
#import "OxPlacementParams.h"

NS_ASSUME_NONNULL_BEGIN

@class OxAd,MAAd,AdReward,OxAdParams;

// 定义 block 类型  回传给task 用来处理任务结束等
typedef void (^OxAdLoadSuccessBlock)(OxAd *ad);
typedef void (^OxAdLoadFailureBlock)(OxAd *ad,NSInteger errorCode,NSString *error);

@protocol OxAdDelegate <NSObject>

- (void)onMeidationAdLoaded:(OxAd *)ad;
- (void)onMeidationAdLoadFailed:(OxAd *)ad errorCode:(NSInteger)errorCode error:(NSString *)error;
- (void)onMeidationAdDisplayed:(OxAd *)ad;
- (void)onMeidationAdDisplayFailed:(OxAd *)ad error:(NSString *)error;
- (void)onMeidationAdClicked:(OxAd *)ad;
- (void)onMeidationAdClosed:(OxAd *)ad;

@optional
- (void)onMeidationRewardedVideoStarted:(OxAd *)ad;
- (void)onMeidationRewardedVideoCompleted:(OxAd *)ad;
- (void)onMeidationUserRewarded:(OxAd *)ad reward:(AdReward *) reward;

@end

@interface OxAd : NSObject

@property (nonatomic, weak) id<OxAdDelegate> delegate;
@property (nonatomic, copy, nullable) OxAdLoadSuccessBlock onAdLoaded;
@property (nonatomic, copy, nullable) OxAdLoadFailureBlock onAdLoadFailed;
@property (nonatomic, strong, nullable) OxMAAdRevenueDelegateImpl* oxMAAdRevenueDelegateImpl;
@property (nonatomic, strong, nullable) MAAd *mMaxAd;
@property (nonatomic, weak, nullable, readonly) UIViewController *mRootViewController;

@property (nonatomic, strong) OxAdParams *mAdEventParams;
@property (nonatomic, strong) OxPlacementParams *mPlacementParams;
@property (nonatomic, assign, readonly) double mRevenue;
@property (nonatomic, assign, readonly) BOOL mReload;
@property (nonatomic, assign, readonly) BOOL mIsLastLayers;

@property (nonatomic, assign, readonly) OxAdLoadType loadType;

@property (nonatomic, assign, readonly) int timeoutTime;

@property (nonatomic, strong,readonly) NSDictionary *mMaxExtraParameterMap;

@property (nonatomic, strong, nullable) dispatch_source_t delayTask;


- (instancetype)initWithPlacementParmas:(OxPlacementParams *)placementParams
                                   adId:(NSString *)adId
                                 layers:(NSInteger)layers
                           isLastLayers:(BOOL)isLastLayers
                                 reload:(BOOL)reload
                         viewController:(UIViewController *)viewController;


- (void)showAd:(NSString *)placement;
- (BOOL)isReady;

- (void)loadAdInternal;
- (void)startLoad;
- (void)destroyAd;
- (void)reloadAd:(OxAdLoadType)loadType;

- (BOOL)isDisableID:(NSString *)disableIds;

// 子类实现 获取当前 disableIds
- (NSString *)getRemoteDisabIds;

#pragma mark - 统一操作
// 广告通用回调处理
- (void)handleAdLoaded:(id)ad;
- (void)handleAdLoadFailed:(NSInteger)errorCode error:(NSString *)error;
- (void)handleAdDisplayed;
- (void)handleAdDisplayFailed:(NSString *)error;
- (void)handleAdClicked;
- (void)handleAdClosed;

// RV 回调处理
- (void)handleUserRewardedWithLabel:(NSString *)label amount:(NSInteger)amount;
- (void)handleRewardedVideoStarted;
- (void)handleRewardedVideoCompleted;

// ✅ APS 事件追踪
- (void)trackApsRequest;
- (void)trackApsLoadSuccess;
- (void)trackApsLoadFailed:(NSString *)error;

#pragma mark - 计时器相关
- (void)startDelayTaskWithTimeInterval:(NSTimeInterval)delay
                              callback:(void(^)(void))callback;
- (void)stopTimeoutTimer;
- (void)loadTimeOut;
- (BOOL)getIsOpenTimeout;

- (NSInteger)getLayers;
- (NSString *)getPlacement;
- (NSString *)getAdUnitId;
- (NSString *)getAdFormat;
- (void)setAdTag:(long)tag;
- (void)updateMaxExtraParameterMap:(NSDictionary *)mMaxExtraParameterMap;

@end

NS_ASSUME_NONNULL_END
