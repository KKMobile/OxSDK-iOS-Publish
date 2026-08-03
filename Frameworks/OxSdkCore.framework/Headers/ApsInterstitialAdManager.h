//
//  ApsInterstitialAdManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/16.
//

#import "ApsBaseAdManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface ApsInterstitialAdManager : ApsBaseAdManager

- (void)loadApsAdWithSlotId:(NSString *)slotId apsType:(NSInteger)apsType;

@end

NS_ASSUME_NONNULL_END
