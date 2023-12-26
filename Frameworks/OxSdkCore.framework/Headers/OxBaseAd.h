//
//  OxBaseAd.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2023/10/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OxAdUnit.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxBaseAd : NSObject

@property (nonatomic, strong) NSString *mLoadPlacement;
@property (nonatomic, weak) UIViewController *mViewController;
@property (nonatomic, strong) NSString *adUnitName;
@property (nonatomic, strong) OxAdUnit *adUnit;
@property (nonatomic, assign) OxSdkMediationType  currentMediationType;
@property (nonatomic, strong) NSMutableDictionary<NSString *,NSString *> *mExtraParameterMap;

- (instancetype)initWithAdUnitName:(NSString *)adUnitName;
- (instancetype)initWithAdUnitName:(NSString *)adUnitName viewController:(UIViewController *)viewController;
- (void)initAdCondig:(NSString *)adUnitName;

- (void)loadAd;
- (void)loadAdWithPlacement:(NSString *)placement;

- (void)destoryAd;

/// 设置ExtraParameters
/// - Parameters:
- (void)setExtraParameters:(NSString *)key value:(NSString *)value;

/// 得到展示广告的机会，但因客户端限制（如时间限制）而不去展示时，客户端可以调用此方法上报打点。
/// - Parameters:
///   - limitation: 限制本次广告的原因
- (void)onClientShowingLimitation:(NSString *)limitation;

/// 得到展示广告的机会，但因客户端限制（如时间限制）而不去展示时，客户端可以调用此方法上报打点。
/// - Parameters:
///   - placement: 场景名称
///   - limitation: 限制本次广告的原因
- (void)onClientShowingLimitation:(NSString *)placement limitation:(NSString *)limitation;

@end

NS_ASSUME_NONNULL_END
