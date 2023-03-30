//
//  OMFyberInterstitial.h
//  OMFyberAdapter
//
//  Created by 耿志向 on 2022/11/9.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OMFyberBannerClass.h"
#import "OMInterstitialCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMFyberInterstitial : NSObject<OMInterstitialCustomEvent>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, weak) id<interstitialCustomEventDelegate> delegate;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
