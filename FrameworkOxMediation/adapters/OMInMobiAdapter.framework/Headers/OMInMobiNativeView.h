//
//  OMInMobiNativeView.h
//  OMInMobiAdapter
//
//  Created by 耿志向 on 2022/11/15.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OMNativeViewCustomEvent.h"
#import "OMInMobiNativeClass.h"
#import "OMInMobiNativeAd.h"
NS_ASSUME_NONNULL_BEGIN

@interface OMInMobiNativeView : UIView <OMNativeViewCustomEvent>
@property (nonatomic, strong) OMInMobiNativeAd *nativeAd;
@property (nonatomic, strong) UIView *mediaView;
- (instancetype)initWithFrame:(CGRect)frame;

@end

NS_ASSUME_NONNULL_END