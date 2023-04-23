//
//  OxAdSdkManager.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/14.
//

#import "BaseAdManager.h"
#import "DataTools.h"
#import "AdEventDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdSdkManager : BaseAdManager

@property (nonatomic, assign) BOOL       tachiEnable; // 设置tachi是否启用，主要用于部分不需要打点的iOS的工具

@property(nonatomic, assign) BOOL    mAdmobSdkInitialed;
@property(nonatomic, assign) BOOL    mMaxSdkInitialed;
@property(nonatomic, assign) BOOL    otherConfigInitialized;
@property(nonatomic, assign) BOOL    enableDebug;

+ (nonnull instancetype)sharedInstance;

@property (nonatomic, weak) id<AdEventDelegate> mAdEventDelegate;

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

- (void)initialize:(OnSdkInitComplete)successBlock;
- (void)initialize:(Platform)platform successBlock:(OnSdkInitComplete)successBlock;


/// 初始化第三方广告 Mediation，仅 OxSdk 内部使用。
- (void)initThirdPartyAdManger:(Platform)platform successBlock:(OnSdkInitComplete)successBlock;

/// 判断第三方 Mediation 是否初始化完成，仅 OxSdk 内部使用
- (BOOL)isThirdPartySdkInitialed:(Platform)platform;

@end

NS_ASSUME_NONNULL_END
