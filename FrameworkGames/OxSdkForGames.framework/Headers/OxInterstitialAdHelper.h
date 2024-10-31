//
//  OxInterstitialAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <OxSdkForGames/OxAdHelper.h>
#import <OxSdkForGames/IFullScreenAd.h>
#import <OxSdkForGames/InterstitialAdDelegate.h>
#import <OxSdkForGames/InterstitialInternalAdDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface OxInterstitialAdHelper : OxAdHelper <IFullScreenAd>

@property (nonatomic, weak) id<InterstitialAdDelegate> mAddelegate;
@property (nonatomic, weak) id<InterstitialInternalAdDelegate> mInternalAddelegate;
@property (nonatomic, assign) NSInteger retryAttempt;
@property (nonatomic, assign) BOOL mReload;
@property (nonatomic, assign) BOOL mIsReloadingInLoadFailed;
@property (nonatomic, assign) BOOL mIsReloadingInDisplayFailed;
- (void)createAd;

@end

NS_ASSUME_NONNULL_END
