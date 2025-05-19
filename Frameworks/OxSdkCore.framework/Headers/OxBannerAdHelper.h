//
//  OxBannerAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import "OxAdHelper.h"
#import "IBannerAd.h"
#import "BannerAdDelegate.h"
#import "BannerInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxBannerAdHelper : OxAdHelper<IBannerAd>

@property (nonatomic, weak) id<BannerAdDelegate> mAdDelegate;

+ (OxBannerAdHelper *)createAdWithCurrentVC:(UIViewController *)currentVC adUnitID:(NSString *)adUnitID;


@end

NS_ASSUME_NONNULL_END
