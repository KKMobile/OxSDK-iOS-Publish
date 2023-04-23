//
//  OMInMobiNative.h
//  OMInMobiAdapter
//
//  Created by 耿志向 on 2022/11/13.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <InMobiSDK/InMobiSDK.h>
#import "OMNativeCustomEvent.h"
#import "OMBidCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMInMobiNative : NSObject <OMNativeCustomEvent,IMNativeDelegate>

@property (nonatomic, strong, nullable) IMNative *native;
@property (nonatomic, copy) NSString *pid;
@property(nonatomic, weak, nullable) id<nativeCustomEventDelegate> delegate;
@property (nonatomic, weak) id<OMBidCustomEventDelegate> bidDelegate;

- (instancetype)initWithParameter:(NSDictionary*)adParameter rootVC:(UIViewController*)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
