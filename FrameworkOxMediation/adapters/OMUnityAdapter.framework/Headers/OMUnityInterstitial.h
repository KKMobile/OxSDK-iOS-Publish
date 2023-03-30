//
//  OMUnityInterstitial.h
//  OMUnityAdapter
//
//  Created by 耿志向 on 2022/11/8.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMUnityAdapter.h"
#import "OMUnityRouter.h"
#import "OMInterstitialCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMUnityInterstitial : NSObject<OMUnityAdapterDelegate,OMInterstitialCustomEvent>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, assign) BOOL isUnityAdReady;
@property (nonatomic, weak) id<interstitialCustomEventDelegate> delegate;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
