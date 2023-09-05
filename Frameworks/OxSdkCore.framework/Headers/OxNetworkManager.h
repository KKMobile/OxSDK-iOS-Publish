//
//  OxNetworkManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2023/7/7.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworkReachabilityManager.h"

static NSString * const UDK_NETWORK_CHANGE = @"UDK_NETWORK_CHANGE";

NS_ASSUME_NONNULL_BEGIN

@interface OxNetworkManager : NSObject

@property (nonatomic, strong) AFNetworkReachabilityManager* reachabilityManager;

+ (nonnull instancetype)sharedInstance;

- (void)startMonitoring;

@end

NS_ASSUME_NONNULL_END
