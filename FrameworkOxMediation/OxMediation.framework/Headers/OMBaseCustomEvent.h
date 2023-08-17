//
//  OMBaseCustomEvent.h
//  OxMediation
//
//  Created by 耿志向 on 2023/3/27.
//  Copyright © 2023 AdTiming. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "OMBidCustomEvent.h"
#import "OMCustomEventDelegate.h"
#import "OMLogMoudle.h"

@protocol OMBaseCustomEvent <NSObject>

@optional
- (void)setBidDelegate:(id<OMBidCustomEventDelegate>)bidDelegate;
- (void)loadAdWithLocalExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (void)loadAdWithBidPayload:(NSString*)bidPayload localExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter;
- (void)setBidParameters:(id)parameters;
@end
