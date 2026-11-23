//
//  InitConfigDurationTracker.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** 将 Init_Config 的墙钟耗时拆成连续且不重叠的阶段。 */
@interface InitConfigDurationTracker : NSObject

@property (nonatomic, copy, readonly) NSString *traceId;

- (void)transitionTo:(NSString *)stage;
- (long long)finish;

@end

NS_ASSUME_NONNULL_END
