//
//  BaseAdManagerUtils.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class OxPlacementParams, OxAd, IdConfig;
@protocol AdInternalListener;

NS_ASSUME_NONNULL_BEGIN

@interface BaseAdManagerUtils : NSObject

+ (void)handleNetworkChangeWithConnectivity:(BOOL)connectivity
                                    isReady:(BOOL)isReady
                                   isReload:(BOOL)isReload
                               loadAdAction:(nullable dispatch_block_t)loadAdAction
                              reloadHandler:(nullable void (^)(dispatch_block_t block, NSTimeInterval delay))reloadHandler
                           cancelReloadBlock:(nullable dispatch_block_t)cancelReloadBlock;

+ (NSTimeInterval)calculateRetryDelayWithRetryAttempt:(NSInteger)retryAttempt reloadSquare:(NSInteger)reloadSquare;

+ (nullable NSString *)appendLimitation:(OxPlacementParams *)placementParams limitation:(nullable NSString *)limitation;

+ (nullable OxAd *)createOxAdByReflectionWithAdFormat:(NSString *)adFormat
                                             idConfig:(IdConfig *)idConfig
                                      placementParams:(OxPlacementParams *)placementParams
                                       viewController:(UIViewController *)viewController
                                             listener:(id<AdInternalListener>)listener;

@end

NS_ASSUME_NONNULL_END
