//
//  OxFunctionManager.h
//  Pods
//
//  Created by Mavl_2023_100272 on 2025/1/21.
//

#import <Foundation/Foundation.h>
#import "OxUserValueFunction.h"
#import "IOxFunction.h"

NS_ASSUME_NONNULL_BEGIN

@class OxAverageFunction;
@class OxLatestFunction;

@interface OxFunctionManager : NSObject

+ (instancetype)sharedInstance;

- (id<IOxFunction>)getOxUserValueFunction;

@end
NS_ASSUME_NONNULL_END
