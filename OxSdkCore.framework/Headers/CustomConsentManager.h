//
//  CustomConsentManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CustomConsentStatus) {
    CustomConsentStatusUnknown = -1,
    CustomConsentStatusReject = 0,
    CustomConsentStatusAccept = 1,
};

@protocol CustomConsentStatusListener <NSObject>
- (void)onConsentAccept;
- (void)onConsentReject;
- (void)onConsentUnknown;
@end

typedef void (^CustomConsentDismissBlock)(void);

@interface CustomConsentManager : NSObject

@property (nonatomic, assign) BOOL showConsentDialog;
@property (nonatomic, assign, readonly) BOOL isShowDialog;

+ (instancetype)sharedInstance;

- (void)initIsShowValue:(BOOL)isShow;
- (void)addStatusListener:(id<CustomConsentStatusListener>)listener;
- (void)removeStatusListener:(id<CustomConsentStatusListener>)listener;
- (void)removeAllListener;

- (void)showConsentDialogFromViewController:(UIViewController *)viewController onDismiss:(nullable CustomConsentDismissBlock)onDismiss;
- (void)showPrivacyDialogFromViewController:(UIViewController *)viewController onDismiss:(nullable CustomConsentDismissBlock)onDismiss;
- (void)onDismiss;

- (BOOL)isConsentReject;
- (BOOL)isConsentAccept;
- (BOOL)isConsentUnset;

- (void)setConsentAccepted;
- (void)setConsentRejected;
- (void)setConsentUnknown;
- (void)resetConsent;

+ (nullable NSString *)privacyPolicyLink;

@end

NS_ASSUME_NONNULL_END
