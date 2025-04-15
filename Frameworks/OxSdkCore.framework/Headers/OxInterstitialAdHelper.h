//
//  OxInterstitialAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import "OxAdHelper.h"
#import "IFullScreenAd.h"
#import "InterstitialAdDelegate.h"
#import "InterstitialInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@class OxInterstitialAd;

@interface OxInterstitialAdHelper : OxAdHelper <IFullScreenAd>

// 缓存
@property (nonatomic, strong) NSMutableArray<OxInterstitialAd *> *cacheAds;
// 判断是否请求中又来请求
@property (nonatomic, assign) BOOL isLoading;
@property(nonatomic, assign) LoadStatus loadStatus;

@property (nonatomic, weak) id<InterstitialAdDelegate> mAddelegate;
@property (nonatomic, weak) id<InterstitialInternalAdDelegate> mInternalAddelegate;
@property (nonatomic, assign) NSInteger retryAttempt;
@property (nonatomic, assign) BOOL mReload;
@property (nonatomic, assign) BOOL mIsReloadingInLoadFailed;
@property (nonatomic, assign) BOOL mIsReloadingInDisplayFailed;
- (void)createAd;

@end

NS_ASSUME_NONNULL_END
