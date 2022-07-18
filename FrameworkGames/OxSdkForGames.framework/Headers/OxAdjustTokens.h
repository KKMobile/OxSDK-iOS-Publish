//
//  OxAdjustTokens.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/7/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAdjustTokens : NSObject

@property(nonatomic, strong) NSString *  top10Token;
@property(nonatomic, strong) NSString *  top20Token;
@property(nonatomic, strong) NSString *  top30Token;
@property(nonatomic, strong) NSString *  top40Token;
@property(nonatomic, strong) NSString *  top50Token;
@property(nonatomic, strong) NSString *  top60Token;
@property(nonatomic, strong) NSString *  adImpressionRevenueToken;
@property(nonatomic, strong) NSString *  totalAdsRevenue001Token;

@property(nonatomic, strong) NSDictionary<NSString*, NSString*> *  adjustTokenDic;

- (void)build:(NSDictionary *)adjustTokenMap;

@end

NS_ASSUME_NONNULL_END
