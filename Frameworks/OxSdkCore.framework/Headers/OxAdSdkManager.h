//
//  OxAdSdkManager.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/14.
// 4.0

#import "BaseAdManager.h"
#import "AdEventDelegate.h"
#import "OxAdSdkInitOptions.h"

#define OXSDK_VERSION @"1.2-PR-OpConfig-202610091903"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdSdkManager : BaseAdManager

@property (nonatomic, assign) BOOL       tachiEnable; // 设置tachi是否启用，主要用于部分不需要打点的iOS的工具

@property(nonatomic, assign) BOOL    mAdmobSdkInitialed;
@property(nonatomic, assign) BOOL    mMaxSdkInitialed;
@property(nonatomic, assign) BOOL    enableDebug;
@property(nonatomic, assign) BOOL    enableFBEvents;
@property(nonatomic, assign) BOOL    enableTAEvents;
@property(nonatomic, assign,readonly) long long sessionId;
@property(nonatomic, assign,readonly) int sessionCount;
/// 宿主传入的 SDK appId。初始化时必须由宿主传入，用于配置加解密 key 派生。
@property(nonatomic, copy, readonly) NSString *appId;

+ (nonnull instancetype)sharedInstance;

@property (nonatomic, weak) id<AdEventDelegate> mAdEventDelegate;

/// 不支持无 appId 初始化；宿主必须调用带 appId 的初始化入口。
- (void)initializeWithSuccessBlock:(OnSdkInitComplete)successBlock failedBlock:(nullable OnSdkInitFailed)failedBlock NS_UNAVAILABLE;

/// 不支持无 appId 初始化；宿主必须调用 initializeWithAppId:platform:successBlock:failedBlock:。
- (void)initialize:(Platform)platform successBlock:(OnSdkInitComplete)successBlock failedBlock:(nullable OnSdkInitFailed)failedBlock NS_UNAVAILABLE;

/// 初始化 SDK，appId 由宿主传入。
- (void)initializeWithAppId:(NSString *)appId successBlock:(OnSdkInitComplete)successBlock failedBlock:(nullable OnSdkInitFailed)failedBlock;

/// 初始化 SDK，appId 和聚合平台由宿主传入。
- (void)initializeWithAppId:(NSString *)appId platform:(Platform)platform successBlock:(OnSdkInitComplete)successBlock failedBlock:(nullable OnSdkInitFailed)failedBlock;

/// 使用 options 初始化 SDK，对齐 Android OxAdSdkInitOptions。
- (void)initializeWithOptions:(OxAdSdkInitOptions *)options;

/// 设置隐私政策链接，并同步给 GDPR 管理器。
- (void)setPrivacyPolicyLink:(nullable NSString *)privacyPolicyLink;

/// 设置默认聚合平台，不设置默认为Admob，在SDK初始化之前调用
/// @param defaultMediationPlatform 平台类型，枚举值 Admob/ Max
- (void)setDefaultMediationPlatform:(Platform)defaultMediationPlatform;

/// 更改广告聚合平台，主要作用firebase取到更新的值更新本地记录的值
/// @param platform Platform
- (void)switchMediationPlatform:(Platform)platform successBlock:(OnSdkInitComplete)block failedBlock:(nullable OnSdkInitFailed)failedBlock;

/// Remote Config 获取成功之后，将 OxSdk 切换到对应的 Mediation
- (Platform)switchMediationPlatformByRemoteConfig:(OnSdkInitComplete)block failedBlock:(nullable OnSdkInitFailed)failedBlock;

- (BOOL)isMediationInitialized:(Platform)mediation;

/// 判断一组聚合平台是否都已初始化，用于广告位混合 MAX/AdMob 请求前校验。
- (BOOL)areSdkInitialized:(nullable NSSet<NSNumber *> *)platforms;

/// 获取当前的sdk 聚合平台
- (Platform)getMediationPlatform;

- (Platform)getDefaultMediationPlatform;

- (Platform)platformFromMediationString:(nullable NSString *)mediation;

- (void)enableDebug:(BOOL)enable;

/// 获得google 自适配的banner 尺寸
- (CGSize)getAdaptiveBannerAdSize;

- (BOOL)shouldShowConsentDialog;

-(void)setGameLevel:(int)level;

/// App 主动检查所有可变规则。
- (void)activeRefresh;

- (void)setGamePlayMinutes:(int)minutes;
- (void)setGamePayCounts:(int)count;

- (int)getFrequencyOfEvent:(CountedEvents)event;

- (double)getLtAdValue;

/**
 * 客户端辅助 OxSdk 完善打点信息。
 */
- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

/// RemoteConfig 获取完成。
- (void)onRemoteConfigFetchCompleted;

- (void)setDeepLinkUrl:(nullable NSString *)url;
- (nullable NSString *)getDeepLinkUrl;

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
