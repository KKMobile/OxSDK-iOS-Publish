//
//  OxOpenAdHelper.h
//  OxSDK-Game
//
//  Created by ios_team on 2022/11/23.
//

#import "OxAdHelper.h"
#import "IFullScreenAd.h"
#import "OpenAdDelegate.h"
#import "OpenInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface BaseOpenAdHelper : OxAdHelper <IFullScreenAd>

@property (nonatomic, weak) id<OpenAdDelegate> mAddelegate;
@property (nonatomic, weak) id<OpenInternalAdDelegate> mInternalAddelegate;
@property (nonatomic, assign) NSInteger retryAttempt;
@property (nonatomic, assign) BOOL mReload;
@property (nonatomic, assign) BOOL mIsReloadingInLoadFailed;
@property (nonatomic, assign) BOOL mIsReloadingInDisplayFailed;
- (void)createAd:(Platform)platform;

@end

NS_ASSUME_NONNULL_END
