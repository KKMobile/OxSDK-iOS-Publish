//
//  MaxAlternateInterstitialAdHelper.h
//  OxSdkCore
//

#import "OxInterstitialAdHelper.h"

@class OxInterstitialAd;

NS_ASSUME_NONNULL_BEGIN

typedef void (^MaxAlternateInterstitialLoadSuccessCallback)(OxInterstitialAd *ad);
typedef void (^MaxAlternateInterstitialLoadFailureCallback)(NSString *adUnitId, NSString * _Nullable error);

@interface MaxAlternateInterstitialAdHelper : OxInterstitialAdHelper

@property (nonatomic, copy, nullable) MaxAlternateInterstitialLoadSuccessCallback alternateLoadSuccessCallback;
@property (nonatomic, copy, nullable) MaxAlternateInterstitialLoadFailureCallback alternateLoadFailureCallback;

- (instancetype)initWithCurrentVC:(UIViewController *)vc adUnitId:(NSString *)adunitId;

- (void)callAdLoadSuccess;
- (double)getHighestPrice;
- (nullable NSString *)getHighestPriceAdUnitId;
- (nullable NSString *)getHighestPriceNetworkName;
- (BOOL)isIsLoading;

@end

NS_ASSUME_NONNULL_END
