//
//  OxMaxBannerAd.h
//  OxSdkCore
//

#import "OxBannerAd.h"

@class OxPlacementParams, IdConfig;
@protocol AdInternalListener;

NS_ASSUME_NONNULL_BEGIN

@interface OxMaxBannerAd : OxBannerAd

@property (nonatomic, assign) BOOL adaptive;

- (instancetype)initWithPlacementParams:(OxPlacementParams *)placementParams
                               idConfig:(IdConfig *)idConfig
                         viewController:(nullable UIViewController *)viewController
                      internalListener:(nullable id<AdInternalListener>)listener;

- (void)setAutoRefreshEnabled:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
