//
//  OxMAAdRevenueDelegateImpl.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/8/31.
//

#import <Foundation/Foundation.h>
#import <AppLovinSDK/AppLovinSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface OxMAAdRevenueDelegateImpl : NSObject<MAAdRevenueDelegate>

@property (nonatomic, assign) long long mTag;
@property (nonatomic, assign) long long mRequestTag;
@property (nonatomic, copy) NSString *showPlacement;
@property (nonatomic, copy) NSString *mFloorPrice;
@property (nonatomic, assign) float mJumpHeightPer;

@end

NS_ASSUME_NONNULL_END
