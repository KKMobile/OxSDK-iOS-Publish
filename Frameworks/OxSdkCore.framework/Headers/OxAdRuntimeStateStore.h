//
//  OxAdRuntimeStateStore.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAdRuntimeStateStore : NSObject

+ (nullable NSUserDefaults *)sharedUserDefaults;

@end

NS_ASSUME_NONNULL_END
