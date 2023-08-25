//
//  AdEventDelegate.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/6/24.
//

#ifndef AdEventDelegate_h
#define AdEventDelegate_h

@protocol AdEventDelegate<NSObject>

@optional
/**
* Sdk 内部进行事件上报时，将事件信息暴露给客户端，客户端可根据需求进行利用。
* @param name 事件名称。
* @param params 相关参数。
*/
- (void) onTrackEvent:(nonnull NSString *)name params:(nullable nullable NSDictionary *)params;
         
@end

#endif /* AdEventDelegate_h */
