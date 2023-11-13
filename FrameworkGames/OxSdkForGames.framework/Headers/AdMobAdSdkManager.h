//
//  AdMobAdSdkManager.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/21.
//

#import "BaseAdManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdMobAdSdkManager : BaseAdManager

+ (nonnull instancetype)sharedInstance;
- (void)initialize:(OnSdkInitComplete)successBlock;

@end

NS_ASSUME_NONNULL_END
