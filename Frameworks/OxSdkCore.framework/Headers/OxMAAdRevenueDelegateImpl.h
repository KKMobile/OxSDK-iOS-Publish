//
//  OxMAAdRevenueDelegateImpl.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/8/31.
//

#import <Foundation/Foundation.h>
#import <AppLovinSDK/AppLovinSDK.h>
NS_ASSUME_NONNULL_BEGIN

@class OxAdParams;

@interface OxMAAdRevenueDelegateImpl : NSObject<MAAdRevenueDelegate>

@property(nonatomic, strong) OxAdParams *mAdEventParams;

@end

NS_ASSUME_NONNULL_END
