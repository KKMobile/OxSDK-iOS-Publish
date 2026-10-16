//
//  OxFireBaseCrashHelper.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/11/22.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxFireBaseCrashHelper : NSObject

+ (instancetype)sharedInstance;

- (void)impression:(NSString *)adUnitID;

@end

NS_ASSUME_NONNULL_END
