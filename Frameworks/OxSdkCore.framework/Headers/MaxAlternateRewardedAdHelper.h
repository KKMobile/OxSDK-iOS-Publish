//
//  MaxAlternateRewardedAdHelper.h
//  OxSdkCore
//

#import "OxRewardedAdHelper.h"

@class OxRewardedAd;

NS_ASSUME_NONNULL_BEGIN

typedef void (^MaxAlternateRewardedLoadSuccessCallback)(OxRewardedAd *ad);
typedef void (^MaxAlternateRewardedLoadFailureCallback)(NSString *adUnitId, NSString * _Nullable error);

@interface MaxAlternateRewardedAdHelper : OxRewardedAdHelper

@property (nonatomic, copy, nullable) MaxAlternateRewardedLoadSuccessCallback alternateLoadSuccessCallback;
@property (nonatomic, copy, nullable) MaxAlternateRewardedLoadFailureCallback alternateLoadFailureCallback;

- (instancetype)initWithCurrentVC:(UIViewController *)vc adUnitId:(NSString *)adunitId;

- (void)callAdLoadSuccess;
- (double)getHighestPrice;
- (nullable NSString *)getHighestPriceAdUnitId;
- (nullable NSString *)getHighestPriceNetworkName;
- (BOOL)isIsLoading;

@end

NS_ASSUME_NONNULL_END
