#import <Foundation/Foundation.h>
@interface OxPangleSdkManager : NSObject
+ (instancetype)sharedInstance;
- (void)initializeWithCompletion:(dispatch_block_t)completion;
@end
