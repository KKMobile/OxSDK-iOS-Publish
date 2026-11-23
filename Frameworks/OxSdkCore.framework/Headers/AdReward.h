//
//  AdReward.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** 激励结果。只在 onUserRewarded 中按 label/amount 发放奖励，展示、点击或关闭均不能替代奖励回调。 */
@interface AdReward : NSObject

@property (nonatomic, strong) NSString  *label;

@property (nonatomic, assign) NSInteger  amount;

@end

NS_ASSUME_NONNULL_END
