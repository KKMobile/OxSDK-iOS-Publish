//
//  BaseOpenAdsAdHelper.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/8/21.
//

#import "BaseFullscreenAdHelper.h"
#import "OpenAdsAdDelegate.h"
#import "OpenAdsInternalAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface BaseOpenAdsAdHelper : BaseFullscreenAdHelper <IFullScreenAd,OpenAdsInternalAdDelegate>


@property (nonatomic, weak) id<OpenAdsAdDelegate> mAdDelegate;

+ (BaseOpenAdsAdHelper *)createAdHelpeWithAdUnitId:(NSString *)adUnitId mediation:(Platform)mediation;

@end

NS_ASSUME_NONNULL_END
