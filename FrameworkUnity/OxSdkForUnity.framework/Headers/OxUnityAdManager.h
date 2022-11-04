//
//  OxUnityAdManager.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/18.
//

#import <Foundation/Foundation.h>
#import "OxInterstitialAdHelper.h"
#import "OxRewardedAdHelper.h"
#import "OxBannerAdHelper.h"
#import "OxMrecAdHelper.h"
#import "OxUnityConstants.h"
#import "OxUnityUtils.h"
#import "OxAdjustTokens.h"
NS_ASSUME_NONNULL_BEGIN


@interface UnityInterstitialAdHelper: NSObject<InterstitialAdDelegate>

@property (nonatomic, strong) NSMutableDictionary  *interstitialAdHelperDic;

+ (instancetype)sharedSingleton;

- (void)setInterstitialExtraParametersForMax:(NSString *)adId key:(NSString *)key value:(nullable NSString *)value;

///加载插屏广告
- (void)loadInterstitial:(NSString *)adId placement:(NSString *)placement;

/**
    * 判断是否存在 adId 对应的可用的插屏广告。
    * adId 对应的广告是否存在且可用（Ready）。
    *
    */
- (BOOL)isInterstitialReady:(NSString *)adId;

///展示插屏广告
- (void)showInterstitial:(NSString *)adId placement:(NSString *)placement;

- (void)destoryInterstitial:(NSString *)adId;

- (void)setInterstitialReloadAfterFailed:(NSString *)adId reload:(BOOL) reload;

@end

@interface UnityRewardedAdHelper : NSObject<RewardedAdDelegate>

@property (nonatomic, strong) NSMutableDictionary  *rewardedAdHelperDic;

+ (instancetype)sharedSingleton;

- (void)setRewardedExtraParametersForMax:(NSString *)adId key:(NSString *)key value:(nullable NSString *)value;

/// 加载RV
- (void)loadRV:(NSString *)adId placement:(NSString *)placement;

/// 判断是否存在adid 可用的广告
- (BOOL)isRVReady:(NSString *)adId;

/// 展示RV
- (void)showRv:(NSString *)adId placement:(NSString *)placement;

/// 销毁ID对应的Rv
- (void)destoryRv:(NSString *)adId;

- (void)setRVReloadAfterFailed:(NSString *)adId reload:(BOOL) reload;

@end

@interface UnityBannerAdHelper : NSObject<BannerAdDelegate>

@property (nonatomic, strong) NSMutableDictionary  *adPositionDic;
@property (nonatomic, strong) NSMutableDictionary  *bannerAdHelperDic;

+ (instancetype)sharedSingleton;

- (void)setBannerExtraParametersForMax:(NSString *)adId key:(NSString *)key value:(nullable NSString *)value;

/// 加载Banner
/// @param adid 广告ID
/// @param position 位置
- (void)loadBanner:(NSString *)adid position:(OxAdPosition)position placement:(NSString *)placement;

///banner是否加载完毕
- (BOOL)isBannerReady:(NSString *)adId;

///展示banner
- (void)showBanner:(NSString *)adid placement:(NSString *)placement;

/// 隐藏banner
- (void)hideBanner:(NSString *)adId;

- (void)destoryBanner:(NSString *)adId;

- (void)enableBannerAutoRefresh:(NSString *)adId enable:(BOOL)enable;
@end

@interface UnityMrecAdHelper : NSObject<MrecAdDelegate>

@property (nonatomic, strong) NSMutableDictionary  *adPositionDic;
@property (nonatomic, strong) NSMutableDictionary  *mrecAdHelperDic;

- (void)setMRecExtraParametersForMax:(NSString *)adId key:(NSString *)key value:(nullable NSString *)value;

+ (instancetype)sharedSingleton;

/// 加载Mrec
/// @param adid 广告ID
/// @param position 位置
- (void)loadMrec:(NSString *)adid position:(OxAdPosition)position placement:(NSString *)placement;

///banner是否加载完毕
- (BOOL)isMrecReady:(NSString *)adId;

///展示banner
- (void)showMrec:(NSString *)adid placement:(NSString *)placement;

/// 隐藏banner
- (void)hideMrec:(NSString *)adId;

- (void)destoryMrec:(NSString *)adId;

- (void)enableMrecAutoRefresh:(NSString *)adId enable:(BOOL)enable;

@end

@interface OxUnityAdManager : NSObject

+ (nonnull instancetype)sharedManager;

- (void)initializeSdk;


/// 是否应该展示 GDPR 请求（弹窗）。
- (BOOL)shouldShowConsentDialog;

///设置用户是否授权了 GDPR。
- (void)setHasUserConsent:(BOOL)hasUserConsent;

// 展示默认 GDPR 弹窗。
- (void)showConsentDialog;

/**
     * Set whether to begin video ads in a muted state or not.
     * Params:
     * muted – If ads should begin in a muted state.
     */
- (void)setMute:(BOOL)mute;

///设置变现打点阀值
- (void)setTopValues:(NSArray *)topValues;

/// 设置log等级
- (void)setEventLevel:(int)level;

- (void)setDefaultMediationPlatform:(Platform)platform;

- (NSInteger)getPlatform;

- (void)switchMediationPlatform:(Platform)targetMediation;

- (UIViewController *)getRootVC;

/// 获取 Banner 和 MRec 的 Parent View，没有时重新创建。
- (UIView *)requireAdContainer:(NSString *)adId position:(OxAdPosition)position viewSize:(CGSize)adSize;

/**
     * 得到展示广告的机会，但因客户端限制（如时间限制）而不去展示时，客户端可以调用此方法上报打点。
     *
     * @param adId 广告 ID。
     * @param placement  场景名称。
     * @param limitation 限制本次广告展示的原因。
     */
- (void)reportShowAdLimitedByClient:(NSString *)adId placement:(NSString *)placement limitation:(NSString *)limitation;

- (void)setAdjustTokens:(OxAdjustTokens *)adjustTokens;

- (void)setGameLevel:(int)currentLevel;

- (void)setUserId:(NSString *)userIdentifier;

- (void)setExtraParameter:(NSString *)key value:(NSString *)value;

- (void)setDeepUserLevel:(int)deepUserLevel;

- (void)setAllowedKeywordType:(int)type;

- (void)setAdLtvMedium:(double)adLtvMedium;

- (void)setAdLtvHigh:(double)adLtvHigh;

- (void)setDaysOfNewUser:(int)days;

- (void)setDayCountSinceInstall:(int)dayCount;

- (void)setUacCampaign:(nullable NSString *)uacCampaign;

- (int)getFrequencyOfEvent:(CountedEvents)event;

- (double)getLtAdValue;


@end

NS_ASSUME_NONNULL_END
