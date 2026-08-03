//
//  AdLoadCoordinator.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class OxAd;

NS_ASSUME_NONNULL_BEGIN

@protocol AdLoadTaskCallback <NSObject>
- (void)onSuccess:(OxAd *)ad;
- (void)onFailure:(OxAd *)ad error:(nullable NSString *)error;
@end

@interface AdLoadCoordinator : NSObject

+ (instancetype)sharedInstance;

- (void)registerTaskWithTaskId:(NSString *)taskId
                       batchId:(NSString *)batchId
                         adId:(NSString *)adId
                            ad:(OxAd *)ad
                     timeoutMs:(NSTimeInterval)timeoutMs
                      callback:(id<AdLoadTaskCallback>)callback;

- (void)cleanupBatch:(NSString *)batchId;

@end

NS_ASSUME_NONNULL_END
