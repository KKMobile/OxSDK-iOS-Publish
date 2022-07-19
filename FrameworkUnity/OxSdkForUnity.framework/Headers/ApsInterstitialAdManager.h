//
//  ApsInterstitialAdManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/16.
//

#import <Foundation/Foundation.h>
#import <DTBiOSSDK/DTBiOSSDK.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^OnApsSuccessBlock)(DTBAdResponse *response);

typedef void (^OnApsFailedBlock)(DTBAdErrorInfo* errorInfo);

@interface ApsInterstitialAdManager : NSObject<DTBAdCallback>

@property (nonatomic, copy) OnApsSuccessBlock apsSuccessBlock;
@property (nonatomic, copy) OnApsFailedBlock  apsFailedBlock;

+ (nonnull instancetype)sharedInstance;

- (void)loadApsInterstitialAd;

- (bool)shouldLoadApsInterstitial;

@end

NS_ASSUME_NONNULL_END
