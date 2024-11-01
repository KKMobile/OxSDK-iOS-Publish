//
//  AdInternalAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdInternalAdDelegate <NSObject>

- (void)onAdLoaded:(nonnull NSString*)adunitId placement:(nullable NSString*)placement loadedDuration:(double)loadedDuration bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName waterfallName:(nullable NSString*)waterfallName networkResponses:(NSInteger)networkResponses latencyMillis:(double)latencyMillis creativeId:(nullable NSString*)creativeId revenue:(double)revenue;

- (void)onAdLoadFailed:(nonnull NSString*)adunitId errorInfo:(NSString *)error placement:(nullable NSString*)placement failedDuration:(double)failedDuration;

- (void)onAdDisplayed:(nonnull NSString*)adunitId placement:(nullable NSString*)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName waterfallName:(nullable NSString*)waterfallName networkResponses:(NSInteger)networkResponses latencyMillis:(double)latencyMillis creativeId:(nullable NSString*)creativeId revenue:(double)revenue;

- (void)onAdDisplayFailed:(nonnull NSString*)adunitId errorInfo:(nonnull NSString *)error placement:(nullable NSString*)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName waterfallName:(nullable NSString*)waterfallName networkResponses:(NSInteger)networkResponses creativeId:(nullable NSString*)creativeId failedDuration:(double)failedDuration;

- (void)onAdClicked:(nonnull NSString*)adunitId placement:(nullable NSString*)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName waterfallName:(nullable NSString*)waterfallName networkResponses:(NSInteger)networkResponses  creativeId:(nullable NSString*)creativeId revenue:(double)revenue;

- (void)onAdOpened;

- (void)onAdClosed:(nonnull NSString*)adunitId placement:(nullable NSString*)placement bannerSize:(nullable NSString*)bannerSize networkName:(nullable NSString*)networkName waterfallName:(nullable NSString*)waterfallName networkResponses:(NSInteger)networkResponses latencyMillis:(double)latencyMillis creativeId:(nullable NSString*)creativeId revenue:(double)revenue showingDuration:(double)showingDuration;

@end

NS_ASSUME_NONNULL_END
