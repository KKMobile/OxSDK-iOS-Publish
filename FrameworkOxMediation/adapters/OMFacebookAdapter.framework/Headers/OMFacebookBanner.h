#import <UIKit/UIKit.h>
#import "OMBannerCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMFacebookBanner : UIView <OMBannerCustomEvent>

@property(nonatomic, weak, nullable) id<bannerCustomEventDelegate> delegate;
- (instancetype)initWithFrame:(CGRect)frame adParameter:(NSDictionary *)adParameter rootViewController:(UIViewController *)rootViewController;
- (void)loadAdWithBidPayload:(NSString *)bidPayload localExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
@end

NS_ASSUME_NONNULL_END
