//
//  OxAdManagerPrivate.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/6/18.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"
#import "OxAdUnit.h"
#import "OxSdkConfig.h"
#import "OxAdLoader.h"
#import "OxAdPrivate.h"
#import "OxAdStrategy.h"

#define MAXLOADCOUNT 5

@class OxNativeViewBinder;

NS_ASSUME_NONNULL_BEGIN
@interface OxAdManager() <OxAdStrategyLoadDelegate,OxAdDelegate>

@property (nonatomic, assign) OxSdkAdFormat adFormat;
@property (nonatomic, strong) NSMutableDictionary<NSString *,OxAdStrategy *> *adStrategyMap;
@property (nonatomic, strong) NSMutableDictionary<NSString *,NSNumber *> *showTimeMap;
@property (nonatomic, strong) NSMapTable *adUnitNameDelegateMap;
@property (nonatomic, strong) NSMapTable *showPlacementNameDelegateMap;
@property (nonatomic, strong) NSMutableArray<OxAd *> *adList;

- (OxAdStrategy *)createAdStrategy:(NSString *)adUnitName;
- (OxAd *)getAd:(NSString *)adUnitName showPlacement:(NSString *)showPlacement;

- (void)show:(nullable UIView *)adContainerV viewBinder:(nullable OxNativeViewBinder *)viewBinder adUnitName:(NSString *)adUnitName showPlacement:(NSString *)showPlacement delegate:(id<OxAdActionDelegate>)delegate;
- (void)show:(nullable UIView *)adContainerV adUnitName:(NSString *)adUnitName showPlacement:(NSString *)showPlacement delegate:(id<OxAdActionDelegate>)delegate;
- (void)show:(NSString *)adUnitName showPlacement:(NSString *)showPlacement delegate:(id<OxAdActionDelegate>)delegate;
// banner APIA
- (void)hidden:(NSString *)adUnitName showPlacement:(NSString *)showPlacement;
- (void)startAutoRefresh:(NSString *)adUnitName showPlacement:(NSString *)showPlacement;
- (void)stopAutoRefresh:(NSString *)adUnitName showPlacement:(NSString *)showPlacement;


@end

NS_ASSUME_NONNULL_END
