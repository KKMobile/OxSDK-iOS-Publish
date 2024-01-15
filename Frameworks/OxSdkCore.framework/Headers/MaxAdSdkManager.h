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

@property (nonatomic, strong) ALSdk *alSdk;


@end

NS_ASSUME_NONNULL_END