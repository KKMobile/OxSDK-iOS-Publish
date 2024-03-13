//
//  BannerAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import <Foundation/Foundation.h>
#import "AdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@protocol BannerAdDelegate <NSObject, AdDelegate>

- (void)onAdExpandedWithAdUnitName:(NSString *)adUnitName;

- (void)onAdCollapsedWithAdUnitName:(NSString *)adUnitName;

@end

NS_ASSUME_NONNULL_END
