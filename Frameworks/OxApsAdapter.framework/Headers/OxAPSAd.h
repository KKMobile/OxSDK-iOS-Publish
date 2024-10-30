//
//  OxAPSAdRequest.h
//  OxApsAdapter
//
//  Created by Mavl_2023_100272 on 2024/10/25.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DTBiOSSDK/DTBiOSSDK.h>


typedef NS_ENUM(NSInteger, OxAPSAdFormat) {
    OxAPSAdFormatBanner = 0,       /* 320x50 */
    OxAPSAdFormatMREC,         /* 300x250 */
    OxAPSAdFormatLeaderBoard,  /* 728x90 */
    OxAPSAdFormatInterstitial, /* full screen */
    OxAPSAdFormatRewardedVideo, /* full screen */
    OxAPSAdFormatInterstitialVideo /* video player width and height set by publisher, default is 320x480*/
};

NS_ASSUME_NONNULL_BEGIN

@interface OxAPSAd : NSObject
+ (instancetype)sharedInstance;
+ (void)initApsSdk:(NSString *)appId testMode:(BOOL)testMode;
+ (BOOL)isReady;
- (void)loadApsAd:(NSString *)amazonAdSlotId adFormat:(OxAPSAdFormat)adFormat ompletion:(nullable void (^)(BOOL success,id info)) completion;

@end

NS_ASSUME_NONNULL_END
