//
//  OxAdPrivate.m
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/6/19.
//  Copyright © 2024 耿志向. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "OxAd.h"
#import "OxAdUnit.h"
#import "AdReward.h"
#import "AppUtils.h"
#import "PureLayout.h"
#import "OxSdkConfig.h"
#import "OxNativeAdapterAd.h"
#import "OxSdkBuilder.h"
#import "OxResBundleUtil.h"
#import "OxAdData.h"
#import "OxMAAdRevenueDelegateImpl.h"

@import AppLovinSDK;
@import GoogleMobileAds;

@protocol OxAdDelegate <NSObject>

- (void)onAdDidOpen:(OxAd *)ad;
- (void)onAdDidShow:(OxAd *)ad;
- (void)onAdDidFailToShow:(OxAd *)ad error:(NSError *)error;
- (void)onAdDidClick:(OxAd *)ad;
- (void)onAdDidClose:(OxAd *)ad;

@optional
- (void)onAdDidReward:(OxAd *)ad reward:(AdReward *)reward;

@end


@interface OxAd() <MAAdDelegate,MARewardedAdDelegate,MAAdViewAdDelegate,GADFullScreenContentDelegate,GADBannerViewDelegate,MANativeAdDelegate,GADNativeAdDelegate,GADVideoControllerDelegate>

@property(nonatomic, assign,readonly) OxSdkAdFormat adFormat;
@property(nonatomic, copy,readonly) NSString *adFormatValue;
@property(nonatomic, copy,readonly) NSString *adUnitName;
@property(nonatomic, copy,readonly) NSString *adUnitId;
@property(nonatomic, copy,readonly) NSString *showPlacement;
@property(nonatomic, assign) long loadStartTime;
@property(nonatomic, assign) long showingTimestamp;
@property(nonatomic, weak) id<OxAdDelegate> delegate;
@property(nonatomic, strong,readonly) id ad;
@property(nonatomic, strong,readonly) id value; // 存储 打点数据上报
@property(nonatomic, assign) BOOL mAutoRefresh; // 是否允许自动刷新
@property(nonatomic, strong) UIView *customView; // 是否允许自动刷新
@property (nonatomic, strong) OxMAAdRevenueDelegateImpl* oxMAAdRevenueDelegateImpl;


- (instancetype)initWithAd:(id)ad adUnitName:(NSString *)adUnitName adUnitId:(NSString *)adUnitId value:(id)value;


- (void)showAd:(NSString *)showPlacement delegate:(id<OxAdDelegate>)delegate;

// 展示 Banner Native Mrec 等
- (void)showAd:(UIView *)adContainerV showPlacement:(NSString *)showPlacement delegate:(id<OxAdDelegate>)delegate;

// 广告是否可用
- (BOOL)isReady;

// Banner API
- (void)hiddenAd;
- (void)startAutoRefresh;
- (void)stopAutoRefresh;

// 销毁广告
- (void)destory;

@end
