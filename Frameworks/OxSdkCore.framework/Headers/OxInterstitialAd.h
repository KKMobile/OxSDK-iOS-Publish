//
//  OxInterstitialAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import "OxBaseAd.h"
#import "InterstitialAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxInterstitialAd : OxBaseAd

@property (nonatomic, weak) id<InterstitialAdDelegate> mAdDelegate;

- (void)showAd:(NSString *)placement;
- (void)showAd;
- (BOOL)isReady;

- (void)setReloadAfterFailed:(BOOL)reload;

@end

NS_ASSUME_NONNULL_END
