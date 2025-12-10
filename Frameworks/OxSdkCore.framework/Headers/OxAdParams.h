//
//  OxAdParams.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/10/31.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAdParams : NSObject

// create
@property (nonatomic, copy, nullable) NSString *mAdUnitID;
@property (nonatomic, copy, nullable) NSString *mPlacement;
@property (nonatomic, copy, nullable) NSString *mAdFormat;
@property (nonatomic, assign) NSInteger mLayers;
@property (nonatomic, assign) long mRequestTag;

// loading
@property (nonatomic, assign) long mAdRequestTimestamp;
@property (nonatomic, assign) long mApsRequestTimestamp;
@property (nonatomic, copy, nullable) NSString *mApsLoadStatus;
@property (nonatomic, copy, nullable) NSString *mApsLoadFailError;

// loaded
@property (nonatomic, copy, nullable) NSString *mBannerSize;
@property (nonatomic, copy, nullable) NSString *mNetworkName;
@property (nonatomic, copy, nullable) NSString *mWaterfallName;
@property (nonatomic, assign) NSInteger mNetworkResponses;
@property (nonatomic, assign) long mLatencyMillis;
@property (nonatomic, copy, nullable) NSString *mCreativeId;
@property (nonatomic, assign) double mRevenue;
@property (nonatomic, copy, nullable) NSString *mLoadError;
@property (nonatomic, copy, nullable) NSString *mShowPlacement;

// show
@property (nonatomic, assign) long mShowingTimestamp;
@property (nonatomic, copy, nullable) NSString *mShowFailError;
@property (nonatomic, assign) long mAdTag;

// MARK: - 初始化方法
/// 完整初始化方法
- (instancetype)initWithAdUnitID:(NSString *)adUnitID
                       placement:(NSString *)placement
                        adFormat:(NSString *)adFormat
                          layers:(NSInteger)layers
                      requestTag:(long)requestTag;

// MARK: - 加载阶段
- (void)setLoadInfoWithAdUnitID:(NSString *)adUnitID
                      placement:(NSString *)placement
                       adFormat:(NSString *)adFormat
                         layers:(NSInteger)layers
                     requestTag:(long)requestTag;

- (void)setApsLoadedInfoWithStatus:(nullable NSString *)apsLoadStatus
                           failError:(nullable NSString *)apsLoadFailError;

- (void)setAdParamsLoadedInfo:(id)ad;

// MARK: - 时间与状态计算
- (void)setAdRequestTimestamp;
- (void)setShowingTimestamp;
- (long)getApsLoadDuration;
- (long)getShowFailDuration;
- (long)getLoadDuration;
- (long)getShowingDuration;


- (NSString *)description;

@end

NS_ASSUME_NONNULL_END
