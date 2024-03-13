//
//  OxInterstitialAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import "OxBaseAd.h"
#import "InterstitialAdDelegate.h"
#import "BaseInterstitialAdHelper.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxInterstitialAdHelper : OxBaseAd

@property (nonatomic, weak) id<InterstitialAdDelegate> mAdDelegate;
@property (nonatomic, strong) NSMutableDictionary<NSNumber *,BaseInterstitialAdHelper *> *mAdHelpersMap;

- (void)showAd:(NSString *)placement;
- (void)showAd;
- (BOOL)isReady;

- (void)setReloadAfterFailed:(BOOL)reload;


@end

NS_ASSUME_NONNULL_END
