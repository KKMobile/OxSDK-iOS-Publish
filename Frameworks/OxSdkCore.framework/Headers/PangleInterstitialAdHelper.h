//
//  PangleInterstitialAdHelper.h
//  OxSdkCore
//

#import "OxInterstitialAdHelper.h"

@class OxInterstitialAd;

NS_ASSUME_NONNULL_BEGIN

typedef void (^PangleInterstitialLoadCallback)(OxInterstitialAd *ad);
typedef void (^PangleInterstitialLoadFailureCallback)(NSString *adUnitId, NSString * _Nullable error);

@interface PangleInterstitialAdHelper : OxInterstitialAdHelper

@property (nonatomic, copy, nullable) PangleInterstitialLoadCallback pangleLoadCallback;
@property (nonatomic, copy, nullable) PangleInterstitialLoadFailureCallback pangleLoadFailureCallback;

- (instancetype)initWithCurrentVC:(UIViewController *)vc adUnitId:(NSString *)adunitId;

- (void)callAdLoadSuccess;
- (double)getHighestPrice;
- (nullable NSString *)getHighestPriceAdUnitId;
- (nullable NSString *)getHighestPriceNetworkName;
- (BOOL)isIsLoading;

@end

NS_ASSUME_NONNULL_END
