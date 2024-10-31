//
//  ApsBaseAdManager.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/5.
//

#import <Foundation/Foundation.h>
#import <OxSdkForGames/OXLogMoudle.h>
#import <OxSdkForGames/OxAPSHelper.h>

NS_ASSUME_NONNULL_BEGIN


typedef void (^OnApsSuccessBlock)(id response);

typedef void (^OnApsFailedBlock)(__nullable id errorInfo);

@interface ApsBaseAdManager : NSObject

@property (nonatomic, copy) OnApsSuccessBlock apsSuccessBlock;
@property (nonatomic, copy) OnApsFailedBlock  apsFailedBlock;

- (BOOL)shouldLoadAps;
- (void)loadApsAd;
- (void)loadApsAd:(NSString *)amazonAdSlotId adFormat:(OxAPSAdFormat)adFormat;
- (void)checkApsInit:(void (^)(BOOL isInitialized))callback;


@end

NS_ASSUME_NONNULL_END
