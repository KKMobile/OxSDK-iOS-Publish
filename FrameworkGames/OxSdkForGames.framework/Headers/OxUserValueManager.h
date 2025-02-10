//
//  OxUserValueManager.h
//  Adjust
//
//  Created by Mavl_2023_100272 on 2025/1/21.
//

#import <Foundation/Foundation.h>
#import "OxUserValuePreferenceManager.h"
#import "OxOrderManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxUserValueManager : NSObject

/// 获取单例对象
+ (instancetype)sharedInstance;

/// 标记是否为测试模式
@property (nonatomic, assign) BOOL isTest;

/// 使用 Firebase 初始化周期配置
- (void)initPeriodsByFirebase;

/// 设置测试值
- (void)setTestValue:(BOOL)isTest
                order:(NSString *)order
             function:(NSString *)function
               factor:(float)factor
      durationPeriods:(NSString *)durationPeriods
       quantityPeriods:(NSString *)quantityPeriods
       summaryPeriods:(NSString *)summaryPeriods;

/// 通过 ECPM 获取瀑布流区间
- (float)getWaterfallByEcpm:(NSString *)adUnitId;

/// 处理 ECPM 数据
- (void)handleEcpm:(double)ecpm adUnitId:(NSString *)adUnitId;

@end

NS_ASSUME_NONNULL_END
