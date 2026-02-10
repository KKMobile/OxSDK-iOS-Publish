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

NS_ASSUME_NONNULL_BEGIN

@class OxAd,MAAd,AdReward;

// 定义 block 类型
typedef void (^OxAdLoadSuccessBlock)(OxAd *ad);
typedef void (^OxAdLoadFailureBlock)(OxAd *ad, NSString *error);

@protocol OxAdDelegate <NSObject>

- (void)onAdapterAdLoadFailed:(nonnull OxAd *)ad error:(nonnull NSString *)error;
- (void)onAdapterAdLoaded:(nonnull OxAd *)ad;
- (void)onAdapterAdDisplayed:(OxAd *)ad;
- (void)onAdapterAdDisplayFailed:(OxAd *)ad error:(NSString *)error;
- (void)onAdapterAdClicked:(OxAd *)ad;
- (void)onAdapterAdClosed:(OxAd *)ad;

@optional
- (void)onAdapterRewardedVideoStarted:(OxAd *)ad;
- (void)onAdapterRewardedVideoCompleted:(OxAd *)ad;
- (void)onAdapterUserRewarded:(OxAd *)ad reward:(AdReward *) reward;

@end

@interface OxAd : NSObject

@property (nonatomic, weak) id<OxAdDelegate> delegate;
@property (nonatomic, copy, nullable) OxAdLoadSuccessBlock onAdLoaded;
@property (nonatomic, copy, nullable) OxAdLoadFailureBlock onAdLoadFailed;
@property (nonatomic, strong, nullable) OxMAAdRevenueDelegateImpl* oxMAAdRevenueDelegateImpl;
@property (nonatomic, strong, nullable) MAAd *mMaxAd;

@property (nonatomic, assign) NSString *mAdFormat;
@property (nonatomic, copy, readonly) NSString *mAdUnitId;
@property (nonatomic, copy, readonly) NSString *mPlacement;
@property (nonatomic, copy, readonly) NSString *mShowPlacement;
@property (nonatomic, copy) NSString *mExploredID;
@property (nonatomic, copy) NSString *mFloorPrice;
@property (nonatomic, assign, readonly) double mRevenue;

@property (nonatomic, assign, readonly) NSInteger mLayers;
@property (nonatomic, assign, readonly) double mRequestTimestamp;
@property (nonatomic, assign) double mShowingTimestamp;
@property (nonatomic, assign, readonly) BOOL mReload;
@property (nonatomic, assign) BOOL mIsLastLayers;
@property (nonatomic, assign, readonly) long long mRequestTag;
@property (nonatomic, assign, readonly) long long mTag;
@property (nonatomic, assign) float mJumpHeightPer;
@property (nonatomic, assign, readonly) double mFloorRevenue;

@property (nonatomic, strong) NSDictionary *mMaxExtraParameterMap;

@property (nonatomic, strong, nullable) dispatch_source_t delayTask;


- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                       placement:(NSString *)placement
                          layers:(NSInteger)layers
            maxExtraParameterMap:(NSDictionary *)maxExtraParameterMap
                    isLastLayers:(BOOL)isLastLayers
                          reload:(BOOL)reload
                      requestTag:(long long)requestTag
                      exploredID:(NSString *)exploredID
                   jumpHeightPer:(float)jumpHeightPer
                    floorRevenue:(double)floorRevenue;

- (void)showAd:(NSString *)placement viewController:(UIViewController *)viewController;
- (BOOL)isReady;

- (void)loadAdInternal;
- (void)loadAd;
- (void)destroyAd;

- (BOOL)isDisableID:(NSString *)disableIds;
- (double)getDuration:(double)latestTimestamp;


// 子类实现 获取当前 disableIds
- (NSString *)getRemoteDisabIds;

- (void)startDelayTask:(void(^)(void))callback;
- (void)stopTimeoutTimer;
- (void)loadTimeOut;
- (void)updateAdTag:(long long)tag;
- (void)updateFloorRevenue:(double)floorRevenue;
- (void)updateRequestTag:(double)requestTag;

@end

NS_ASSUME_NONNULL_END
