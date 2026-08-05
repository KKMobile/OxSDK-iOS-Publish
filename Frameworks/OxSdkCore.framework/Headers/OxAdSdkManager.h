//
//  OxAdSdkManager.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/14.
//

#import "BaseAdManager.h"
#import "AdEventDelegate.h"
#import "DataTools.h"

#define OXSDK_VERSION @"1.3.6.0-RC01-202608051300" 

NS_ASSUME_NONNULL_BEGIN

@interface OxAdSdkManager : BaseAdManager

@property (nonatomic, assign) BOOL       tachiEnable; // 设置tachi是否启用，主要用于部分不需要打点的iOS的工具

@property(nonatomic, assign) BOOL    mAdmobSdkInitialed;
@property(nonatomic, assign) BOOL    mMaxSdkInitialed;
@property(nonatomic, assign) BOOL    enableDebug;
@property(nonatomic, assign) BOOL    enableFBEvents;
@property(nonatomic, assign) BOOL    enableTAEvents;
@property(nonatomic, assign,readonly) long long sessionId;

+ (nonnull instancetype)sharedInstance;

@property (nonatomic, weak) id<AdEventDelegate> mAdEventDelegate;

- (void)initialize:(Platform)platform successBlock:(OnSdkInitComplete)successBlock;

/// 设置默认聚合平台，不设置默认为Admob，在SDK初始化之前调用
/// @param defaultMediationPlatform 平台类型，枚举值 Admob/ Max
- (void)setDefaultMediationPlatform:(Platform)defaultMediationPlatform;

/// 更改广告聚合平台，主要作用firebase取到更新的值更新本地记录的值
/// @param platform Platform
- (void)switchMediationPlatform:(Platform)platform successBlock:(OnSdkInitComplete)block;

/// Remote Config 获取成功之后，将 OxSdk 切换到对应的 Mediation
- (Platform)switchMediationPlatformByRemoteConfig:(OnSdkInitComplete)block;

- (BOOL)isMediationInitialized:(Platform)mediation;


/// 获取当前的sdk 聚合平台
- (Platform)getMediationPlatform;

- (Platform)getDefaultMediationPlatform;

- (void)enableDebug:(BOOL)enable;

/// 获得google 自适配的banner 尺寸
- (CGSize)getAdaptiveBannerAdSize;

- (BOOL)shouldShowConsentDialog;

-(void)setGameLevel:(int)level;

- (int)getFrequencyOfEvent:(CountedEvents)event;

- (double)getLtAdValue;

/**
 * 客户端辅助 OxSdk 完善打点信息。
 */
- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

/// RemoteConfig 获取完成。
- (void)onRemoteConfigFetchCompleted;

/**
 * 设置 OxSdk 内部属性
 */
- (void)setOxExtraParameter:(NSString *)value forKey:(NSString *)key;

/**
 * 获取 OxSdk 内部属性
 */
- (NSDictionary<NSString *,NSString *> *)getOxExtraParameter;

@end

NS_ASSUME_NONNULL_END
