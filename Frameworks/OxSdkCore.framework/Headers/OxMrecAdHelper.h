//
//  OxMrecAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import "OxAdHelper.h"
#import "IBannerAd.h"
#import "MrecAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxMrecAdHelper : OxAdHelper<IBannerAd>

@property (nonatomic, weak)id<MrecAdDelegate> mAddelegate;

+ (OxMrecAdHelper *)createAdWithCurrentVC:(UIViewController *)currentVC adUnitID:(NSString *)adUnitID;

@end

NS_ASSUME_NONNULL_END
