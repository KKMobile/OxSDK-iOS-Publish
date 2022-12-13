// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "OxMediationAdFormats.h"
#import "OMImpressionDataDelegate.h"


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, OMGender) {
    OMGenderUnknown,
    OMGenderMale,
    OMGenderFemale,
};

typedef NS_ENUM(NSInteger, OMConsentStatus) {
    OMConsentStatusUnknown,
    OMConsentStatusDenied,
    OMConsentStatusConsented,
};

typedef void(^initCompletionHandler)(NSError *_Nullable error);

///OpenMeidation init success notification
extern NSString *kOpenMediatonInitSuccessNotification;

@interface OxMediation : NSObject

@property(nonatomic,copy) initCompletionHandler completionHandler;

+ (instancetype)sharedInstance;

- (void)initWithAppKey:(NSString*)appKey baseHost:(NSString*)host completionHandler:(initCompletionHandler)completionHandler;

/// Check that `OpenMediation` has been initialized
+ (BOOL)isInitialized;

/// user in-app purchase
+ (void)userPurchase:(CGFloat)amount currency:(NSString*)currencyUnit;

/// Set this property to configure the user's age.
+ (void)setUserAge:(NSInteger)userAge;

/// Set custom user id
+ (void)setUserID:(NSString*)userID;

/// Get custom user id
+ (NSString*)getUserID;

/// Set custom tag
+ (void)setCustomTag:(NSString*)tag withString:(NSString*)value;

+ (void)setCustomTag:(NSString*)tag withNumber:(NSNumber*)value;

+ (void)setCustomTag:(NSString*)tag withStrings:(NSArray *)values;

+ (void)setCustomTag:(NSString*)tag withNumbers:(NSArray *)values;

+ (void)removeTag:(NSString*)tag;

+ (NSDictionary*)allCustomTags;

/// Set the gender of the current user
+ (void)setUserGender:(OMGender)userGender;

///Send conversion attribution data to server
+ (void)sendAFConversionData:(NSDictionary*)conversionInfo;

///Send  deep link attribution data to server
+ (void)sendAFDeepLinkData:(NSDictionary*)attributionData;

///Add Impression Data delegate
+ (void)addImpressionDataDelegate:(id<OMImpressionDataDelegate>)delegate;

///Remove Impression Data delegate
+ (void)rmoveImpressionDataDelegate:(id<OMImpressionDataDelegate>)delegate;

/// setUserConsent "NO" is Refuse，"YES" is Accepted. //GDPR
/// According to the GDPR, set method of this property must be called before "initWithAppKey:", or by default will collect user's information.
+ (void)setGDPRConsent:(BOOL)consent;

/// Get the GDPR current consent status of this user.
+ (OMConsentStatus)currentConsentStatus;

/// According to the CCPA, set method of this property must be called before "initWithAppKey:", or by default will collect user's information.
+ (void)setUSPrivacyLimit:(BOOL)privacyLimit;

/// If you call this method with YES, you are indicating that your app should be treated as child-directed for purposes of the Children’s Online Privacy Protection Act (COPPA).
/// If you call this method with NO, you are indicating that your app should not be treated as child-directed for purposes of the Children’s Online Privacy Protection Act (COPPA).
+ (void)setUserAgeRestricted:(BOOL)restricted;

/// current SDK version
+ (NSString *)SDKVersion;

/// A tool to verify a successful integration of the OpenMediation SDK and any additional adapters.
+ (void)validateIntegration;

/// log enable,default is YES
+ (void)setLogEnable:(BOOL)logEnable;

+ (void)setUseCacheAdFormat:(OxMediationAdFormat)useCacheAdFormat;

/// set auto cache,default is YES
+ (void)setAutoCache:(BOOL)autoCache;

@end

NS_ASSUME_NONNULL_END
