//
//  OxSdkBuilder.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/5/29.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxSdkBuilder : NSObject

/// 设置测试模式
@property(nonatomic, assign) BOOL testModel;
/// 设置静音
@property(nonatomic, assign) BOOL muted;
/// 核心 Level
@property(nonatomic, assign) NSInteger corelevel;
/// 应用安装天数
@property(nonatomic, assign) int dayCountSinceInstall;
/// 用户ID
@property(nonatomic, copy) NSString *userId;

@property (nonatomic,strong,readonly) NSMutableDictionary<NSString *,NSMutableDictionary *> *maxExtraParameterMap;

/// 为Max  设置扩展参数
/// - Parameters:
///   - adUnitName: adUnitName
///   - value: value
///   - key: key
- (void)setExtraParameter:(NSString *)adUnitName value:(NSString *)value  forKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
