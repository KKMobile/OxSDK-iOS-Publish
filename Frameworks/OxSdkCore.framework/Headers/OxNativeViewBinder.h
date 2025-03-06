//
//  OxNativeViewBinder.h
//  oxsdk_flutter
//
//  Created by Mavl_2023_100272 on 2025/3/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class GADMediaView,NativeAdViewBinder;

NS_ASSUME_NONNULL_BEGIN

@interface OxNativeViewBinder : NSObject


@property(nonatomic, strong) NativeAdViewBinder *viewBinder;

@end

@interface NativeAdViewBinder : NSObject

@property(nonatomic, strong) UIView *mediaView;
@property(nonatomic, strong) UIImageView *icon;
@property(nonatomic, strong) UILabel *title;
@property(nonatomic, strong) UILabel *adLabel;
@property(nonatomic, strong) UILabel *advertiser;
@property(nonatomic, strong) UILabel *body;
@property(nonatomic, strong) UIButton *callToAction;

@property(nonatomic, strong) GADMediaView *admobMediaView;

@end


NS_ASSUME_NONNULL_END
