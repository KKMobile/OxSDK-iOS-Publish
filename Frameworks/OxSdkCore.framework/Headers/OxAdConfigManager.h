//
//  OxAdConfigManager.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/11/3.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAdConfigManager : NSObject

@property (nonatomic, assign) NSInteger mMaxRetryAttempt;
@property (nonatomic, assign) NSInteger mCacheAdSize;
@property (nonatomic, assign) BOOL mReload;
@property (nonatomic, assign) BOOL mCloseReload;

/// 从远程配置更新所有设置
- (void)updateFromRemoteConfig:(NSString *)adFormat;

/// 验证配置有效性
- (BOOL)isValid;

/// 重置为默认配置
- (void)resetToDefaults;

/// 打印当前配置
- (void)printConfig;

@end

NS_ASSUME_NONNULL_END
