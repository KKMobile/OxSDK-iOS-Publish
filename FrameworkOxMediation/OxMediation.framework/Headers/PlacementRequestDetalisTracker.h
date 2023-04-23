//
//  PlacementRequestDetalisTracker.h
//  OxMediation
//
//  Created by 耿志向 on 2023/4/14.
//  Copyright © 2023 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMAdBasePrivate.h"

NS_ASSUME_NONNULL_BEGIN

@interface PlacementRequestDetalisTracker : NSObject

+ (void)trackEvent:(NSString *)wfReqId placementId:(NSString *)placementId adFormat:(OxMediationAdFormat)adFormat c2s:(NSArray *)c2s wfs:(NSArray *)wfs load_duration:(double)load_duration  error:(nullable NSError *)error;

@end

NS_ASSUME_NONNULL_END
