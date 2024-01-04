//
//  ApsBaseAdManager.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/5.
//

#import <Foundation/Foundation.h>
#import <DTBiOSSDK/DTBiOSSDK.h>
#import "OxAdSdkManager.h"
#import "AdEvents.h"

@import IronSource;

NS_ASSUME_NONNULL_BEGIN


typedef void (^OnApsSuccessBlock)(DTBAdResponse  * _Nullable response);

typedef void (^OnApsFailedBlock)(DTBAdErrorInfo  * _Nullable errorInfo);

@interface ApsBaseAdManager : NSObject<DTBAdCallback>

@property (nonatomic, copy) OnApsSuccessBlock apsSuccessBlock;
@property (nonatomic, copy) OnApsFailedBlock  apsFailedBlock;
@property (nonatomic, copy) NSString * slotId;

- (BOOL)shouldLoadAps;
- (void)loadApsAd;
- (void)checkApsInit:(void (^)(BOOL isInitialized))callback;


@end

NS_ASSUME_NONNULL_END