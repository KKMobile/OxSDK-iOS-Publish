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
@property(nonatomic, assign) BOOL    enableDebug;

+ (nonnull instancetype)sharedInstance;

@property (nonatomic, weak) id<AdEventDelegate> mAdEventDelegate;

/// 设置默认聚合平台，不设置默认为Admob，在SDK初始化之前调用
/// @param defaultMediationPlatform 平台类型，枚举值 Admob/ Max
- (void)setDefaultMediationPlatform:(Platform)defaultMediationPlatform;

/// 更改广告聚合平台，主要作用firebase取到更新的值更新本地记录的值
/// @param platform Platform
- (void)switchMediationPlatform:(Platform)platform successBlock:(OnSdkInitComplete)block;


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

- (BOOL)isSdkInitialed:(Platform)platform;

- (void)initialize:(Platform)platform successBlock:(OnSdkInitComplete)successBlock;

@end

NS_ASSUME_NONNULL_END
