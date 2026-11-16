//
//  OxNaturalDayInstallUtil.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxNaturalDayInstallUtil : NSObject

/// 兼容旧入口，内部转发至 RulesUtils.getInstallDays。
+ (NSInteger)getNaturalInstallDays;

@end

NS_ASSUME_NONNULL_END
