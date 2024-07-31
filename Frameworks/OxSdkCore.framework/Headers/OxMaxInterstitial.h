//
//  OMMaxInterstitial.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/6/1.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OxBaseCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxMaxInterstitial : NSObject <OxBaseCustomEvent>

@property (nonatomic, copy) NSString *pid;
@property (nonatomic, copy) NSString *adUnitName;
@property (nonatomic, weak) id<OxCustomEventDelegate> delegate;

@end

NS_ASSUME_NONNULL_END