//
//  RuleType.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RuleType : NSObject

+ (BOOL)isVariableRule:(NSString *)fieldName;

/** 判断字段名是否为不可变规则（安装后不再变化，如 session/appVersion/channel/campaign/deviceModule） */
+ (BOOL)isImmutableRule:(NSString *)fieldName;

@end

NS_ASSUME_NONNULL_END
