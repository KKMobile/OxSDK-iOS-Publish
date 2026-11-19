//
//  OxAdjustEventTracker.h
//  OxAdjustPlugin
//
//  Created by Mavl_2023_100272 on 2024/10/23.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 OxSDK 与 Adjust 之间的插件桥接类。
 将 Core 事件转换为 Adjust 事件或广告收入，并缓存 Adjust 的渠道、广告系列及 Adid。
 宿主负责初始化 Adjust SDK，Core 负责提供事件名称与 Adjust token 的对应表。
 */
@interface OxAdjustEventTracker : NSObject

/**
 统一上报入口：adjustParams 中的 params 是事件参数，tokenMap 是事件名到 Adjust token 的映射。
 params.event_type：0 或其他值不上报；1 只报普通事件；2 只报广告收入；3 先报事件再报收入。
 */
+ (void)trackEvent:(NSString *)eventName adjustParams:(nullable NSDictionary *)adjustParams;

/** 读取渠道，如 Facebook；优先返回缓存，归因不完整时可能触发有限次数的异步重试。 */
+ (NSString *)getNetwork;
/** 读取广告系列；返回规则同 getNetwork，暂无有效值时返回空字符串。 */
+ (NSString *)getCampaign;
/** 读取 Adjust 分配的设备标识 Adid（区别于苹果 IDFA）；暂无有效值时异步查询并返回空字符串。 */
+ (NSString *)getAdID;
/** 注册 Core 的归因变更回调并立即查询一次；仅有效值变化时通知，传 nil 取消监听。 */
+ (void)setAttributionChangedHandler:(void (^ _Nullable)(NSString * _Nullable channel, NSString * _Nullable campaign))handler;
/**
 初始化及宿主归因变更时主动查询，不受 3 次上限和 5 秒间隔限制，但仍避免并发重复查询。
 异步结果更新缓存，有效归因变化时通过上述回调通知 Core；不会重置自动重试次数。
 */
+ (void)refreshAttribution;


@end

NS_ASSUME_NONNULL_END
