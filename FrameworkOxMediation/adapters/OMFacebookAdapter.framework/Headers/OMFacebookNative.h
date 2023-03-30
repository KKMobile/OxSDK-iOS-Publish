// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <FBAudienceNetwork/FBAudienceNetwork.h>
#import "OMNativeCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMFacebookNative : NSObject<OMNativeCustomEvent,FBNativeAdDelegate,FBNativeBannerAdDelegate>

@property (nonatomic, weak) UIViewController *rootVC;
@property (nonatomic, weak) id<nativeCustomEventDelegate> delegate;

- (instancetype)initWithParameter:(NSDictionary*)adParameter rootVC:(UIViewController*)rootViewController;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (void)loadAdWithBidPayload:(NSString *)bidPayload localExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;

@end

NS_ASSUME_NONNULL_END
