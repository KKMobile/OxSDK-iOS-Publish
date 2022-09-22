//
//  AdHelper.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OxAdSdkManager.h"
#import "AdDelegate.h"
#import "AdValueUtils.h"
NS_ASSUME_NONNULL_BEGIN


@interface OxAdHelper : NSObject

@property (nonatomic, strong) NSString *mAdunitId;

@property (nonatomic, strong, nullable) UIViewController *mViewController;

@property (nonatomic, assign) double mRequestTimestamp;
@property (nonatomic, assign) double mShowingTimestamp;
@property (nonatomic, assign) double mLastShowFailedTimestamp;
@property (nonatomic, strong) NSString *mLoadPlacement;
@property (nonatomic, strong) NSString *mShowPlacement;
@property (nonatomic, strong) NSString *mAdStatus;
@property (nonatomic, strong) NSString *mNetworkName;
@property (nonatomic, strong) NSString *mCreativeId;
@property(nonatomic, strong)NSMutableDictionary<NSString*, NSString*>* mMaxExtraParameterMap;

- (void)loadAd;

- (void)loadAd:(NSString *)placement;

- (double)getDuration:(double)latestTimestamp;

- (void)loadAdInternal:(NSString *)placement;

- (void)destoryAd;

- (BOOL)isReady;

/**
     * 得到展示广告的机会，但因客户端限制（如时间限制）而不去展示时，客户端可以调用此方法上报打点。
     *
     * @param limitation 限制本次广告展示的原因。
     */
- (void)onClientShowingLimitation:(nullable NSString*)limitation;

/**
     * 得到展示广告的机会，但因客户端限制（如时间限制）而不去展示时，客户端可以调用此方法上报打点。
     *
     * @param placement  场景名称。
     * @param limitation 限制本次广告展示的原因。
     */
- (void)onClientShowingLimitation:(nullable NSString*)placement limitation:(nullable NSString*)limitation;

/**
     * 客户端调用 showAd 系列方法。
     *
     * @param placement  场景名称。
     * @param limitation 空则表示，没有遇到限制，可以展示。另一种情况可能为 {@link AdEventUtil#LIMITATION_AD_NOT_READY}
     *                   表示客户端调用 showAd 系列方法，但广告尚未准备好。
     */
- (void)clientInvokingShowAd:(nullable NSString*)placement limitation:(nullable NSString*)limitation;

- (NSString *)appendLimitation:(NSString *)limitation;

-(void) setExtraParametersForMax:(NSString *)key value:(NSString *)value;


- (UIViewController *)mavlVisibleViewController;

@end

NS_ASSUME_NONNULL_END
