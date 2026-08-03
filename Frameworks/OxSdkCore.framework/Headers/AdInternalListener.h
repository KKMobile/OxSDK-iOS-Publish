//
//  AdInternalListener.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class OxAdParams, AdReward;

NS_ASSUME_NONNULL_BEGIN

@protocol AdInternalListener <NSObject>

@optional
- (void)onAdLoaded:(OxAdParams *)adParams;
- (void)onAdLoadFailed:(nullable OxAdParams *)adParams errorCode:(NSInteger)errorCode error:(nullable NSString *)error;
- (void)onAdDisplayed:(nullable OxAdParams *)adParams;
- (void)onAdDisplayFailed:(nullable OxAdParams *)adParams errorCode:(NSInteger)errorCode error:(nullable NSString *)error;
- (void)onAdClicked:(OxAdParams *)adParams;
- (void)onAdOpened;
- (void)onAdClosed:(OxAdParams *)adParams;
- (void)onUserRewarded:(AdReward *)reward adParams:(OxAdParams *)adParams;

@end

NS_ASSUME_NONNULL_END
