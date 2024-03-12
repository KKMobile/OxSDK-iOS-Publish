//
//  OxAdSdkConsentManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OxAdSdk.h"

typedef enum : NSUInteger {
    GDPRTool_Max = 0,
    GDPRTool_Admob = 1,
} GDPRTool;

NS_ASSUME_NONNULL_BEGIN

typedef void (^GDPRDismiss)(void);

@interface OxConsentMananger : NSObject

@property(nonatomic, copy)NSString *privacyPolicyLink;

+ (nonnull instancetype)sharedInstance;

- (void)initialize:(GDPRTool)defaultGDPRTool privacyPolicyLink:(NSString *)privacyPolicyLink consentCheckResultCallback:(void (^)(BOOL))consentCheckResultCallback;

/// 展示 GDPRUI
/// - Parameters:
///   - viewController: 需要展示的界面
///   - force: 是否为设置界面 (YES=设置界面)
///   - dismiss: 关闭回调
- (BOOL)showConsentDialog:(UIViewController *)viewController force:(BOOL)force dismiss:(nullable GDPRDismiss)dismiss;

/// 是否是可以展示GDPR的地区/国家  在设置界面使用的时候需要客户端自己判断ATT状态
- (BOOL)isSubjectToGDPR;

/// Max 下 SDK 初始化成功
- (void)onMediationInitialized:(OxSdkMediationType)mediation;

@end

NS_ASSUME_NONNULL_END