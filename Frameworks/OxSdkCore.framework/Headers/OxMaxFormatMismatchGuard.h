//
//  OxMaxFormatMismatchGuard.h
//  OxSdkCore
//
//  兜住 AppLovin「Incorrect format」异常，避免进程崩溃。
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxMaxFormatMismatchGuard : NSObject
+ (void)install;
@end

NS_ASSUME_NONNULL_END
