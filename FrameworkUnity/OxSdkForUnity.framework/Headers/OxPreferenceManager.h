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

- (void)initialize;

- (void)setGameLevel:(int)gameLevel;

@end

NS_ASSUME_NONNULL_END
