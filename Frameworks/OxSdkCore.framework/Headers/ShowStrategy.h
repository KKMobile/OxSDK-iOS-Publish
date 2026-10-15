//
//  ShowStrategy.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ShowStrategyType) {
    STRATEGY_MAX = 0,
    STRATEGY_PANGLE,
    STRATEGY_PRICE,
};

@interface ShowStrategy : NSObject

+ (NSString *)getValue:(ShowStrategyType)strategy;
+ (ShowStrategyType)fromValue:(NSString *)value;

@end
