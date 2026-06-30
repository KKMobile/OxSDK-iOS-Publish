//
//  ConfigSegment.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class AdConfig;
@class RuleCondition;

NS_ASSUME_NONNULL_BEGIN

@interface ConfigSegment : NSObject

@property (nonatomic, copy, readonly) NSArray *rules;
@property (nonatomic, strong, readonly) AdConfig *config;
@property (nonatomic, copy, readonly) NSString *version;

- (instancetype)initWithRules:(NSArray *)rules
                       config:(AdConfig *)config
                      version:(NSString *)version;

- (BOOL)isMatch;
- (NSSet<NSString *> *)variableRuleTypes;

@end

NS_ASSUME_NONNULL_END
