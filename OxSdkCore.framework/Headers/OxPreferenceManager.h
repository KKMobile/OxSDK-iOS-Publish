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

- (void)initialize;

- (void)setGameLevel:(int)gameLevel;
- (void)setGamePlayMinutes:(int)minutes;
- (void)setGamePayCounts:(int)count;

@end

NS_ASSUME_NONNULL_END
