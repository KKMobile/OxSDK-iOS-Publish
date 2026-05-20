//
//  OxAdSdkConsentManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OxAdSdkManager.h"
#import "BaseConsentManager.h"

NS_ASSUME_NONNULL_BEGIN
// GdprRegion 地区
typedef NS_ENUM(NSUInteger, OxGdprRegion) {
    OxGdprRegionUnknown = 0,      ///< Gdpr 地区未获取到
    OxGdprRegionSupport = 1,     ///<  是 Gdpr地区
    OxGdprRegionNotSupport = 2,  ///<  不是 Gdpr地区
};

typedef void(^GDPRInitCompletionCallback)(void);
typedef void(^GDPRStateChangeCallback)(void);

@interface OxConsentMananger : NSObject

+ (nonnull instancetype)sharedInstance;

/// 初始化GDPR
/// - Parameters:
///   - privacyPolicyLink: Max GDPR 的隐私政策链接
///   - completion: 初始化完成回调
///   - stateChangeCallback: GDPR状态变化回调
- (void)initializeWithPrivacyPolicyLink:(NSString *)privacyPolicyLink
        completion:(GDPRInitCompletionCallback)completion
stateChangeCallback:(GDPRStateChangeCallback)stateChangeCallback;

/// 展示 GDPRUI  展示之前不用判断 isSubjectToGDPR
/// - Parameters:
///   - viewController: 需要展示的界面
///   - force: 是否为设置界面 (YES=设置界面)
///   - dismiss: 关闭回调
- (BOOL)showConsentDialog:(UIViewController *)viewController force:(BOOL)force dismiss:(nullable ConsentDialogDismissCallback)dismiss;

/// 是否是可以展示GDPR的地区/国家 
- (OxGdprRegion)isSubjectToGDPR;
- (NSInteger)getGdprThreeStatus;
@end

NS_ASSUME_NONNULL_END
