//
//  AdInternalAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class OxAdParams;

@protocol AdInternalAdDelegate <NSObject>

- (void)oxAdLoaded:(OxAdParams *)adParams;

- (void)oxAdLoadFailed:(OxAdParams *)adParams errorCode:(NSInteger)errorCode error:(NSString *)error;

- (void)oxAdDisplayed:(OxAdParams *)adParams;

- (void)oxAdDisplayFailed:(OxAdParams *)adParams errorInfo:(nonnull NSString *)error;

- (void)oxAdClicked:(OxAdParams *)adParams;

- (void)oxAdClosed:(OxAdParams *)adParams;

@end

NS_ASSUME_NONNULL_END
