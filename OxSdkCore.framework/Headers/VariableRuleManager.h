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

@end

NS_ASSUME_NONNULL_END
