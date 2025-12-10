//
//  OxMrecAd.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/11/3.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OxAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxMrecAd : OxAd

@property(nonatomic, assign, readonly) BOOL mAutoRefresh;
@property(nonatomic, assign) BOOL mIsReady;

- (void)showAd:(UIView *)adContainerV placement:(NSString *)placement;
- (void)hideAd;

- (void)startAutoRefresh;
- (void)stopAutoRefresh;

#pragma mark - 子类实现
- (void)activateAutoRefresh;
- (void)internalStopAutoRefresh;

@end

NS_ASSUME_NONNULL_END
