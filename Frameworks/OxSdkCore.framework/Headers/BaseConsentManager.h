//
//  BaseConsentManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2023/7/28.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GDPRConsentants.h"
#import "AppUtils.h"
#import "OXLogMoudle.h"
#import "OxConsentEventUtils.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    OxGDPRFormSteteUnknown = 0,  // 未拿到数据，可能原因 未初始化 或者初始化失败
    OxGDPRFormSteteAvailable = 1, //  GDPR 可用
    OxGDPRFormSteteUnavailable = 2, // GDPR 不可用
} OxGDPRFormStete;

typedef void (^ConsentDialogDismissCallback)(void);


@interface BaseConsentManager : NSObject

- (instancetype)init:(BOOL)reset consentCheckResultCallback:(nullable void (^)(BOOL isSubjectToGDPR,NSString * _Nullable error))consentCheckResultCallback;

- (BOOL)isSubjectToGDPR;

/// 展示 GDPRUI
/// - Parameters:
///   - viewController: 需要展示的界面
///   - force: 是否为设置界面 (YES=设置界面)
///   - dismiss: 关闭回调
- (BOOL)showConsentDialog:(UIViewController *)viewController force:(BOOL)force consentDialogDismissCallback:(nullable ConsentDialogDismissCallback)consentDialogDismissCallback;

- (OxGDPRFormStete)getState;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
