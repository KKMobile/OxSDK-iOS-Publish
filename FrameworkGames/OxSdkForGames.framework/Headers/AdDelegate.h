//
//  AdLoaderDelegate.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdDelegate <NSObject>

- (void)onAdLoadedWithAdUnitName:(NSString *)adUnitName;

- (void)onAdLoadFailedWithAdUnitName:(NSString *)adUnitName errorInfo:(NSString *)error;

- (void)onAdDisplayedWithAdUnitName:(NSString *)adUnitName;

- (void)onAdDisplayFailedWithAdUnitName:(NSString *)adUnitName errorInfo:(NSString *)error;

- (void)onAdClickedWithAdUnitName:(NSString *)adUnitName;

- (void)onAdOpenedWithAdUnitName:(NSString *)adUnitName;

- (void)onAdClosedWithAdUnitName:(NSString *)adUnitName;

@end

NS_ASSUME_NONNULL_END
