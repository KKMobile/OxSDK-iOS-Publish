//
//  PangleSdkManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PangleSdkManager : NSObject

+ (instancetype)sharedInstance;

- (void)initializeWithContext:(nullable id)context runnable:(nullable dispatch_block_t)runnable;

- (BOOL)isSdkInitialed;

@end

NS_ASSUME_NONNULL_END
