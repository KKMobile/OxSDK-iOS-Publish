//
//  OxAdmobBannerAd.h
//  OxSdkCore
//

#import "OxBannerAd.h"

@class OxPlacementParams, IdConfig;
@protocol AdInternalListener;

NS_ASSUME_NONNULL_BEGIN

@interface OxAdmobBannerAd : OxBannerAd

- (instancetype)initWithPlacementParams:(OxPlacementParams *)placementParams
                               idConfig:(IdConfig *)idConfig
                         viewController:(nullable UIViewController *)viewController
                      internalListener:(nullable id<AdInternalListener>)listener;

@end

NS_ASSUME_NONNULL_END
