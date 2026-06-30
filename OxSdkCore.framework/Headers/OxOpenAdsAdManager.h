//
//  OxOpenAdsAdManager.h
//  OxSdkCore
//

#import "OxAdManager.h"
#import "IFullScreenAd.h"
#import "OpenAdsAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxOpenAdsAdManager : OxAdManager <IFullScreenAd>

+ (instancetype)createAdWithViewController:(UIViewController *)viewController
                                 adUnitName:(NSString *)adUnitName;

- (void)showAd;
- (void)showAd:(NSString *)placement;

@end

NS_ASSUME_NONNULL_END
