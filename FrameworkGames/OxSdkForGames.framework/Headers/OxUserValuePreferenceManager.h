//
//  OxUserValuePreferenceManager.h
//  Adjust
//
//  Created by Mavl_2023_100272 on 2025/1/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxUserValuePreferenceManager : NSObject

@property (nonatomic, assign,readonly) NSTimeInterval firstInit;
@property (nonatomic, assign) float targetEcpm;
@property (nonatomic, copy) NSString *order; // 计算方案
@property (nonatomic, copy,readonly) NSString *orderVersion; // 计算方案版本号
@property (nonatomic, copy) NSString *function; // 统计方式
@property (nonatomic, assign) float factor; // 计算系数
@property (nonatomic, copy) NSString *durationPeriods; // 时间周期数组
@property (nonatomic, copy) NSString *quantityPeriods; // 行为周期数组
@property (nonatomic, copy) NSString *summaryPeriods; // 价格周期数组

+ (instancetype)sharedInstance;

- (void)setTargetEcpm:(float)ecpm forKey:(NSString *)key;
- (float)getTargetEcpm:(NSString *)key;

- (void)setFloat:(float)f forKey:(NSString *)key;
- (void)mergeFloat:(float)f forKey:(NSString *)key;
- (float)getFloat:(NSString *)key;

- (void)setInt:(NSInteger)i forKey:(NSString *)key;
- (void)mergeInt:(NSInteger)i forKey:(NSString *)key;
- (NSInteger)getInt:(NSString *)key;

- (void)setString:(NSString *)value forKey:(NSString *)key;
- (NSString *)getString:(NSString *)key;


@end
NS_ASSUME_NONNULL_END
