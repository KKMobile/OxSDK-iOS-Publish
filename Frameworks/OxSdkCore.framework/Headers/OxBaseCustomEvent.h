//
//  OMBaseCustomEvent.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/6/1.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "OxCustomEventDelegate.h"
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@protocol OxBaseCustomEvent <NSObject>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, copy) NSString *adUnitName;
@property(nonatomic, weak, nullable) id<OxCustomEventDelegate> delegate;
- (instancetype)initWithParameter:(NSDictionary *)adParameter;


@optional
- (void)loadAdWithParameter:(nullable NSDictionary<NSString *,id> *)parameter;
- (void)setExtraParameters:(NSString *)key value:(NSString *)value;

@end

NS_ASSUME_NONNULL_END
