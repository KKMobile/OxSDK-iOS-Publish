//
//  OxGamesEventUtil.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/1/9.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum : NSUInteger {
    GamesEventType_Custom = 0,
    GamesEventType_Stage,
    GamesEventType_Terminated,
    GamesEventType_Score
} GamesEventType;

NS_ASSUME_NONNULL_BEGIN


@interface OxGamesEventUtil : NSObject

+ (void)trackGamesEvent:(GamesEventType)eventType value:(NSString *)value params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
