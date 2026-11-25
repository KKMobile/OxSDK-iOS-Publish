//
//  OxAd.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OxMAAdRevenueDelegateImpl.h"
#import "OXLogMoudle.h"
#import "AdEvents.h"
#import "OxRemoteConfigHelper.h"

@class IdConfig, OxPlacementParams, OxAdParams, MAAd, AdReward;
@protocol AdInternalListener;

NS_ASSUME_NONNULL_BEGIN

@class OxAd;

@protocol OxAdLoadListener <NSObject>
- (void)onAdLoaded:(OxAd *)ad;
- (void)onAdLoadFailed:(OxAd *)ad error:(nullable NSString *)error;
@end

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
- (void)onAdapterUserRewarded:(OxAd *)ad reward:(AdReward *)reward;
@end

@interface OxAd : NSObject

FOUNDATION_EXPORT const NSInteger OxAdDefaultShowDelayMs;

@property (nonatomic, weak, nullable) id<OxAdDelegate> delegate;
@property (nonatomic, copy, nullable) OxAdLoadSuccessBlock onAdLoaded;
@property (nonatomic, copy, nullable) OxAdLoadFailureBlock onAdLoadFailed;
@property (nonatomic, strong, nullable) OxMAAdRevenueDelegateImpl *oxMAAdRevenueDelegateImpl;
@property (nonatomic, strong, nullable) MAAd *mMaxAd;

@property (nonatomic, copy, nullable) NSString *mAdFormat;
@property (nonatomic, copy, nullable) NSString *mAdUnitId;
@property (nonatomic, copy, nullable) NSString *mPlacement;
@property (nonatomic, copy, nullable) NSString *mShowPlacement;
@property (nonatomic, copy, nullable) NSString *mFloorPrice;
@property (nonatomic, assign) double mRevenue;
@property (nonatomic, assign) double mDynamicFloorECPM;

@property (nonatomic, assign) NSInteger mLayers;
@property (nonatomic, assign) double mRequestTimestamp;
@property (nonatomic, assign) double mShowingTimestamp;
@property (nonatomic, assign) BOOL mReload;
@property (nonatomic, assign) long long mRequestTag;
@property (nonatomic, assign) long long mTag;
@property (nonatomic, assign) float mJumpHeightPer;
@property (nonatomic, assign) double mFloorRevenue;

@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *mMaxExtraParameterMap;
@property (nonatomic, strong, nullable) dispatch_source_t delayTask;

@property (nonatomic, strong, nullable) IdConfig *idConfig;
@property (nonatomic, strong, nullable) OxPlacementParams *oxPlacementParams;
@property (nonatomic, assign) BOOL isFloorID;
@property (nonatomic, strong, nullable) OxAdParams *mAdEventParams;

@property (nonatomic, weak, nullable) UIViewController *mViewController;
@property (nonatomic, weak, nullable) id<AdInternalListener> internalListener;
@property (nonatomic, weak, nullable) id<OxAdLoadListener> adLoadListener;

/// Android: OxAd(placementParams, idConfig, activity)
- (instancetype)initWithPlacementParams:(OxPlacementParams *)placementParams
                               idConfig:(IdConfig *)idConfig
                         viewController:(nullable UIViewController *)viewController
                               listener:(nullable id<AdInternalListener>)listener;

/// Adapter 反射构造（Android 四参构造）
- (instancetype)initWithPlacementParams:(OxPlacementParams *)placementParams
                               idConfig:(IdConfig *)idConfig
                         viewController:(nullable UIViewController *)viewController
                      internalListener:(nullable id<AdInternalListener>)listener NS_DESIGNATED_INITIALIZER;

/// Legacy — OxAdHelper / Max*AdHelper 兼容，Step 5 后逐步移除
- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                       placement:(NSString *)placement
                          layers:(NSInteger)layers
            maxExtraParameterMap:(nullable NSDictionary *)maxExtraParameterMap
                          reload:(BOOL)reload
                      requestTag:(long long)requestTag
                   jumpHeightPer:(float)jumpHeightPer
                    floorRevenue:(double)floorRevenue;

- (void)showAd:(NSString *)placement;
- (void)showAd:(NSString *)placement viewController:(UIViewController *)viewController;
- (BOOL)isReady;

- (void)loadAdInternal;
- (void)loadAdInternalWithListener:(id<OxAdLoadListener>)listener;
- (void)loadAd;
- (void)destroyAd;

- (NSString *)getAdUnitId;
- (double)getRevenue;
- (void)setRevenue:(double)revenue;
- (nullable IdConfig *)getIdConfig;
- (nullable OxPlacementParams *)getOxPlacementParams;
- (void)setOxPlacementParams:(OxPlacementParams *)placementParams;
- (nullable OxAdParams *)getAdEventParams;
- (void)setViewController:(nullable UIViewController *)viewController;

- (BOOL)isDisableID:(NSString *)disableIds;
- (double)getDuration:(double)latestTimestamp;
- (NSString *)getRemoteDisabIds;

- (void)startDelayTask:(void (^)(void))callback;
- (void)stopTimeoutTimer;
- (void)loadTimeOut;
- (void)updateAdTag:(long long)tag;
- (void)updateFloorRevenue:(double)floorRevenue;
- (void)updateRequestTag:(double)requestTag;
- (void)setAdTag:(long long)tag;
- (void)setExtraParameter:(NSString *)key value:(nullable NSString *)value;

/// 子类 / 适配器回调桥接
- (void)onOxAdRequest;
- (void)onOxAdLoaded;
- (void)onOxAdLoadFail:(NSString *)errorMsg;
- (void)handleAdLoadedBridge;
- (void)handleAdLoadFailedBridge:(NSString *)error;

- (BOOL)isViewControllerValid;
- (void)runOnMainThread:(dispatch_block_t)block;
- (void)runOnMainThreadDelayed:(dispatch_block_t)block delayMs:(NSInteger)delayMs;
- (BOOL)shouldApplyDynamicFloor:(double)jumpHeightPer floorRevenue:(double)floorRevenue;
- (void)calculateDynamicFloorECPM:(double)jumpHeightPer floorRevenue:(double)floorRevenue;
- (NSString *)double2String:(double)ecpm;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
