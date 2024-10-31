//
//  OxAdSdkConsentManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/18.
//

#import <OxSdkForGames/BaseConsentManager.h>
#import <OxSdkForGames/AdEvents.h>

typedef enum : NSUInteger {
    ConsentEntryTypeNormal,
    ConsentEntryTypeAbout,
} ConsentEntryType;

NS_ASSUME_NONNULL_BEGIN

@interface MaxConsentManager : BaseConsentManager

- (void)onMediationInitialized:(Platform)mediation;

//
+ (BOOL)isConsentRejected;

+ (BOOL)isConsentAccepted;

+ (BOOL)isConsentUnSet;


@end

NS_ASSUME_NONNULL_END
