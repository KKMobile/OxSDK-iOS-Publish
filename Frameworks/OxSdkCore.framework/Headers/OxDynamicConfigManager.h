//
//  OxDynamicConfigManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2026/1/22.
//  Copyright © 2026 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OxDynamicIDConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxDynamicConfigManager : NSObject

+ (instancetype)sharedInstance;

- (void)initManager;
- (NSInteger)getNaturalInstallDays;
- (NSArray<OxDynamicIDConfig *> *)getConfigsForKey:(NSString *)key;
- (NSArray<OxDynamicIDConfig *> *)getConfigsForKey:(NSString *)key installDays:(NSInteger)installDays;
- (float)getRatioForKey:(NSString *)key mID:(NSString *)mID;
- (float)getRatioForKey:(NSString *)key installDays:(NSInteger)installDays mID:(NSString *)mID;
- (NSArray<NSString *> *)getAllIdsForKey:(NSString *)key;
- (NSArray<NSString *> *)getAllIdsForKey:(NSString *)key installDays:(NSInteger)installDays;
- (BOOL)putConfigForKey:(NSString *)key configStr:(NSString *)configStr;
- (NSArray<NSNumber *> *)getInstallDaysForKey:(NSString *)key;
- (NSInteger)size;
- (void)printAllConfigs;

@end

NS_ASSUME_NONNULL_END
