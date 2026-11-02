//
//  RulesUtils.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RulesUtils : NSObject

+ (NSString *)getVersionName;
+ (NSString *)getChannel;
+ (NSString *)getCampaign;
/// 仅供广告配置分群使用：空归因统一按 unknown 参与规则匹配。
+ (NSString *)getChannelForRule;
+ (NSString *)getCampaignForRule;
+ (NSInteger)getInstallDays;
+ (NSInteger)getInstallHours;
+ (NSInteger)getSessionCount;
+ (NSString *)getDeviceModel;
+ (NSString *)getCustomValue;
+ (NSInteger)getPassLevels;
+ (double)getPlayMinutes;
+ (double)getPayCounts;
+ (double)getRam;
+ (double)getRom;
+ (NSString *)getGameCoreValue;
+ (NSString *)getMemoryControlValue;

/// 汇总当前全部分群规则运行时取值（便于一次对比命中条件）
+ (NSDictionary<NSString *, id> *)allRuleSnapshot;
/// 打印规则快照；reason 标识触发来源（如 setGameLevel / segment_eval）
+ (void)logAllRuleSnapshot:(NSString *)reason;

@end

NS_ASSUME_NONNULL_END
