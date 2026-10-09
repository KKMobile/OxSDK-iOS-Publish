//
//  OxUnitAdsGdprUtil.h
//  OxSDK-Game
//
//  Created by 耿志向 on 2023/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxUnitAdsGdprUtil : NSObject

/**
 * 首次进入 GDPR 流程时为 UnityAds 设置默认 consent。
 * 如果用户此前已经通过本工具同步过 consent，则不重复写入。
 */
+ (void)initUnityAdsGdprConsentIfShould;

/**
 * 为 UnityAds 设置用户是否接受 GDPR 个性化广告。
 */
+ (void)setUnityAdsGdprConsent:(BOOL)isAccepted;

@end

NS_ASSUME_NONNULL_END
