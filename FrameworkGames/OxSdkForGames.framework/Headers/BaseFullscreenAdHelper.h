//
//  BaseFullscreenAdHelper.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/5/31.
//

#import "OxAdHelper.h"
#import "IFullScreenAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface BaseFullscreenAdHelper : OxAdHelper <IFullScreenAd>

@property (nonatomic, assign) NSInteger retryCount;
@property (nonatomic, assign) BOOL isReloadAfterFailed;
@property (nonatomic, assign) BOOL mIsReloadingInLoadFailed;
@property (nonatomic, assign) BOOL mIsReloadingInDisplayFailed;
@property (nonatomic, assign) BOOL mDisplayCalled;


- (void)resetLoadStatus:(NSString *)placement;

- (void)reloadOnLoadFailed:(NSString *)placement;

- (void)reloadOnDisplayFailed:(NSString *)placement;


@end

NS_ASSUME_NONNULL_END
