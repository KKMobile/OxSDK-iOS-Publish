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
#import "OxPlacementParams.h"
#import "OxAdParams.h"
#import "OxStrategyManager.h"
#import "OxAdConfigManager.h"

@class OxAdEventModel,OxAd,AdReward,OxAdInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol OxAdHelperProtocol <NSObject>

@required
/// 创建 OxAd
/// - Parameters:
///   - adid: 广告ID
///   - adFormat: 广告类型
///   - layers: 广告在 在队列中的编号
///   - isLastLayers: 是否是最后一个
- (OxAd *)createAdWithId:(NSString *)adid adFormat:(NSString *)adFormat layers:(NSInteger)layers isLastLayers:(BOOL)isLastLayers;

/// 返回 子类中的广告事件监听 （给客户端的）
- (id<AdDelegate>)getAdDelegate;

/// 通知客户端广告加载成功
- (void)callAdLoadSuccess;

/// 更新远端配置 处理如何生成 mAllAdUnitIDs
- (void)updateRemoteConfig;

@optional
// 子类实现成功方法  Banner 和 Mrec 不存缓存
- (void)onMeidationAdLoaded:(OxAd *)ad;


@end

@interface OxAdHelper() <OxAdHelperProtocol>

#pragma mark - APP 传入字段
@property (nonatomic, strong, readonly) NSString *mPlacementName;
@property (nonatomic, strong, readonly) NSArray<NSString *> *mAdUnitIds;
@property (nonatomic, strong, readonly) NSDictionary<NSString*, NSString*>* mMaxExtraParameterMap;
@property (nonatomic, weak, readonly) UIViewController *mViewController;

#pragma mark - 广告状态
@property (nonatomic, assign, readonly) LoadStatus mLoadStatus;
@property (nonatomic, strong) NSArray<NSString *> *mAllAdUnitIDs;
@property (nonatomic, assign,readonly) BOOL mIsAllFailed;


#pragma mark - 广告相关字段
@property (nonatomic, strong) NSString *mAdFormat;
@property (nonatomic, strong) NSMutableArray<OxAd *> *mCacheAds;
@property (nonatomic, strong) NSString *mNativeIDs;
@property (nonatomic, assign) Platform mPlatform;

@property (nonatomic, assign) BOOL mIsReloadingInLoadFailed;
@property (nonatomic, assign) BOOL mIsReloadingInDisplayFailed;
@property (nonatomic, assign) BOOL mIsReturn;

#pragma mark - firebase 配置
@property (nonatomic, assign, readonly) NSInteger mCacheAdSize;

#pragma mark - 广告位配置
@property (nonatomic, strong) OxPlacementParams *mPlacementParams;
@property (nonatomic, strong) OxAdParams *mAdEventParams;

#pragma mark - 管理类
@property (nonatomic, strong, readonly) OxAdConfigManager *mConfigManager;
@property (nonatomic, strong, readonly) OxStrategyManager *mStrategyManager;

#pragma mark - 扩展
@property (nonatomic, assign, readonly) BOOL mIsFullScreenAd;


- (instancetype)initWithCurrentVC:(UIViewController *)vc adUnitId:(NSString *)adunitId adFormat:(NSString *)adFormat;

- (void)loadAdInternalWithPlacement:(NSString *)placement loadType:(OxAdLoadType)loadType;

- (void)updateAdConfigReload:(BOOL)reload;

#pragma mark - 广告相关
// 重试
- (void)reloadAdWithLoadType:(OxAdLoadType)loadType;
// 重置超时逻辑
- (void)resetStrategy;
// 是否是 MAX 聚合
- (BOOL)isMaxAd;

#pragma mark - 广告展示
/// 展示全屏广告
/// - Parameter placement: placement
- (void)showFullScreenAd:(NSString *)placement;

- (BOOL)isReadyForCacheAd;

#pragma mark - 处理事件回调
- (void)handleAdLoaded:(OxAdParams *)adParams;
- (void)handleAdLoadFailedWithAdParams:(OxAdParams *)adParams
                             errorCode:(NSInteger)errorCode
                                  error:(NSString *)error;

- (void)handleAdDisplayed:(OxAdParams *)adParams;
- (void)handleAdDisplayFailedWithAdParams:(OxAdParams *)adParams
                                    error:(NSString *)error;

- (void)handleAdClicked:(OxAdParams *)adParams;
- (void)handleAdClosed:(OxAdParams *)adParams;
- (void)handleAdOpened:(OxAdParams *)adParams;
- (void)handleAdExpanded:(OxAdParams *)adParams;
- (void)handleAdCollapsed:(OxAdParams *)adParams;

- (void)handleRewardedVideoStarted:(OxAdParams *)adParams;
- (void)handleRewardedVideoCompleted:(OxAdParams *)adParams;
- (void)handleUserRewardedWithAdParams:(OxAdParams *)adParams reward:(AdReward *)reward;

- (void)clientInvokingShowAd:(nullable NSString *)limitation;

@end

NS_ASSUME_NONNULL_END



#endif /* OxAdHelperPrivate_h */
