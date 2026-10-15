//
//  OxPangleBannerAd.h
//  OxSdkCore
//

#import "OxAd.h"
#import "BannerInternalAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxPangleBannerAd : OxAd

- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                viewController:(UIViewController *)viewController
                     placement:(NSString *)placement
              internalListener:(id<BannerInternalAdDelegate>)internalListener
                    requestTag:(long long)requestTag;

- (void)showAd:(UIView *)adContainer placement:(NSString *)placement;
- (void)hidAd;

@end

NS_ASSUME_NONNULL_END
