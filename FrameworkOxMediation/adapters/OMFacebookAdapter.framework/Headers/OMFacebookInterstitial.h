#import <Foundation/Foundation.h>
#import <FBAudienceNetwork/FBAudienceNetwork.h>
#import "OMInterstitialCustomEvent.h"


NS_ASSUME_NONNULL_BEGIN

@interface OMFacebookInterstitial : NSObject <OMInterstitialCustomEvent,FBInterstitialAdDelegate>
@property (nonatomic, strong) FBInterstitialAd *facebookInterstitial;
@property (nonatomic, copy) NSString *pid;
@property (nonatomic, weak) id<interstitialCustomEventDelegate> delegate;
@property (nonatomic, assign) BOOL ready;
@property (nonatomic, getter=isAdValid, readonly) BOOL adValid;

- (instancetype)initWithParameter:(NSDictionary*)adParameter;
- (void)loadAdWithBidPayload:(NSString *)bidPayload localExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (BOOL)isReady;
- (void)show:(UIViewController*)vc;

@end

NS_ASSUME_NONNULL_END
