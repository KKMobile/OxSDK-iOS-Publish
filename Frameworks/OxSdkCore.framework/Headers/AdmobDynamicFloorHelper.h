//
//  AdmobDynamicFloorHelper.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class GADRequest, GADResponseInfo, IdConfig, OxPlacementParams;

NS_ASSUME_NONNULL_BEGIN

/// Applies the Android-compatible `extraParameters.admobDynamic` mapping to a
/// Google Mobile Ads request and returns the effective eCPM in USD.
@interface AdmobDynamicFloorHelper : NSObject

+ (double)applyToRequest:(GADRequest *)request
                idConfig:(IdConfig *)idConfig
         placementParams:(OxPlacementParams *)placementParams
                 logTag:(NSString *)logTag
                adType:(NSString *)adType;

+ (nullable NSString *)waterfallNameFromResponseInfo:(nullable GADResponseInfo *)responseInfo;
+ (nullable NSString *)networkPlacementFromResponseInfo:(nullable GADResponseInfo *)responseInfo;
+ (nullable NSString *)creativeIdentifierFromResponseInfo:(nullable GADResponseInfo *)responseInfo;

@end

NS_ASSUME_NONNULL_END
