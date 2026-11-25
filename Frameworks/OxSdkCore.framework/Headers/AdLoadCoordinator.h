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

/// taskModel 只写入真正发起加载的广告，合并等待者不会覆盖它。
- (void)registerTaskWithTaskId:(NSString *)taskId
                      batchId:(NSString *)batchId
                         adId:(NSString *)adId
                           ad:(OxAd *)ad
                    timeoutMs:(NSTimeInterval)timeoutMs
                    taskModel:(nullable NSString *)taskModel
                     callback:(id<AdLoadTaskCallback>)callback;

/// 原始加载的模式和分组下标只在真正发起 SDK 加载时写入，缓存与合并等待者保留原值。
- (void)registerTaskWithTaskId:(NSString *)taskId
                      batchId:(NSString *)batchId
                         adId:(NSString *)adId
                           ad:(OxAd *)ad
                    timeoutMs:(NSTimeInterval)timeoutMs
                    taskModel:(nullable NSString *)taskModel
                   stageIndex:(nullable NSNumber *)stageIndex
                     callback:(id<AdLoadTaskCallback>)callback;

/// 清理某一批未完成任务。
///
/// 新一轮 load 或 controller destroy 时调用，避免旧批次回调影响新请求。
- (void)cleanupBatch:(NSString *)batchId;

@end

NS_ASSUME_NONNULL_END
