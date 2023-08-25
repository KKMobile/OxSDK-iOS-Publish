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
@property (nonatomic, assign) BOOL isReloadAfterFailed; // 是否重试
@property (nonatomic, assign) BOOL mIsReloadingInLoadFailed; // 判断是否处于加载失败后重试
@property (nonatomic, assign) BOOL mIsReloadingInDisplayFailed; // 判断是否处于显示失败后重试
@property (nonatomic, assign) BOOL mDisplayCalled;

- (void)reloadAd:(NSString *)requestSource;

- (void)reloadOnDisplayFailed:(NSString *)placment;
- (void)reloadOnLoadFailed:(NSString *)placment;


@end

NS_ASSUME_NONNULL_END
