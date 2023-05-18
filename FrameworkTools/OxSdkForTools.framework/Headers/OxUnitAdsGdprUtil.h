//
//  OxUnitAdsGdprUtil.h
//  SwithMediationDemo
//
//  Created by 耿志向 on 2023/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface OxUnitAdsGdprUtil : NSObject

+ (void)initUnityAdsGdprConsentIfShould;

/**
 * 为 UnityAds 设置用户是否接收定向投放广告。
 */
+ (void)setUnityAdsGdprConsent:(BOOL)isAccepted;

@end

NS_ASSUME_NONNULL_END
