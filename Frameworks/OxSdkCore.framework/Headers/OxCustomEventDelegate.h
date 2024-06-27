//
//  OxCustomEventDelegate.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/6/1.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol OxCustomEventDelegate <NSObject>

- (void)customEvent:(id)adapter didLoadAd:(id)adObject value:(id)value;
- (void)customEvent:(id)adapter didFailToLoadWithError:(NSError*)error;

@end

NS_ASSUME_NONNULL_END
