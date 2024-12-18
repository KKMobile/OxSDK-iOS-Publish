//
//  IFullScreenAd.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IFullScreenAd <NSObject>

- (BOOL)showAd;

- (BOOL)showAd:(NSString *)placement;

- (void)setReloadAfterFailed:(BOOL)reload;

@end

NS_ASSUME_NONNULL_END
