//
//  ApsBannerAdManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/16.
//

#import <Foundation/Foundation.h>
#import <DTBiOSSDK/DTBiOSSDK.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^OnApsSuccessBlock)(DTBAdResponse *response);

typedef void (^OnApsFailedBlock)(DTBAdErrorInfo* errorInfo);

@interface ApsBannerAdManager : NSObject<DTBAdCallback>

@property (nonatomic, copy) OnApsSuccessBlock apsSuccessBlock;
@property (nonatomic, copy) OnApsFailedBlock  apsFailedBlock;

+ (nonnull instancetype)sharedInstance;

- (void)loadApsBannerAd;

- (bool)shouldLoadApsBanner;

@end

NS_ASSUME_NONNULL_END
