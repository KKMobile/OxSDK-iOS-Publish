//
//  IViewAd.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@protocol IViewAd <NSObject>

- (void)showAd:(UIView *)adContainerV;

- (void)showAd:(UIView *)adContainerV placement:(NSString *)placement;

- (void)hideAd;

@end

NS_ASSUME_NONNULL_END
