//
//  OxGlobalStrategy.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxGlobalStrategy : NSObject

+ (instancetype)sharedInstance;

- (BOOL)isBlockedByIntervalRule:(NSString *)adUnitName;
- (void)onAdClosed:(NSString *)adUnitName;

@end

NS_ASSUME_NONNULL_END
