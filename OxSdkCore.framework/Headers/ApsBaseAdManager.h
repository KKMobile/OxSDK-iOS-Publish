//
//  ApsBaseAdManager.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/5.
//

#import <Foundation/Foundation.h>
#import "OXLogMoudle.h"

typedef NS_ENUM(NSInteger, OxAPSAdFormat) {
    OxAPSAdFormatBanner = 0,       /* 320x50 */
    OxAPSAdFormatMREC,         /* 300x250 */
    OxAPSAdFormatLeaderBoard,  /* 728x90 */
    OxAPSAdFormatInterstitial, /* full screen */
    OxAPSAdFormatRewardedVideo, /* full screen */
    OxAPSAdFormatInterstitialVideo /* video player width and height set by publisher, default is 320x480*/
};

NS_ASSUME_NONNULL_BEGIN


typedef void (^OnApsSuccessBlock)(id response);

typedef void (^OnApsFailedBlock)(__nullable id errorInfo);

@interface ApsBaseAdManager : NSObject

@property (nonatomic, copy) OnApsSuccessBlock apsSuccessBlock;
@property (nonatomic, copy) OnApsFailedBlock  apsFailedBlock;

- (BOOL)shouldLoadAps;
- (BOOL)shouldLoadApsWithSlotId:(NSString *)slotId;
- (void)loadApsAd;
- (void)loadApsAdWithSlotId:(NSString *)slotId;
- (void)loadApsAd:(NSString *)amazonAdSlotId adFormat:(OxAPSAdFormat)adFormat;
- (void)checkApsInit:(void (^)(BOOL isInitialized))callback;


@end

NS_ASSUME_NONNULL_END
