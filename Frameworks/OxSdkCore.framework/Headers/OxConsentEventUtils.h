//
//  OxConsentEventUtils.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/11/7.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    OxConsentStatusUnknown = 0,      ///< Unknown consent status.
    OxConsentStatusRequired = 1,     ///< User consent required but not yet obtained.
    OxConsentStatusNotRequired = 2,  ///< Consent not required.
    OxConsentStatusObtained = 3
} OxConsentStatus;

@interface OxConsentEventUtils : NSObject


/// GDPR 开始初始化打点
+ (void)trackGDPRBeginInit;

/// GDPR 初始化结束打点
+ (void)trackGDPREndInit:(NSString *)error;

/// MAX 初始化的时间
/// @param startTime 开始初始化的时间点
+ (void)trackMaxBeginInit:(NSTimeInterval)startTime;

/// Geo Consent 状态更新打点
/// @param startTime 开始初始化的时间
+ (void)trackMaxGDPRStateUpdate:(NSTimeInterval)startTime;


/// 获取 GDPR 状态时候的打点
/// @param isSubjectToGDPR 是否允许展示 gdpr
+ (void)trackGDPRGetIsSubjectToGDPR:(BOOL)isSubjectToGDPR;

/// Geo Consent 状态更新打点
//+ (void)trackGeoConsentUpdate;


/// 展示 GDPR 弹窗打点
/// @param force 是否强制展示
/// @param canShow 是否允许展示
/// @param error canShow 为 NO 时的原因，canShow 为 YES 时传 nil
+ (void)tarckGDPRShow:(BOOL)force canShow:(BOOL)canShow error:(nullable NSString *)error;

/// GDPR 弹窗展示中打点
/// @param force 是否强制展示
/// @param canShow 是否允许展示
+ (void)tarckGDPRShowing:(BOOL)force canShow:(BOOL)canShow;

/// GDPR 弹窗关闭 / 消失打点
/// @param force 是否强制展示
/// @param consentState 当前 GDPR 状态
/// @param error 错误信息
/// @param isAccept 是否是点击 Accept 进来的
+ (void)tarckGDPRDissmiss:(BOOL)force consentState:(OxConsentStatus)consentState isAccept:(BOOL)isAccept error:(nullable NSString *)error;

#pragma mark - CMP UI 相关事件

/// CMP 页面展示隐私政策打点
/// @param force 是否强制展示
/// @param inType 进入来源类型
+ (void)trackGDPRCMPShowPrivacy:(BOOL)force inType:(NSInteger)inType;

/// CMP 页面点击“更多选项”打点
/// @param force 是否强制展示
+ (void)trackGDPRCMPPrivacyClickMore:(BOOL)force;

/// CMP 页面点击“同意”按钮打点
/// @param force 是否强制展示
+ (void)trackGDPRCMPPrivacyClickAccpet:(BOOL)force;

/// CMP 页面展示选项页打点
/// @param force 是否强制展示
+ (void)trackGDPRCMPShowOption:(BOOL)force;

/// CMP 页面更改同意状态打点
/// @param force 是否强制展示
/// @param consentState 当前同意状态
+ (void)trackGDPRCMPChangeConsentState:(BOOL)force consentState:(OxConsentStatus)consentState;

/// CMP 页面点击返回按钮打点
/// @param force 是否强制展示
+ (void)trackGDPRCMPClickBack:(BOOL)force;

/// CMP 页面点击保存按钮打点
/// @param force 是否强制展示
/// @param consentState 当前同意状态
+ (void)trackGDPRCMPClickSave:(BOOL)force consentState:(OxConsentStatus)consentState;

@end

NS_ASSUME_NONNULL_END
