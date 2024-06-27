//
//  OxClientConfig.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2023/6/9.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdEventDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxClientConfig : NSObject

@property (nonatomic,weak) id<AdEventDelegate> delegate;

+ (nonnull instancetype)sharedInstance;
- (void)onTrackEvent:(nonnull NSString *)name params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
