//
//  AdLoaderDelegate.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdDelegate <NSObject>


- (void)onAdLoaded;

- (void)onAdLoadFailed:(NSString*)adunitId errorInfo:(NSString *)error;

- (void)onAdDisplayed;

- (void)onAdDisplayFailed:(NSString*)adunitId errorInfo:(NSString *)error;

- (void)onAdClicked;

- (void)onAdOpened;

- (void)onAdClosed;
@end

NS_ASSUME_NONNULL_END
