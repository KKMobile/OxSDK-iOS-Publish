//
//  OxAdSdkConsentManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import "ConsentStatusDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdSdkConsentManager : NSObject

@property (nonatomic, weak) id<ConsentStatusDelegate>  mStatusDelegate;

+ (nonnull instancetype)sharedInstance;

- (void)showPrivacyDialog;

- (void)showConsentDialog;

- (BOOL)isGDPRSupported;

- (BOOL)isConsentRejected;

- (BOOL)isConsentAccepted;

- (BOOL)isConsentUnSet;

- (void)consentAccepted;

- (void)consentRejected;

- (void)consentUnknown;

@end

NS_ASSUME_NONNULL_END
