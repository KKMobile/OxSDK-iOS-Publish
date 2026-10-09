//
//  OxAdSdkConsentManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdEvents.h"
#import "BaseConsentManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, OxGdprRegion) {
    OxGdprRegionUnknown = 0,
    OxGdprRegionSupport = 1,
    OxGdprRegionNotSupport = 2,
};

typedef void(^GDPRInitCompletionCallback)(void);
typedef void(^OxConsentCheckResultCallback)(BOOL isSubjectToGDPR);

@interface OxConsentMananger : NSObject

@property(nonatomic, copy, nullable) NSString *privacyPolicyLink;
@property(nonatomic, assign, readonly) NSInteger tag;

+ (nonnull instancetype)sharedInstance;

/// 初始化GDPR
/// - Parameters:
///   - privacyPolicyLink: Max GDPR 的隐私政策链接
///   - completion: 初始化完成回调
///   - stateChangeCallback: GDPR状态变化回调
- (void)initializeWithPrivacyPolicyLink:(NSString *)privacyPolicyLink
        completion:(GDPRInitCompletionCallback)completion;

- (void)initializeWithViewController:(nullable UIViewController *)viewController
                   privacyPolicyLink:(nullable NSString *)privacyPolicyLink
               consentResultCallback:(nullable OxConsentCheckResultCallback)callback;

- (void)setPrivacyPolicyLink:(nullable NSString *)privacyPolicyLink;

/// 添加 GDPR 结果监听；若结果已解析完成，会立即回调。
- (void)addConsentResultListener:(OxConsentCheckResultCallback)listener;

/// 移除 GDPR 结果监听。
- (void)removeConsentResultListener:(OxConsentCheckResultCallback)listener;

/// 展示 GDPRUI  展示之前不用判断 isSubjectToGDPR
/// - Parameters:
///   - viewController: 需要展示的界面
///   - force: 是否为设置界面 (YES=设置界面)
///   - dismiss: 关闭回调
- (BOOL)showConsentDialog:(UIViewController *)viewController force:(BOOL)force dismiss:(nullable ConsentDialogDismissCallback)dismiss;

/// 是否是可以展示GDPR的地区/国家 
- (OxGdprRegion)isSubjectToGDPR;
- (BOOL)hasClosedGDPRDialog;
- (NSInteger)getGdprThreeStatus;

/// 聚合 SDK 初始化完成后刷新 GDPR 平台兜底状态
- (void)onMediationInitialized:(Platform)mediation;
@end

NS_ASSUME_NONNULL_END
