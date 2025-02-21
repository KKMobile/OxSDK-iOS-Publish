//
//  IBannerAd.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import <Foundation/Foundation.h>
#import "IViewAd.h"
NS_ASSUME_NONNULL_BEGIN

@protocol IBannerAd <NSObject, IViewAd>

- (void)stopAutoRefresh;

- (void)startAutoRefresh;

@end

NS_ASSUME_NONNULL_END
