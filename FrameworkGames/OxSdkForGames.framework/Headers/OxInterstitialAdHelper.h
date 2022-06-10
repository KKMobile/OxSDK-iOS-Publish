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

@interface OxInterstitialAdHelper : OxAdHelper <IFullScreenAd>

@property (nonatomic, weak) id<InterstitialAdDelegate> mAddelegate;
@property (nonatomic, weak) id<InterstitialInternalAdDelegate> mInternalAddelegate;
@property (nonatomic, assign) NSInteger retryAttempt;
@property (nonatomic, assign) BOOL mReload;
- (void)createAd;

@end

NS_ASSUME_NONNULL_END
