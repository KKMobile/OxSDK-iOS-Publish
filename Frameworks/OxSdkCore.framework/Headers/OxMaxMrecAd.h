//
//  OxMaxMrecAd.h
//  OxSdkCore
//

#import "OxMrecAd.h"

@class OxPlacementParams, IdConfig;
@protocol AdInternalListener;

NS_ASSUME_NONNULL_BEGIN

@interface OxMaxMrecAd : OxMrecAd

- (instancetype)initWithPlacementParams:(OxPlacementParams *)placementParams
                               idConfig:(IdConfig *)idConfig
                         viewController:(nullable UIViewController *)viewController
                      internalListener:(nullable id<AdInternalListener>)listener;

- (void)setAutoRefreshEnabled:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
