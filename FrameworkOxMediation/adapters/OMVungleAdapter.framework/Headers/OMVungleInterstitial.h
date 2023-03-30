//
//  OMVungleInterstitial.h
//  OMVungleAdapter
//
//  Created by 耿志向 on 2022/11/8.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMVungleRouter.h"
#import "OMInterstitialCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMVungleInterstitial : NSObject <OMInterstitialCustomEvent,OMVungleAdapterDelegate>

@property (nonatomic, weak) id<interstitialCustomEventDelegate>delegate;
@property (nonatomic, copy) NSString *pid;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
