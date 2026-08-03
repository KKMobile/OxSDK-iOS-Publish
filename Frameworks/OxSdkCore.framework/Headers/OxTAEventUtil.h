//
//  OxTAEventUtil.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxTAEventUtil : NSObject

+ (void)trackEventTA:(NSString *)eventName params:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
