//
//  VariableRuleManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import "VariableRuleListener.h"

NS_ASSUME_NONNULL_BEGIN

@interface VariableRuleManager : NSObject

+ (instancetype)sharedInstance;
+ (void)releaseInstance;

- (void)setMonitoredRuleTypes:(NSSet<NSString *> *)ruleTypes;
- (void)addListener:(id<VariableRuleListener>)listener;
- (void)removeListener:(id<VariableRuleListener>)listener;
- (void)startMonitoring:(nullable NSSet<NSString *> *)ruleTypes;
- (void)stopMonitoring;
- (void)releaseManager;

/**
 * 由业务主动触发所有已监控可变规则的检查。
 * 当前统一由 App 调用 setGameLevel 后触发一次，不再依赖分钟级轮询。
 */
- (void)triggerAllRuleChecks;

@end

NS_ASSUME_NONNULL_END
