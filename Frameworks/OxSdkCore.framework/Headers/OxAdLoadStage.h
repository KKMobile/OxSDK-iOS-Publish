//
//  OxAdLoadStage.h
//  OxSdkCore
//
//  Created by Cursor on 2026/6/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 广告加载阶段：floor / dynamic / explore
typedef NSString *OxAdLoadStage NS_STRING_ENUM;

/// 底价阶段
FOUNDATION_EXPORT OxAdLoadStage const OxAdLoadStageFloor;
/// Dynamic 跳价阶段
FOUNDATION_EXPORT OxAdLoadStage const OxAdLoadStageDynamic;
/// Explore 上探阶段
FOUNDATION_EXPORT OxAdLoadStage const OxAdLoadStageExplore;

NS_ASSUME_NONNULL_END
