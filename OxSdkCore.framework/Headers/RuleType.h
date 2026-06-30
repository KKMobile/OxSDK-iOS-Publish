//
//  RuleType.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RuleType : NSObject

+ (BOOL)isVariableRule:(NSString *)fieldName;

@end

NS_ASSUME_NONNULL_END
