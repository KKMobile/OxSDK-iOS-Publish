#import <Foundation/Foundation.h>
FOUNDATION_EXPORT NSString * const OxShowStrategyMainMediation;
FOUNDATION_EXPORT NSString * const OxShowStrategyPrice;
FOUNDATION_EXPORT NSString * const OxShowStrategyMax;
@interface ShowStrategy : NSObject
+ (NSString *)resolve:(NSString *)strategy;
@end
