//
//  OMVerveNativeView.h
//  OMVerveAdapter
//
//  Created by Mavl_2023_100272 on 2023/7/3.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OMNativeViewCustomEvent.h"
#import "OMVerveNativeAd.h"

@import HyBid;

NS_ASSUME_NONNULL_BEGIN

@interface OMVerveNativeView : UIView <OMNativeViewCustomEvent>

@property (nonatomic, weak) OMVerveNativeAd *nativeAd;
@property (nonatomic, readonly) UIImageView *mediaView;
@property(nonatomic, strong) NSLayoutConstraint *heightConstraint;
- (instancetype)initWithFrame:(CGRect)frame;


@end

NS_ASSUME_NONNULL_END
