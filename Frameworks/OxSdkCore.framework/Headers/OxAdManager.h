//
//  OxAdManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "IAdLoadCallback.h"
#import "IOnConfigChangedListener.h"
#import "OxStrategy.h"

@class OxAd, OxAdParams, OxPlacementParams, AdHelperConfigManager, AdLoadManager, AdUnitBaseConfig, IdConfig, OxStrategy;

@protocol AdDelegate;
@protocol AdInternalListener;

NS_ASSUME_NONNULL_BEGIN

/** 广告位 Manager 基类。加载、展示与销毁通过具体格式 Manager 执行；同名广告位复用管理器。 */
@interface OxAdManager : NSObject <IAdLoadCallback, IOnConfigChangedListener>

@property (nonatomic, weak, nullable) id<AdDelegate> adListener;
@property (nonatomic, strong, nullable) id<AdInternalListener> internalAdListener;
@property (nonatomic, strong, readonly) OxStrategy *oxStrategy;
@property (nonatomic, strong, readonly, nullable) AdHelperConfigManager *configManager;
@property (nonatomic, strong, readonly, nullable) AdLoadManager *adLoadManager;
@property (nonatomic, strong, readonly) OxPlacementParams *baseInfo;
@property (nonatomic, weak, readonly, nullable) UIViewController *viewController;

- (instancetype)initWithViewController:(UIViewController *)viewController
                            adUnitName:(NSString *)adUnitName
                              adFormat:(NSString *)adFormat;

- (instancetype)initWithViewController:(UIViewController *)viewController
                          adUnitConfig:(AdUnitBaseConfig *)adUnitConfig
                            adUnitName:(NSString *)adUnitName
                              adFormat:(NSString *)adFormat;

- (void)loadAd;
- (void)loadAdWithIdConfigFilter:(BOOL (^)(IdConfig *config))filter completion:(void (^)(BOOL success))completion;
- (void)notifyInternalLoadFailureWithoutRetry;
- (void)showSelectedFullScreenAd:(OxAd *)ad viewController:(UIViewController *)vc placement:(NSString *)placement;
- (void)showSelectedFullScreenAd:(OxAd *)ad viewController:(UIViewController *)vc placement:(NSString *)placement ownerStrategy:(nullable OxStrategy *)ownerStrategy;
- (BOOL)canShowAd;
/// 发起加载，placement 是业务场景；已有缓存可能立即返回 Loaded，后台请求仍可继续。
- (void)loadAdWithPlacement:(nullable NSString *)loadPlacement;
- (void)loadAdInternalWithPlacement:(nullable NSString *)loadPlacement isReload:(BOOL)isReload;
- (void)showAdWithViewController:(UIViewController *)viewController placement:(NSString *)placement;
- (void)showAdWithPlacement:(NSString *)placement;
/// 释放广告缓存、请求与监听，并从同名管理器注册表移除。
- (void)destroyAd;

/// 设置加载失败后是否允许自动重试；仍受配置与重试策略约束。
- (void)setReloadAfterFailed:(BOOL)reload;
- (void)setExtraParametersForMaxKey:(NSString *)key value:(nullable NSString *)value;
- (void)onClientShowingLimitation:(NSString *)limitation;
/// App 获得展示机会却因业务限制放弃时，记录场景与原因；不主动展示。
- (void)onClientShowingLimitationWithPlacement:(nullable NSString *)placement limitation:(NSString *)limitation;

/// 查询缓存就绪且当前展示策略允许；不触发回调、打点或消耗展示次数。
/// 页面、容器及实际展示结果仍由 show 入口检查。
- (BOOL)isReady;
/// SDK 内部原始就绪状态，包含该格式的 BackUp 判断，不受展示频控影响。
- (BOOL)hasReadyAd;

- (NSArray<OxAd *> *)getCacheAds;

/// 判断指定备用广告位是否存在至少一个启用且有 ID 的配置
- (BOOL)hasEnabledAdUnitId:(NSString *)adUnitName;
/// 判断当前广告位是否仍有一轮加载未收口
- (BOOL)isAdLoadInProgress;

#pragma mark - Used by AdLoadManager

- (OxPlacementParams *)oxPlacementParams;
- (BOOL)isOpenDynamic;
- (BOOL)isOpenPostBidding;
- (nullable OxAd *)createOxAdWithAdFormat:(NSString *)adFormat idConfig:(IdConfig *)idConfig;
- (void)onBackOxAd:(OxAd *)ad;
- (void)setReturnFlag:(BOOL)isReturn;
- (void)setAllFailed:(BOOL)allFailed;
- (BOOL)isAllFailed;
- (void)callAdLoadSuccess;
- (void)callAdLoadSuccessWithAd:(nullable OxAd *)oxAd;
- (void)callAdLoadFail:(NSString *)error;
- (void)callAdLoadFail:(NSString *)error adParams:(nullable OxAdParams *)adParams;

#pragma mark - Subclass hooks

- (BOOL)isViewControllerValid:(nullable UIViewController *)viewController;
- (BOOL)isFullScreenAd;
- (BOOL)isNotMaxAd;
/// 是否为 Banner 或 Mrec（两者共用一套“不通过 AdLoadManager 收口成功/失败回调”的逻辑）
- (BOOL)isBannerOrMrec;
/// 取消当前展示并清理展示态广告；默认空实现，Banner/Mrec 覆盖。
- (void)cancelShow;
- (void)removeFromAdHelpers:(NSString *)adUnitName;
- (void)callOnAdDisplayFailedForCheck:(NSString *)error;

#pragma mark - Event handlers (subclasses / internal listener bridge)

- (void)handleAdLoaded:(OxAdParams *)adParams;
- (void)handleAdLoadFailedWithAdParams:(nullable OxAdParams *)adParams errorCode:(NSInteger)errorCode error:(NSString *)error;
- (void)handleAdDisplayed:(nullable OxAdParams *)adParams;
- (void)handleAdDisplayFailedWithAdParams:(nullable OxAdParams *)adParams error:(NSString *)error;
- (void)handleAdClicked:(OxAdParams *)adParams;
- (void)handleAdClosed:(OxAdParams *)adParams;
- (void)handleAdOpened;

- (void)updateViewController:(UIViewController *)viewController;
- (void)setRetryAttempt;
- (nullable NSString *)getFloorID;
- (void)initAdListener;
- (void)finishHelperActivityAndCancelTimer;
- (BOOL)shouldReloadAfterAllFailedWithAdParams:(nullable OxAdParams *)adParams;
- (void)reloadWithLoadType:(OxStrategyLoadType)loadType;
- (void)markDisplayCalled;

- (BOOL)tryAcceptShowRequest:(NSString *)placement;
- (void)showAdAfterRequestAccepted:(UIViewController *)viewController placement:(NSString *)placement;
- (void)onAdDisplayFailedForCheck:(NSString *)error;
@end

NS_ASSUME_NONNULL_END
