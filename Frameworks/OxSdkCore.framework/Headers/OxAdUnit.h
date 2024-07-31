//
//  OxAdUnitIds.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/5/31.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    OxLoadPriorityDefault,
    OxLoadPriorityLow,
    OxLoadPriorityMiddle,
    OxLoadPriorityHigh
} OxLoadPriority;

@class OxAdUnitIds;

@interface OxAdUnit : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) OxSdkAdFormat adFormat;
@property (nonatomic, copy) NSString *adFormatValue;
@property (nonatomic, assign) OxSdkMediationType mediationType;
@property (nonatomic, assign) OxLoadPriority priority;  // 是否是预加载
@property (nonatomic, strong) OxAdUnitIds *adUnitIds;

- (NSString *)getTargetAdUnitId:(OxSdkMediationType)mediationType;
- (OxSdkMediationType)getTargetMediation;

@end

@interface  OxAdUnitIds : NSObject

@property (nonatomic, copy) NSString *max;
@property (nonatomic, copy) NSString *admob;

@end


NS_ASSUME_NONNULL_END
