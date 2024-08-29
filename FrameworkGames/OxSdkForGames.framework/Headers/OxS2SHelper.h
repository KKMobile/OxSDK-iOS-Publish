//
//  OxS2SHelper.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/8/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxS2SHelper : NSObject


+ (instancetype)sharedInstance;
- (void)s2s:(NSString *)eventName eventParameters:(NSDictionary *)eventParameters retryCount:(NSInteger)retryCount;

@end

NS_ASSUME_NONNULL_END
