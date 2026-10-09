//
//  MaxConsentManager.h
//  OxSdkCore
//

#import "BaseConsentManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface MaxConsentManager : BaseConsentManager

- (void)onMediationInitialized;
- (BOOL)isSubjectToGDPR;
- (void)initIsShowValue:(BOOL)isShow;

@end

NS_ASSUME_NONNULL_END
