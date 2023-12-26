//
//  OxOpenAdHelper.h
//  OxSDK-Game
//
//  Created by BJMM100001 on 2022/11/25.
//

#import "OxBaseAd.h"
#import "OpenAdsDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxOpenAds : OxBaseAd

@property (nonatomic, weak) id<OpenAdsDelegate> mAdDelegate;

- (void)showAd:(NSString *)placement;
- (void)showAd;
- (void)destoryAd;
- (BOOL)isReady;

@end

NS_ASSUME_NONNULL_END
