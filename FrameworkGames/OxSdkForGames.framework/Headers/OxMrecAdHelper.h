//
//  OxMrecAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import "OxAdHelper.h"
#import "IBannerAd.h"
#import "MrecAdDelegate.h"
#import "MrecInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxMrecAdHelper : OxAdHelper<IBannerAd>

@property (nonatomic, weak) id<MrecInternalAdDelegate>  mInternalAddelegate;
@property (nonatomic, weak)id<MrecAdDelegate> mAddelegate;
@property (nonatomic, assign) bool  mIsReady;
@property (nonatomic, assign) bool  mAutoRefresh;
@property (nonatomic, strong) NSString *loadPlacement;
- (void)createAd;

@end

NS_ASSUME_NONNULL_END
