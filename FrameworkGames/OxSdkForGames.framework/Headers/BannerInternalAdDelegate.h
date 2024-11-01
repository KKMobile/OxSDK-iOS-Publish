//
//  BannerInternalAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>
#import "AdInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@protocol BannerInternalAdDelegate <NSObject, AdInternalAdDelegate>

- (void)onAdExpanded;

- (void)onAdCollapsed;

@end

NS_ASSUME_NONNULL_END
