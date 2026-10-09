//
//  GoogleConsentManager.h
//  OxSdkCore
//

#import "BaseConsentManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface GoogleConsentManager : BaseConsentManager

- (BOOL)isPersonalizedAdsConsentGranted;

@end

NS_ASSUME_NONNULL_END
