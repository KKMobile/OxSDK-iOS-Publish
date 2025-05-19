//
//  OxInterstitialAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import "OxAdHelper.h"
#import "IFullScreenAd.h"
#import "InterstitialAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@class OxInterstitialAd;

@interface OxInterstitialAdHelper : OxAdHelper <IFullScreenAd>

@property (nonatomic, weak) id<InterstitialAdDelegate> mAddelegate;

+ (OxInterstitialAdHelper *)createAdWithCurrentVC:(UIViewController *)currentVC adUnitID:(NSString *)adUnitID;

@end

NS_ASSUME_NONNULL_END
