//
//  OxPlacementParams.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/10/31.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxPlacementParams : NSObject

// create
@property (nonatomic, copy, readonly) NSString *mAdUnitId;
@property (nonatomic, copy, readonly) NSString *mAdUserValueConfig;
@property (nonatomic, copy, readonly) NSString *mAdFormat;

// loading
@property (nonatomic, assign) long mRequestTag;
@property (nonatomic, assign) long mRequestTimestamp;
@property (nonatomic, copy, nullable) NSString *mPlacement;

// loaded
@property (nonatomic, copy, nullable) NSString *mLoadError;

// show
@property (nonatomic, copy, nullable) NSString *mShowPlacement;

// Show Limitation
@property (nonatomic, assign) long mLastShowFailedTimestamp;   // 广告没有Ready的情况下，调用show失败的时间戳。
@property (nonatomic, assign) BOOL mIsReady;
@property (nonatomic, copy, nullable) NSNumber *mErrorCode;
@property (nonatomic, assign) BOOL mIsLoadFailRetry;

// showing
@property (nonatomic, assign) long mShowingTimestamp;
@property (nonatomic, copy, nullable) NSString *mShowFailError;

// 其他
@property (nonatomic, copy, nullable) NSString *mAdStatus;

// 初始化
- (instancetype)initWithAdFormat:(NSString *)adFormat
                       adUnitId:(NSString *)adUnitId
              adUserValueConfig:(NSString *)adUserValueConfig;

// 设置加载信息
- (void)setLoadInfo:(NSString *)placement;

// 设置加载完成信息
- (void)setLoadedInfoWithErrorCode:(nullable NSNumber *)errorCode
                          adStatus:(nullable NSString *)adStatus;

// 设置广告展示信息
- (void)setAdDisplayInfo;

// 设置广告展示状态
- (void)setAdShowInfoWithReady:(BOOL)ready
                loadFailRetry:(BOOL)loadFailRetry;

// 获取失败时间间隔
- (long)getLastShowFailedDuration;
- (long)getLoadFailedDuration;
- (long)getShowingDuration;

- (NSString *)description;

@end

NS_ASSUME_NONNULL_END
