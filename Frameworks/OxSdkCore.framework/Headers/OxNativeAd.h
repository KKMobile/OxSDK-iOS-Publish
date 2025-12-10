//
//  OxNativeAd.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/11/3.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OxAd.h"

NS_ASSUME_NONNULL_BEGIN

@class OxNativeViewBinder;

@interface OxNativeAd : OxAd

@property(nonatomic, assign) BOOL mIsReady;
@property (nonatomic, strong, readonly) OxNativeViewBinder *mViewBinder;

- (void)showAd:(UIView *)adContainerV placement:(NSString *)placement;
- (void)hideAd;

- (void)setViewBinder:(OxNativeViewBinder *)binder;


@end

NS_ASSUME_NONNULL_END
