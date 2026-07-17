//
//  OxAdHelperPrivate.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2025/8/9.
//  Copyright © 2025 耿志向. All rights reserved.
//

#ifndef OxAdHelperPrivate_h
#define OxAdHelperPrivate_h

#import "OxAdHelper.h"
#import "ThreadSafeAdStatusManager.h"

@class OxAdEventModel;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdHelper()

@property (nonatomic, strong) NSString *mAdStatus;
@property (nonatomic, weak, readonly) UIViewController *mViewController;
@property (nonatomic, assign, readonly) NSString *mAdUnitId;
@property (nonatomic, strong, readonly) NSString *mLoadPlacement;
@property (nonatomic, strong, readonly) NSString *mAdFormat;
@property (nonatomic, strong) NSArray<NSString *> *mExploredIDs;
@property (nonatomic, strong) NSString *mExploredCacheModel;
@property (nonatomic, assign, readonly) double mRequestTimestamp;
@property (nonatomic, strong) NSString *mShowPlacement;
@property (nonatomic, assign) double mShowingTimestamp;
@property (nonatomic, assign, readonly) double mLastShowFailedTimestamp;
@property (nonatomic, assign, readonly) NSInteger mMaxRetryAttempt;
@property (nonatomic, assign) NSInteger mRetryAttempt;
@property (nonatomic, assign, readonly) long long mRequestTag;
@property (nonatomic, assign, readonly) NSInteger mCacheAdSize;
@property (nonatomic, assign ,readonly) OxAdLoadType mLoadType;
@property (nonatomic, assign) BOOL mReload;
@property (nonatomic, assign, readonly) BOOL mCloseReload;

/// 是否开启 Explored
@property (nonatomic, assign) BOOL mIsReturn;
@property (nonatomic, assign) OxAdLoadStatus mAdLoadStatus;
@property (nonatomic, assign) double mRevenue;

@property (nonatomic, strong, readonly) NSDictionary<NSString*, NSString*>* mMaxExtraParameterMap;
@property (nonatomic, strong) ThreadSafeAdStatusManager *mAdStatusManager;
@property (nonatomic, strong) NSString *mFloorAdunitId;
@property (nonatomic, copy) NSString *mPangleID;


- (instancetype)initWithCurrentVC:(UIViewController *)vc adUnitId:(NSString *)adunitId adFormat:(NSString *)adFormat;

// 设置 segment
- (void)setSegment;

- (double)getDuration:(double)latestTimestamp;

- (void)loadAdInternal:(NSString *)placement;

- (NSString *)appendLimitation:(NSString *)limitation;

- (NSInteger)findInsertPosition:(OxAd *)ad inCacheAds:(NSArray<OxAd *> *)cacheAds;

/// 处理缓存排序
/// - Parameters:
///   - ad: 要处理的 ad
///   - cacheAds: 缓存列表
- (void)addAd2Cache:(OxAd *)ad cacheAds:(NSMutableArray<OxAd *> *)cacheAds;

// 请求失败重试
- (void)reloadOnLoadFailed;
// 展示失败重试
- (void)reloadOnLoadDesplayFailed;
// 关闭重试
- (void)reloadOnAdClose;

// 计时器相关
- (void)startDelayTaskWithTimeInterval:(NSTimeInterval)delay
                              callback:(void(^)(void))callback;
- (void)stopTimeoutTimer;
- (BOOL)getIsReload;
- (BOOL)isOpenExplored;

#pragma mark - 子类实现
// 返回当前的类是否是MAX 用来判断是否进行无限重试
- (BOOL)isMaxAd;
- (BOOL)isAdmobAd;
- (BOOL)isOpenPangleBidding;
- (NSString *)getNetworkName;
- (NSString *)getCreativeId;

#pragma mark - AdEvent
- (void)onTrackAdRequest;
- (void)onTrackAdAdapterRequest;

#pragma mark - 监听相关
- (void)onUpdateRemoteConfig;

@end

NS_ASSUME_NONNULL_END



#endif /* OxAdHelperPrivate_h */
