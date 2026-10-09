//
//  AdLoadCoordinator.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class OxAd;

NS_ASSUME_NONNULL_BEGIN

@protocol AdLoadTaskCallback <NSObject>
/// 某一路任务等到广告加载成功。
- (void)onSuccess:(OxAd *)ad;
/// 某一路任务等到广告加载失败或任务超时。
- (void)onFailure:(OxAd *)ad error:(nullable NSString *)error;
@end

/// 广告加载协调器。
///
/// 这个类不决定“要加载哪些广告”，也不决定“加载顺序”。
/// 它只负责把 BaseTaskController 创建出来的一路路加载任务统一登记起来，
/// 并保证同一个 adId 或同一个受限请求 key 在同一时间尽量只触发一次真实 SDK load。
///
/// 核心职责：
/// 1. 记录 taskId、batchId、adId、callback 的关系。
/// 2. 多个 task 等同一个 adId 时，只发起一次 loadAd，结果回来后广播给所有 task。
/// 3. post-bidding/native/AdMob 全屏等受限类型，按 AdLoadRequestPolicy 合并正在加载中的重复请求。
/// 4. 给每个 task 设置独立超时，避免单路任务一直挂起。
/// 5. batch 销毁时清理该 batch 的未完成 task。
@interface AdLoadCoordinator : NSObject

+ (instancetype)sharedInstance;

/// 注册一条加载任务。
///
/// taskId：一次具体加载任务的唯一标识。
/// batchId：一批加载任务的标识，BaseTaskController 销毁时会按 batchId 清理。
/// adId：广告位 ID，同一个 adId 的多个 task 会共享同一个加载状态。
/// ad：真正执行 loadAdInternalWithListener 的 OxAd 对象。
/// timeoutMs：该 task 的超时时间，单位毫秒。
/// callback：加载成功、失败、超时时回调给 BaseTaskController。
- (void)registerTaskWithTaskId:(NSString *)taskId
                       batchId:(NSString *)batchId
                         adId:(NSString *)adId
                            ad:(OxAd *)ad
                     timeoutMs:(NSTimeInterval)timeoutMs
                      callback:(id<AdLoadTaskCallback>)callback;

/// 清理某一批未完成任务。
///
/// 新一轮 load 或 controller destroy 时调用，避免旧批次回调影响新请求。
- (void)cleanupBatch:(NSString *)batchId;

@end

NS_ASSUME_NONNULL_END
