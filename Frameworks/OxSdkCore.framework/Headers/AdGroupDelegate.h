//
//  AdGroupDelegate.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2023/7/7.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdGroupDelegate <NSObject>

- (void)onAdGroupLoaded:(NSString *)adUnitId;

- (void)onAdGroupLoadFailed:(NSString *)adUnitId errorInfo:(NSString *)error;

- (void)onAdGroupDisplayed:(NSString *)adUnitId;

- (void)onAdGroupDisplayFailed:(NSString *)adUnitId errorInfo:(NSString *)error;

- (void)onAdGroupClicked:(NSString *)adUnitId;

- (void)onAdGroupOpened:(NSString *)adUnitId;

- (void)onAdGroupClosed:(NSString *)adUnitId;

@end

NS_ASSUME_NONNULL_END
