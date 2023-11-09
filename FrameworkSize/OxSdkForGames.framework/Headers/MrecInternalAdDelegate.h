//
//  MrecInternalAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>
#import "AdInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@protocol MrecInternalAdDelegate <NSObject, AdInternalAdDelegate>

- (void)onAdExpanded;

- (void)onAdCollapsed;

@end

NS_ASSUME_NONNULL_END
