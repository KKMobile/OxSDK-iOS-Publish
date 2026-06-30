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
- (void)loadAdWithPlacement:(nullable NSString *)loadPlacement;
- (void)loadAdInternalWithPlacement:(nullable NSString *)loadPlacement isReload:(BOOL)isReload;
- (void)showAdWithViewController:(UIViewController *)viewController placement:(NSString *)placement;
- (void)showAdWithPlacement:(NSString *)placement;
- (void)destroyAd;

- (void)setReloadAfterFailed:(BOOL)reload;
- (void)setExtraParametersForMaxKey:(NSString *)key value:(nullable NSString *)value;
- (void)onClientShowingLimitation:(NSString *)limitation;
- (void)onClientShowingLimitationWithPlacement:(nullable NSString *)placement limitation:(NSString *)limitation;

- (BOOL)isReady;

- (NSArray<OxAd *> *)getCacheAds;

#pragma mark - Used by AdLoadManager

- (OxPlacementParams *)oxPlacementParams;
- (BOOL)isOpenDynamic;
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

- (BOOL)isFullScreenAd;
- (BOOL)isNotMaxAd;
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

@end

NS_ASSUME_NONNULL_END
