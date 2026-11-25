//
//  OxAdSdkInitOptions.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"
#import "BaseAdManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^OxConsentCheckResultBlock)(BOOL isSubjectToGDPR);

@class OxAdSdkInitOptionsBuilder;

@interface OxAdSdkInitOptions : NSObject

@property (nonatomic, copy, readonly, nullable) NSString *appId;
@property (nonatomic, copy, readonly, nullable) NSString *privacyPolicyLink;
@property (nonatomic, assign, readonly) Platform fallbackMediationPlatform;
@property (nonatomic, copy, readonly, nullable) OnSdkInitComplete initializationCompleteBlock;
@property (nonatomic, copy, readonly, nullable) OnSdkInitFailed initializationFailedBlock;
@property (nonatomic, copy, readonly, nullable) OxConsentCheckResultBlock consentCheckResultBlock;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (OxAdSdkInitOptionsBuilder *)builderWithAppId:(nullable NSString *)appId;

@end

@interface OxAdSdkInitOptionsBuilder : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithAppId:(nullable NSString *)appId NS_DESIGNATED_INITIALIZER;
- (instancetype)setPrivacyPolicyLink:(nullable NSString *)privacyPolicyLink;
- (instancetype)setFallbackMediationPlatform:(Platform)fallbackMediationPlatform;
- (instancetype)setInitializationCompleteBlock:(nullable OnSdkInitComplete)initializationCompleteBlock;
- (instancetype)setInitializationFailedBlock:(nullable OnSdkInitFailed)initializationFailedBlock;
- (instancetype)setConsentCheckResultBlock:(nullable OxConsentCheckResultBlock)consentCheckResultBlock;
- (OxAdSdkInitOptions *)build;

@end

NS_ASSUME_NONNULL_END
