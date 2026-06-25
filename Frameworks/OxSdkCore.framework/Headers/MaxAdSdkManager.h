//
//  MaxAdSdkManager.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/21.
//

#import "BaseAdManager.h"
NS_ASSUME_NONNULL_BEGIN

@class ALSdkConfiguration;

@interface MaxAdSdkManager : BaseAdManager

+ (nonnull instancetype)sharedInstance;

- (void)addDisableCache:(NSString *)adUnitId;

- (void)updateSegment;

- (ALSdkConfiguration *)getSdkConfiguration;
- (ALConsentFlowUserGeography)getConsentState;


@end

NS_ASSUME_NONNULL_END
