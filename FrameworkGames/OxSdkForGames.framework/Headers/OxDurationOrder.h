//
//  OxDurationOrder.h
//  Adjust
//
//  Created by Mavl_2023_100272 on 2025/1/21.
//

#import <Foundation/Foundation.h>
#import "IOxOrder.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxDurationOrder : NSObject <IOxOrder>

@property (nonatomic, assign) BOOL isResetDuration; // 是否是边界值
@property (nonatomic, assign) NSInteger period; // 周期值
@property (nonatomic, assign) NSInteger targetDurationPeriod; // 周期边界值，以及循环之后的边界值
@property (nonatomic, assign) NSTimeInterval initCurrentTimeMillis; // 初始化时间


@end

NS_ASSUME_NONNULL_END
