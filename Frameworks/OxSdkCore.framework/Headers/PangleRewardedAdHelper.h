//
//  PangleRewardedAdHelper.h
//  OxSdkCore
//

#import "OxRewardedAdHelper.h"

@class OxRewardedAd;

NS_ASSUME_NONNULL_BEGIN

typedef void (^PangleLoadCallback)(OxRewardedAd *ad);
typedef void (^PangleLoadFailureCallback)(NSString *adUnitId, NSString * _Nullable error);

@interface PangleRewardedAdHelper : OxRewardedAdHelper

@property (nonatomic, copy, nullable) PangleLoadCallback pangleLoadCallback;
@property (nonatomic, copy, nullable) PangleLoadFailureCallback pangleLoadFailureCallback;

- (instancetype)initWithCurrentVC:(UIViewController *)vc adUnitId:(NSString *)adunitId;

- (void)callAdLoadSuccess;
- (double)getHighestPrice;
- (nullable NSString *)getHighestPriceAdUnitId;
- (nullable NSString *)getHighestPriceNetworkName;
- (BOOL)isIsLoading;

@end

NS_ASSUME_NONNULL_END
