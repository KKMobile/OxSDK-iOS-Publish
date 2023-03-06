//
//  OxAdSdkConsentManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import "ConsentStatusDelegate.h"

typedef enum : NSUInteger {
    ConsentEntryTypeNormal,
    ConsentEntryTypeAbout,
} ConsentEntryType;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdSdkConsentManager : NSObject

@property (nonatomic, weak) id<ConsentStatusDelegate>  mStatusDelegate;

+ (nonnull instancetype)sharedInstance;

- (void)showPrivacyDialog;

// 需要在主线程中操作
- (BOOL)isShowPrivace;

- (void)showConsentDialog;

// 需要在主线程中操作
- (BOOL)isShowConsent;

- (void)showConsentDialog:(ConsentEntryType)entryType;

- (BOOL)isGDPRSupported;

- (BOOL)isConsentRejected;

- (BOOL)isConsentAccepted;

- (BOOL)isConsentUnSet;

- (void)consentAccepted;

- (void)consentRejected;

- (void)consentUnknown;

@end

NS_ASSUME_NONNULL_END
