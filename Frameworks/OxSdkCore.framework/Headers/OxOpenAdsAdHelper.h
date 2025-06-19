//
//  OxOpenAdsAdHelper.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/5/22.
//

#import "OxAdHelper.h"
#import "IFullScreenAd.h"
#import "OpenAdsAdDelegate.h"
#import "OpenAdsInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxOpenAdsAdHelper : OxAdHelper <IFullScreenAd>

@property (nonatomic, weak) id<OpenAdsAdDelegate> mAddelegate;

+ (OxOpenAdsAdHelper *)createAdWithCurrentVC:(UIViewController *)currentVC adUnitID:(NSString *)adUnitID;

@end

NS_ASSUME_NONNULL_END
