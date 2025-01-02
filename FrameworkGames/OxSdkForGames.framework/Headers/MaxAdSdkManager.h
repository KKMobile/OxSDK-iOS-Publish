//
//  MaxAdSdkManager.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/21.
//

#import "BaseAdManager.h"
NS_ASSUME_NONNULL_BEGIN

@interface MaxAdSdkManager : BaseAdManager

+ (nonnull instancetype)sharedInstance;

// 当前广告ID 是否开启 APS
- (BOOL)enabledAmazonAdUnitIdentifier:(NSString *)adUnitID;

@end

NS_ASSUME_NONNULL_END
