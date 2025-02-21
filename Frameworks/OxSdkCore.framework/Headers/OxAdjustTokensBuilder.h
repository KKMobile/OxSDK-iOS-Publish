//
//  OxAdjustTokensBuilder.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/7/11.
//

#import <Foundation/Foundation.h>
#import "OxAdjustTokens.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdjustTokensBuilder : NSObject

@property(nonatomic, strong) NSString *  top10Token;
@property(nonatomic, strong) NSString *  top20Token;
@property(nonatomic, strong) NSString *  top30Token;
@property(nonatomic, strong) NSString *  top40Token;
@property(nonatomic, strong) NSString *  top50Token;
@property(nonatomic, strong) NSString *  top60Token;
@property(nonatomic, strong) NSString *  adImpressionRevenueToken;
@property(nonatomic, strong) NSString *  totalAdsRevenue001Token;

- (OxAdjustTokens *)build;

@end

NS_ASSUME_NONNULL_END
