//
//  OxAdSdkConsentManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OxAdSdkManager.h"

typedef enum : NSUInteger {
    GDPRTool_Max = 0,
    GDPRTool_Admob = 1,
} GDPRTool;

NS_ASSUME_NONNULL_BEGIN

typedef void (^GDPRDismiss)(void);

@interface OxConsentMananger : NSObject

@property(nonatomic, copy)NSString *privacyPolicyLink;

+ (nonnull instancetype)sharedInstance;

/// 初始化GDPR
/// - Parameters:
///   - defaultGDPRTool: 默认使用的 GDPR 平台
///   - privacyPolicyLink: Max GDPR 的隐私政策链接
///   - consentCheckResultCallback: 是否受到GDPR影响回调
- (void)initialize:(GDPRTool)defaultGDPRTool privacyPolicyLink:(NSString *)privacyPolicyLink consentCheckResultCallback:(void (^)(BOOL isSubjectToGDPR))consentCheckResultCallback;

/// 展示 GDPRUI  展示之前不用判断 isSubjectToGDPR
/// - Parameters:
///   - viewController: 需要展示的界面
///   - force: 是否为设置界面 (YES=设置界面)
///   - dismiss: 关闭回调
- (BOOL)showConsentDialog:(UIViewController *)viewController force:(BOOL)force dismiss:(nullable GDPRDismiss)dismiss;

/// 是否是可以展示GDPR的地区/国家
- (BOOL)isSubjectToGDPR;

/// Max 下 SDK 初始化成功
- (void)onMediationInitialized:(OxSdkMediationType)mediation;


@end

NS_ASSUME_NONNULL_END
