//
//  RuleCondition.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RuleCondition : NSObject

@property (nonatomic, copy) NSString *fieldName;
@property (nonatomic, strong, nullable) id value;
@property (nonatomic, copy) NSString *operatorName;
@property (nonatomic, assign) NSInteger priority;

- (instancetype)initWithFieldName:(NSString *)fieldName
                            value:(nullable id)value
                         operator:(NSString *)operatorName
                         priority:(NSInteger)priority;

@end

NS_ASSUME_NONNULL_END
