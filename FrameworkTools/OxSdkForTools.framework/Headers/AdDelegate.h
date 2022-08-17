//
//  AdLoaderDelegate.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdDelegate <NSObject>


- (void)onAdLoaded:(NSString*)adUnitId;

- (void)onAdLoadFailed:(NSString*)adunitId errorInfo:(NSString *)error;

- (void)onAdDisplayed:(NSString*)adUnitId;

- (void)onAdDisplayFailed:(NSString*)adunitId errorInfo:(NSString *)error;

- (void)onAdClicked:(NSString*)adUnitId;

- (void)onAdOpened:(NSString*)adUnitId;

- (void)onAdClosed:(NSString*)adUnitId;
@end

NS_ASSUME_NONNULL_END
