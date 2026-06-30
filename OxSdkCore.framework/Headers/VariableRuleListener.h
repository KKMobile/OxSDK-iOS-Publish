//
//  VariableRuleListener.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VariableRuleListener <NSObject>
- (void)onRuleChanged:(NSString *)ruleType oldValue:(nullable id)oldValue newValue:(nullable id)newValue;
- (void)onNeedReevaluate:(NSString *)ruleType;
@end

NS_ASSUME_NONNULL_END
