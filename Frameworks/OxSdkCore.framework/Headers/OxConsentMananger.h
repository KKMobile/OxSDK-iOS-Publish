//
//  OxAdSdkConsentManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BaseConsentManager.h"
#import "GoogleConsentManager.h"
#import "SFBXConsentManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^GDPRDismiss)(void);

@interface OxConsentMananger : NSObject


+ (nonnull instancetype)sharedInstance;

- (void)initialize:(NSInteger)googleWeight sfbxWeight:(double)sfbxWeight sfbxAppKey:(NSString *)sfbxAppKey consentCheckResultCallback:(void (^)(BOOL isSubjectToGDRP))consentCheckResultCallback;

/// 展示 GDPRUI
/// - Parameters:
///   - viewController: 需要展示的界面
///   - force: 是否为设置界面 (YES=设置界面)
///   - dismiss: 关闭回调
- (BOOL)showConsentDialog:(UIViewController *)viewController force:(BOOL)force dismiss:(nullable GDPRDismiss)dismiss;

/// 是否是可以展示GDPR的地区/国家
- (BOOL)isSubjectGDPR;

@end

NS_ASSUME_NONNULL_END
