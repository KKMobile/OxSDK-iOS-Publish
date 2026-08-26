//
//  OxPangleRewardedAd.h
//  OxSdkCore
//

#import "OxRewardedAd.h"
#import "RewardedInternalAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxPangleRewardedAd : OxRewardedAd

- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                viewController:(UIViewController *)viewController
                     placement:(NSString *)placement
              internalListener:(id<RewardedInternalAdDelegate>)internalListener
                    requestTag:(long long)requestTag
                        layers:(NSInteger)layers;

- (void)showAd:(NSString *)placement;
- (void)callAdLoadSuccess;

@end

NS_ASSUME_NONNULL_END
