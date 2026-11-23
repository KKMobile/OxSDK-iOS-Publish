#import <Foundation/Foundation.h>
@interface OxFacebookSdkManager : NSObject
+ (instancetype)sharedInstance;
- (void)initializeWithCompletion:(dispatch_block_t)completion;
@end
