//
//  OxOpenAdHelper.h
//  OxSDK-Game
//
//  Created by ios_team on 2022/11/23.
//

#import "BaseFullscreenAdHelper.h"
#import "OpenAdsDelegate.h"
#import "OpenInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface BaseOpenAdsHelper : BaseFullscreenAdHelper <IFullScreenAd,OpenInternalAdDelegate>

@property (nonatomic, weak) id<OpenAdsDelegate> mAdDelegate;

+ (BaseOpenAdsHelper *)createAdHelpeWithAdUnitId:(NSString *)adUnitId mediationType:(OxSdkMediationType)mediationType;

@end

NS_ASSUME_NONNULL_END
