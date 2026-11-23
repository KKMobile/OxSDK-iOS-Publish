#import <Foundation/Foundation.h>
@class OxAd, IdConfig;
/**
 这个类负责判断：已经有广告可展示了，还要不要再加载一次试试。

 只对配置为 PostBidding 的广告生效，次数从广告位的 extraParameters 里读取：
 {"explore":{"count":2}}

 例如 count=2：已有广告时，允许继续尝试加载；连续成功 2 次后，后面先复用已有广告。
 这里数的是“已经有广告时，再加载并成功”的次数，第一次从没有广告到加载成功不计入。
 没有可用广告、相关配置改变，或这种尝试加载失败/取消时，会重新计数。
 count 没配置或小于等于 0，表示这个类不限制次数，仍由其他加载规则决定是否请求。
 这个类只记次数、给判断结果，不会自己发请求，也不会定时重试。
 */
@interface AdExploreRequestPolicy : NSObject
/// 返回 YES：已经连续成功到配置次数了，这次先用已有广告，不要重新加载。
/// 返回 NO：这个规则不拦截，是否真正请求还要看其他加载条件。
+ (BOOL)shouldSkipReadyReload:(OxAd *)ad idConfig:(IdConfig *)idConfig;
/// 请求开始时调用。wasReady 表示“发请求之前是否已经有广告可展示”。
+ (void)onLoadStarted:(OxAd *)ad idConfig:(IdConfig *)idConfig wasReadyBeforeRequest:(BOOL)wasReady;
/// 加载成功时调用；如果这次属于“已有广告还继续尝试”，就给连续成功次数加 1。
+ (void)onLoadSucceeded:(OxAd *)ad;
/// 加载失败、超时或取消时调用；如果这次属于上面的尝试，就把连续成功次数清零。
+ (void)onLoadFailedOrCancelled:(OxAd *)ad;
@end
