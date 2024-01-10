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

NS_ASSUME_NONNULL_BEGIN

typedef void (^ConsentDialogDismissCallback)( NSError * _Nullable error);


@interface BaseConsentManager : NSObject

- (instancetype)init:(void (^)(BOOL isSubjectToGDRP))consentCheckResultCallback;

- (BOOL)isSubjectToGDPR;

/// 展示 GDPRUI
/// - Parameters:
///   - viewController: 需要展示的界面
///   - force: 是否为设置界面 (YES=设置界面)
///   - dismiss: 关闭回调
- (BOOL)showConsentDialog:(UIViewController *)viewController force:(BOOL)force consentDialogDismissCallback:(nullable ConsentDialogDismissCallback)consentDialogDismissCallback;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
