//
//  AdLoadRequestPolicy.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class OxAd;

NS_ASSUME_NONNULL_BEGIN

@interface AdLoadRequestPolicy : NSObject
- (nullable NSString *)restrictionKeyForAd:(nullable OxAd *)ad;
@end

NS_ASSUME_NONNULL_END
