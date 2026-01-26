//
//  OxAdEventModel.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/8/11.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAdEventModel : NSObject

@property(nonatomic, copy) NSString *mPlacementId;
@property(nonatomic, copy) NSString *mAdUnitId;
@property(nonatomic, copy) NSString *mAdFormat;
@property(nonatomic, copy) NSString *mPlacement;
@property(nonatomic, copy) NSString *mNetworkName;
@property(nonatomic, copy) NSString *mWaterfallName;
@property(nonatomic, copy) NSString *mCreativeId;
@property(nonatomic, copy) NSString *mErrorMsg;
@property(nonatomic, copy) NSString *mErrorCode;
@property(nonatomic, copy) NSString *mLimitation;
@property(nonatomic, strong) NSNumber *mIsReady;
@property(nonatomic, assign) NSInteger mNetworkResponses;  // 默认 -1
@property(nonatomic, assign) double mLatencyMillis;
@property(nonatomic, assign) double mRevenue;
@property(nonatomic, assign) long long mRequestTag;
@property(nonatomic, assign) long long mAdTag;
@property(nonatomic, assign) double mLoadedDuration;
@property(nonatomic, assign) double mShowingDuration;
@property(nonatomic, assign) double mFailedDuration;
@property(nonatomic, assign) CGSize mSize;

// 禁用默认初始化方法
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

// 自定义初始化方法，必传 mEventName、mAdFormat、mTag
- (instancetype)initWithAd:(nullable id)ad NS_DESIGNATED_INITIALIZER;

// 转为字典，自动进行空值判断
- (NSDictionary *)toDictionary;


@end

NS_ASSUME_NONNULL_END
