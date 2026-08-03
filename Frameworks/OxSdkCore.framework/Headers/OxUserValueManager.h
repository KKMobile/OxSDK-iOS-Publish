//
//  OxUserValueManager.h
//  Adjust
//
//  Created by Mavl_2023_100272 on 2025/1/21.
//

#import <Foundation/Foundation.h>
#import "OxUserValuePreferenceManager.h"
#import "OxOrderManager.h"
#import "OxUserValueConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxUserValueManager : NSObject

/// 获取单例对象
+ (instancetype)sharedInstance;

/// 标记是否为测试模式
@property (nonatomic, assign) BOOL isTest;

/// 配置解析完成后初始化 UserValue（对齐 Android initManager）
- (void)initManager;

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
- (NSString *)getSegmentValueByAdUnitId:(NSString *)adUnitId ecpm:(float)ecpm;

/// 处理 ECPM 数据
- (void)handleEcpm:(double)ecpm adUnitId:(NSString *)adUnitId;

- (BOOL)isHitUserValueSegmentWithAdUnitName:(NSString *)adUnitName adUnitID:(NSString *)adUnitID;

- (float)getUserValueByAdUnitName:(NSString *)adUnitName;

@end
NS_ASSUME_NONNULL_END
