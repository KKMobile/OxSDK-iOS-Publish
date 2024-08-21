//
//  OxOpenAdsAdHelper.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/5/22.
//

#import "OxBaseAd.h"
#import "OpenAdsAdDelegate.h"
#import "BaseOpenAdsAdHelper.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxOpenAdsAdHelper : OxBaseAd

@property (nonatomic, weak) id<OpenAdsAdDelegate> mAdDelegate;
@property (nonatomic, strong) NSMutableDictionary<NSNumber *,BaseOpenAdsAdHelper *> *mAdHelpersMap;

- (void)showAd:(NSString *)placement;
- (void)showAd;
- (BOOL)isReady;


@end

NS_ASSUME_NONNULL_END
