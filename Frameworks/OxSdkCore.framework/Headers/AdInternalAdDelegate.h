//
//  AdInternalAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdInternalAdDelegate <NSObject>

- (void)oxAdLoaded:(nullable id)ad;

- (void)oxAdLoadFailed:(NSString *)error;

- (void)oxAdDisplayed:(nullable id)ad;

- (void)oxAdDisplayFailed:(nullable id)ad errorInfo:(nonnull NSString *)error;

- (void)oxAdClicked:(nullable id)ad;

- (void)oxAdOpened;

- (void)oxAdClosed:(nullable id)ad;

@end

NS_ASSUME_NONNULL_END
