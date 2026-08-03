//
//  OxMAAdRevenueDelegateImpl.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/8/31.
//

#import <Foundation/Foundation.h>
#import <AppLovinSDK/AppLovinSDK.h>

@class OxAdParams;

NS_ASSUME_NONNULL_BEGIN

@interface OxMAAdRevenueDelegateImpl : NSObject<MAAdRevenueDelegate>

@property (nonatomic, weak, nullable) OxAdParams *mAdEventParams;

@end

NS_ASSUME_NONNULL_END
