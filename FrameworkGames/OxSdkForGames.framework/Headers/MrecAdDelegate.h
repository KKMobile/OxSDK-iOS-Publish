//
//  MrecAdDelegate.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import <Foundation/Foundation.h>
#import "AdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@protocol MrecAdDelegate <NSObject, AdDelegate>

- (void)onAdExpanded;

- (void)onAdCollapsed;

@end

NS_ASSUME_NONNULL_END
