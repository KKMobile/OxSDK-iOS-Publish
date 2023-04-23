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

@interface BaseInterstitialAdHelper : OxAdHelper <IFullScreenAd>

@property (nonatomic, weak) id<InterstitialAdDelegate> mAddelegate;
@property (nonatomic, weak) id<InterstitialInternalAdDelegate> mInternalAddelegate;
@property (nonatomic, assign) NSInteger retryAttempt;
@property (nonatomic, assign) BOOL mReload;
@property (nonatomic, assign) BOOL mIsReloadingInLoadFailed;
@property (nonatomic, assign) BOOL mIsReloadingInDisplayFailed;
@property (nonatomic, assign) BOOL mDisplayCalled;
- (void)createAd:(Platform)platform;
- (void)resetLoadStatus:(NSString *)placement;
- (void)resetLoadStatus:(NSString *)placement requestSource:(nullable NSString *)requestSource;

@end

NS_ASSUME_NONNULL_END
