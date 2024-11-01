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
@property (nonatomic, weak) id<BannerInternalAdDelegate>  mInternalAddelegate;
@property (nonatomic, weak) id<BannerAdDelegate> mAdDelegate;
@property (nonatomic, assign) bool  mIsReady;
@property (nonatomic, assign) bool  mAutoRefresh;
@property (nonatomic, strong) NSString *loadPlacement;
@property (nonatomic, assign) bool mAdaptive;

- (void)createAd;


@end

NS_ASSUME_NONNULL_END
