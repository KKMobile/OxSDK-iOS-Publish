//
//  OxPangleInterstitialAd.h
//  OxSdkCore
//

#import "OxInterstitialAd.h"
#import "InterstitialInternalAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxPangleInterstitialAd : OxInterstitialAd

- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                viewController:(UIViewController *)viewController
                     placement:(NSString *)placement
              internalListener:(id<InterstitialInternalAdDelegate>)internalListener
                    requestTag:(long long)requestTag
                        layers:(NSInteger)layers;

- (void)showAd:(NSString *)placement;
- (void)callAdLoadSuccess;

@end

NS_ASSUME_NONNULL_END
