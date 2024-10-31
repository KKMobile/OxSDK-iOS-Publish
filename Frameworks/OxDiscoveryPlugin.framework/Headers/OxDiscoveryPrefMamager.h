//
//  OxDiscoveryPrefMamager.h
//  OxDiscoveryPlugin
//
//  Created by Mavl_2023_100272 on 2023/6/6.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxDiscoveryPrefMamager : NSObject

@property (nonatomic,assign) NSString *iaaLastTime;  //上次缓存时间
@property (nonatomic,assign) double iaaLtvValue;    // 当天累计
@property (nonatomic,assign) double troasCache001;  // 001缓存
@property (nonatomic,assign) double troasCache01;   // 01缓存

+ (nonnull instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
