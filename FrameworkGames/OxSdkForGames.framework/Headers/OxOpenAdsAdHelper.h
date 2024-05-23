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
@property (nonatomic, weak) id<OpenAdsInternalAdDelegate> mInternalAddelegate;
- (void)createAd;

@end

NS_ASSUME_NONNULL_END
