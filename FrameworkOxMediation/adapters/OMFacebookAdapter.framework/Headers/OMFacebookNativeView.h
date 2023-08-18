// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <UIKit/UIKit.h>
#import <FBAudienceNetwork/FBAudienceNetwork.h>
#import "OMFacebookNativeAd.h"
#import "OMNativeViewCustomEvent.h"
NS_ASSUME_NONNULL_BEGIN

@interface OMFacebookNativeView : UIView<FBMediaViewDelegate,OMNativeViewCustomEvent>

@property (nonatomic, weak) OMFacebookNativeAd *nativeAd;
@property (nonatomic, strong) FBAdChoicesView *adChoicesView;
@property (nonatomic, strong) FBMediaView *mediaView;

- (instancetype)initWithFrame:(CGRect)frame;
- (void)setClickableViews:(NSArray<UIView *> *)clickableViews;


@end

NS_ASSUME_NONNULL_END
