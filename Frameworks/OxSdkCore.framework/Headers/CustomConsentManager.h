//
//  CustomConsentManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^CustomConsentDismissCallback)(void);

@interface CustomConsentManager : NSObject

extern NSString * const CustomConsentManagerGDPRStatusKey;

+ (instancetype)sharedInstance;

@property (nonatomic, assign, getter=isShowDialog) BOOL showDialog;
@property (nonatomic, assign) BOOL showConsentDialog;

- (void)initIsShowValue:(BOOL)isShow;
- (void)showConsentDialog:(UIViewController *)viewController dismiss:(nullable CustomConsentDismissCallback)dismiss;
- (void)showPrivacyDialog:(UIViewController *)viewController dismiss:(nullable CustomConsentDismissCallback)dismiss;

- (BOOL)isConsentReject;
- (BOOL)isConsentAccept;
- (BOOL)isConsentUnset;
- (NSInteger)getConsentStatus;
- (void)setConsentStatus:(NSInteger)status;
- (BOOL)hasClosedGDPRDialog;

@end

NS_ASSUME_NONNULL_END
