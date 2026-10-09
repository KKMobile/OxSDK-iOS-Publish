//
//  InternalConsentManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BaseConsentManager.h"
#import "OxConsentMananger.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^InternalConsentResultCallback)(BOOL isSubjectToGDPR);

/// GDPR 内部统一调度类，不直接负责画 UI，而是负责“选择使用哪套 GDPR 方案”。
///
/// 整体流程可以理解为：
/// 1. SDK 初始化时先调用 initializeWithViewController:privacyPolicyLink:callback:。
/// 2. 这里优先初始化 Google UMP，因为 UMP 是当前优先级最高的 GDPR 判断来源。
/// 3. 如果 UMP 明确可用，后续 GDPR 弹窗就走 UMP。
/// 4. 如果 UMP 不可用或失败，再根据当前聚合平台兜底：
///    - MAX 聚合：等 MAX 初始化完成后，用 MAX/CMP 的状态判断和展示；
///    - 非 MAX 聚合：使用服务端下发的 geoConsent 判断是否在 GDPR 区域。
/// 5. 最终把“是否受 GDPR 约束”通过 callback 和 listener 返回给外部。
///
/// 这个类对外隐藏了 UMP、CMP、缓存、网络重试这些细节，
/// 外部只需要关心 isSubjectToGDPR 和 showConsentDialog。
@interface InternalConsentManager : NSObject

/// 单例入口。
/// GDPR 状态需要在 SDK 生命周期内保持一致，所以这里不允许外部创建多个实例。
+ (instancetype)sharedInstance;

/// 隐私政策链接。
/// SDK 初始化时由外部传入，后续自定义 GDPR/CMP 页面需要展示隐私政策时会使用。
@property (nonatomic, copy, nullable) NSString *privacyPolicyLink;

/// 最终判定结果：用户是否处于 GDPR 管辖范围内。
/// YES 表示后续需要按 GDPR 流程处理同意弹窗和广告授权；
/// NO 表示当前用户不需要走 GDPR 同意弹窗。
@property (nonatomic, assign, readonly) BOOL subjectToGDPR;

/// UMP 维度的 GDPR 判断结果。
/// 当这个值为 YES 时，说明 Google UMP 已经明确认为当前用户需要 GDPR 同意流程，
/// showConsentDialog 会优先使用 UMP 展示。
@property (nonatomic, assign, readonly) BOOL subjectUMPGDPR;

/// GDPR 三态结果。
/// Unknown：还没有足够信息判断，例如 UMP 未返回、MAX 也未初始化完成；
/// Support：用户处于 GDPR 区域，需要展示同意弹窗；
/// NotSupport：用户不处于 GDPR 区域，不需要展示同意弹窗。
@property (nonatomic, assign, readonly) OxGdprRegion gdprThreeStatus;

/// 本次 GDPR 初始化标识。
/// 使用毫秒时间戳生成，主要用于埋点排查一次初始化从开始到结束的链路。
@property (nonatomic, assign, readonly) NSInteger initTag;

/// 初始化 GDPR 检测链路。
///
/// 参数说明：
/// viewController：当前调用方传入的页面，保留参数位，当前内部初始化不直接使用它；
/// privacyPolicyLink：隐私政策链接，会保存到 privacyPolicyLink；
/// callback：当 GDPR 区域结果明确后回调，参数表示是否受 GDPR 约束。
///
/// 注意：callback 不一定马上回调。
/// 如果 UMP 和 MAX/CMP 都还没有返回有效结果，会先保持 Unknown，
/// 等网络恢复、UMP 重试或 MAX 初始化完成后再回调。
- (void)initializeWithViewController:(nullable UIViewController *)viewController
                   privacyPolicyLink:(nullable NSString *)privacyPolicyLink
                            callback:(nullable InternalConsentResultCallback)callback;

/// 聚合平台初始化完成时由 SDK 初始化流程通知进来。
/// 主要用于 MAX 聚合场景：MAX SDK 没初始化完成前，CMP 状态不可完全相信；
/// 初始化完成后需要重新执行一次 GDPR 决策。
- (void)onMediationInitialized:(Platform)mediation;

/// 添加 GDPR 检测结果监听。
/// 如果当前结果还没出来，listener 会被暂存，等结果明确后统一回调；
/// 如果结果已经明确，会立刻回调一次，不会让调用方错过结果。
- (void)addConsentResultListener:(InternalConsentResultCallback)listener;

/// 移除 GDPR 检测结果监听。
/// 用于调用方不再关心结果时取消监听，避免无意义回调。
- (void)removeConsentResultListener:(InternalConsentResultCallback)listener;

/// 查询用户是否受 GDPR 约束。
/// 这个方法只返回当前已经计算出的结果，不会主动重新请求 UMP 或 MAX。
/// 调用时会记录一次查询埋点。
- (BOOL)isSubjectToGDPR;

/// 用户是否已经关闭过 GDPR 弹窗。
/// 这个值用于区分新用户和老用户：
/// 老用户在 UMP 临时失败时，可以使用上一次缓存的 UMP 状态做兜底。
- (BOOL)hasClosedGDPRDialog;

/// 展示当前可用的 GDPR 同意弹窗。
///
/// 展示优先级：
/// 1. 如果 UMP 判断可用，展示 UMP；
/// 2. 如果 UMP 不可用但 MAX/CMP 可用，展示 MAX/CMP；
/// 3. 如果当前没有可用的 manager，返回 NO。
///
/// force 表示是否强制展示；
/// dismiss 会在弹窗关闭后回调。
- (BOOL)showConsentDialog:(UIViewController *)viewController
                    force:(BOOL)force
                  dismiss:(nullable ConsentDialogDismissCallback)dismiss;

/// 读取当前 GDPR 三态结果，不触发埋点。
/// 主要给内部或桥接层直接查看当前状态使用。
- (NSInteger)peekGdprThreeStatus;

/// 获取 UMP 状态码，用于埋点和日志诊断。
/// 1：available，UMP 可用；
/// 2：unavailable，UMP 明确不可用；
/// 3：error，UMP 请求或初始化失败；
/// 0：unknown，还没有结果。
- (NSInteger)getUmpStateCode;

/// 获取 MAX/CMP 状态码，用于埋点和日志诊断。
/// 1：available，CMP 可用；
/// 2：unavailable，CMP 明确不可用；
/// 0：unknown 或 error。
- (NSInteger)getMaxStateCode;

/// 获取最终 GDPR 地理状态码，用于埋点和日志诊断。
/// 返回值对应 gdprThreeStatus。
- (NSInteger)getGdprGeoStateCode;

/// 获取当前实际使用的 GDPR 工具。
/// 返回 UMP 表示当前会使用 Google UMP；
/// 返回 CMP 表示当前会使用 MAX/CMP；
/// 返回 nil 表示当前还没有可用工具，或者不需要展示 GDPR 弹窗。
- (nullable NSString *)getGdprTool;

/// 获取 iOS ATT 授权状态。
/// iOS 14.5 及以上返回 ATTrackingManager 的状态；
/// iOS 14.5 以下系统没有 ATT，返回 -1。
- (NSInteger)getATTState;

@end

NS_ASSUME_NONNULL_END
