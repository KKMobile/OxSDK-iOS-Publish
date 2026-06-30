//
//  OxAdParams.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class IdConfig;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdParams : NSObject

@property (nonatomic, copy, nullable) NSString *mAdUnitID;
@property (nonatomic, strong, nullable) IdConfig *idConfig;
@property (nonatomic, copy, nullable) NSString *mAdUnitName;
@property (nonatomic, copy, nullable) NSString *mAdFormat;
@property (nonatomic, assign) long long mRequestTag;

@property (nonatomic, assign) long long mAdRequestTimestamp;
@property (nonatomic, assign) long long mApsRequestTimestamp;
@property (nonatomic, copy, nullable) NSString *mApsLoadStatus;
@property (nonatomic, copy, nullable) NSString *mApsLoadFailError;
@property (nonatomic, copy, nullable) NSString *mDynamicFloorECPM;
@property (nonatomic, copy, nullable) NSString *mJumpHeightPer;
@property (nonatomic, assign) float mUserValueSegment;

@property (nonatomic, copy, nullable) NSString *mBannerSize;
@property (nonatomic, copy, nullable) NSString *mNetworkName;
@property (nonatomic, copy, nullable) NSString *mWaterfallName;
@property (nonatomic, assign) NSInteger mNetworkResponses;
@property (nonatomic, assign) long long mLatencyMillis;
@property (nonatomic, copy, nullable) NSString *mCreativeId;
@property (nonatomic, assign) double mRevenue;
@property (nonatomic, copy, nullable) NSString *mLoadError;
@property (nonatomic, copy, nullable) NSString *mShowPlacement;
@property (nonatomic, copy, nullable) NSString *mPlacement;
@property (nonatomic, assign) long long mLoadedTimestamp;

@property (nonatomic, assign) long long mShowingTimestamp;
@property (nonatomic, copy, nullable) NSString *mShowFailError;
@property (nonatomic, assign) long long mAdTag;

/// Adapter request layer index in waterfall
@property (nonatomic, assign) NSInteger mLayers;

- (instancetype)init;
- (instancetype)initWithIdConfig:(IdConfig *)idConfig
                      adUnitName:(NSString *)adUnitName
                        adFormat:(NSString *)adFormat
                      requestTag:(long long)requestTag;

- (void)setApsLoadedInfoWithStatus:(nullable NSString *)apsLoadStatus failError:(nullable NSString *)apsLoadFailError;
- (void)setAdParamsLoadedInfoWithBannerSize:(nullable NSString *)bannerSize
                                networkName:(nullable NSString *)networkName
                              waterfallName:(nullable NSString *)waterfallName
                           networkResponses:(NSInteger)networkResponses
                              latencyMillis:(long long)latencyMillis
                                 creativeId:(nullable NSString *)creativeId
                                    revenue:(double)revenue;
- (void)setDynamicInfoWithFloorECPM:(nullable NSString *)dynamicFloorECPM jumpHeightPer:(nullable NSString *)jumpHeightPer;
- (void)setAdRequestTimestamp;
- (void)setShowingTimestamp;

- (long long)getApsLoadDuration;
- (long long)getLoadDuration;
- (long long)getShowFailDuration;
- (long long)getShowingDuration;

@end

NS_ASSUME_NONNULL_END
