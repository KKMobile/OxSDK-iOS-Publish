//
//  OxAdjustTokens.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/7/11.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAdjustTokens : NSObject

@property(nonatomic, strong) NSDictionary<NSString*, NSString*> *  adjustTokenDic;

- (void)build:(NSDictionary *)adjustTokenMap;

@end

NS_ASSUME_NONNULL_END
