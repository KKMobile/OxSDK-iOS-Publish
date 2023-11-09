//
//  ApsRewardedAdManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/8/16.
//

#import <Foundation/Foundation.h>
#import <DTBiOSSDK/DTBiOSSDK.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^OnApsSuccessBlock)(DTBAdResponse *response);

typedef void (^OnApsFailedBlock)(DTBAdErrorInfo* errorInfo);

@interface ApsRewardedAdManager : NSObject<DTBAdCallback>

@property (nonatomic, copy) OnApsSuccessBlock apsSuccessBlock;
@property (nonatomic, copy) OnApsFailedBlock  apsFailedBlock;

- (void)loadApsRewardedAd;

- (bool)shouldLoadApsRewarded;

@end

NS_ASSUME_NONNULL_END
