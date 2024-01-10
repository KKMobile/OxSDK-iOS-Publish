//
//  OxAdSdkManager.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/14.
//

#import <Foundation/Foundation.h>
#import "BaseAdManager.h"
#import "AdEventDelegate.h"
#import "OnMediationInitDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdSdkManager : NSObject

@property (nonatomic, assign) BOOL tachiEnable; // 设置tachi是否启用，主要用于部分不需要打点的iOS的工具
@property (nonatomic, assign) BOOL isSdkInitialized;
@property (nonatomic, strong) BaseAdManager  *mAdManager; // 当前的聚合平台adManager
@property (nonatomic, assign) OxSdkMediationType currentMediationType; // 当前的聚合平台
@property (nonatomic, copy) OnSdkInitComplete sdkInitComplete;

+ (nonnull instancetype)sharedInstance;


/// 初始化 OxSdk
/// @param delayInMills 延迟 n 毫秒执行初始化。
/// @param successBlock 成功毁掉
- (void)initializeWithDelayInMills:(int)delayInMills successBlock:(OnSdkInitComplete)successBlock;

/**
 * @param delegate  聚合平台初始化完成回调。
 */
- (void)initMediationType:(OxSdkMediationType)mediationType delegate:(nullable id<OnMediationInitDelegate>)delegate;

/// 切换聚合平台
/// - Parameter mediationType: 聚合平台类型
- (void)switchMediation:(OxSdkMediationType)mediationType;

///  判断第三方 Mediation 是否初始化完成，仅 OxSdk 内部使用。
/// - Parameter mediationType: 聚合平台类型
- (BOOL)isMediationInitialized:(OxSdkMediationType)mediationType;

/// RemoteConfig 获取完成。
- (void)onRemoteConfigFetchCompleted;


@end

NS_ASSUME_NONNULL_END
