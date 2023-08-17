// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMVungleRouter.h"
#import "OMBannerCustomEvent.h"


NS_ASSUME_NONNULL_BEGIN

@interface OMVungleBanner : UIView <OMBannerCustomEvent>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, strong) UIView *renderView;
@property (nonatomic, assign) BOOL adShow;
@property (nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
