//
//  OxOrderManager.h
//  Adjust
//
//  Created by Mavl_2023_100272 on 2025/1/21.
//

#import <Foundation/Foundation.h>
#import "IOxOrder.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxOrderManager : NSObject

+ (instancetype)sharedInstance;

- (id<IOxOrder>)getOxUserValueOrder;

@end

NS_ASSUME_NONNULL_END
