//
//  OxAdSdkInitOptions.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"
#import "BaseAdManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^OxConsentCheckResultBlock)(BOOL isSubjectToGDPR);

@class OxAdSdkInitOptionsBuilder;

/** SDK 初始化参数的不可变快照；通过 Builder 设置 App ID、隐私链接、兜底聚合平台与初始化回调。 */
@interface OxAdSdkInitOptions : NSObject

@property (nonatomic, copy, readonly, nullable) NSString *appId;
@property (nonatomic, copy, readonly, nullable) NSString *privacyPolicyLink;
@property (nonatomic, assign, readonly) Platform fallbackMediationPlatform;
@property (nonatomic, copy, readonly, nullable) OnSdkInitComplete initializationCompleteBlock;
@property (nonatomic, copy, readonly, nullable) OnSdkInitFailed initializationFailedBlock;
@property (nonatomic, copy, readonly, nullable) OxConsentCheckResultBlock consentCheckResultBlock;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (OxAdSdkInitOptionsBuilder *)builderWithAppId:(nullable NSString *)appId;

@end

/** 链式构建初始化选项。build 后继续修改 Builder 不影响已生成选项。 */
@interface OxAdSdkInitOptionsBuilder : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithAppId:(nullable NSString *)appId NS_DESIGNATED_INITIALIZER;
/// 设置隐私政策链接；需展示隐私界面的流程由 SDK 使用当前可见页面执行。
- (instancetype)setPrivacyPolicyLink:(nullable NSString *)privacyPolicyLink;
/// 远程/本地配置未指定有效聚合平台时的兜底值。
- (instancetype)setFallbackMediationPlatform:(Platform)fallbackMediationPlatform;
/// SDK 初始化成功通知，不表示广告已加载。
- (instancetype)setInitializationCompleteBlock:(nullable OnSdkInitComplete)initializationCompleteBlock;
/// SDK 初始化失败原因；可在处理失败后重新初始化。
- (instancetype)setInitializationFailedBlock:(nullable OnSdkInitFailed)initializationFailedBlock;
/// 隐私地区判断结果；不是广告加载结果，也不代表用户已同意。
- (instancetype)setConsentCheckResultBlock:(nullable OxConsentCheckResultBlock)consentCheckResultBlock;
/// 生成供 initializeWithOptions: 使用的独立选项快照。
- (OxAdSdkInitOptions *)build;

@end

NS_ASSUME_NONNULL_END
