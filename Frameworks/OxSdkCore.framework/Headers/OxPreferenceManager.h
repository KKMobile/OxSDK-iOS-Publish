//
//  OxPreferenceManager.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/9/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxPreferenceManager : NSObject

+ (nonnull instancetype)shared;

@property (nonatomic) int gameLevel;
@property (nonatomic) int gamePlayMinutes;
@property (nonatomic) int gamePayCounts;
@property (nonatomic, copy, nullable) NSString *adRestrictConfig;
@property (nonatomic, readonly) int sessionCount;

- (void)initialize;

- (void)setGameLevel:(int)gameLevel;
- (void)setGamePlayMinutes:(int)minutes;
- (void)setGamePayCounts:(int)count;

/// 自然天内累计通过的关卡数（基于 setGameLevel 基线差）
- (int)getDailyPassedLevelCount;

/// 冷启动累计 session；同一进程应只在首次初始化调用一次
- (int)increaseSessionCount;
- (int)getSessionCount;

@end

NS_ASSUME_NONNULL_END
