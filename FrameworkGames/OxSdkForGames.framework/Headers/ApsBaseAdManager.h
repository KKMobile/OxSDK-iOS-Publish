//
//  ApsBaseAdManager.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/5.
//

#import <Foundation/Foundation.h>
#import <OxSdkForGames/OXLogMoudle.h>

#if __has_include(<OxApsAdapter/OxAPSAd.h>)
    #import <OxApsAdapter/OxAPSAd.h>
#endif

NS_ASSUME_NONNULL_BEGIN


typedef void (^OnApsSuccessBlock)(id response);

typedef void (^OnApsFailedBlock)(__nullable id errorInfo);

@interface ApsBaseAdManager : NSObject

@property (nonatomic, copy) OnApsSuccessBlock apsSuccessBlock;
@property (nonatomic, copy) OnApsFailedBlock  apsFailedBlock;

- (BOOL)shouldLoadAps;
- (void)loadApsAd;
- (void)loadApsAd:(NSString *)amazonAdSlotId adFormat:(NSInteger)adFormat;
- (void)checkApsInit:(void (^)(BOOL isInitialized))callback;


@end

NS_ASSUME_NONNULL_END
