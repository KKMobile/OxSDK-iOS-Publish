//
//  OxBaseAd.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2023/7/20.
//  Copyright © 2023 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdEvents.h"
#import "OxAdUnit.h"

NS_ASSUME_NONNULL_BEGIN

@class OxAdHelper;

@interface OxBaseAd : NSObject

@property (nonatomic, strong) NSString *adUnitName;
@property (nonatomic, strong) NSString *mLoadPlacement;
@property (nonatomic, assign) OxSdkMediationType currentMediationType;
@property (nonatomic, strong) NSMutableDictionary<NSNumber *,OxAdHelper *> *mAdHelpersMap;
@property (nonatomic, weak) UIViewController *mViewController;
@property (nonatomic, strong) OxAdUnit *adUnit;
@property (nonatomic, assign) BOOL isReloadAfterFailed;
@property (nonatomic, strong) NSMutableDictionary<NSString *,NSString *> *mExtraParameterMap;

- (instancetype)initWithAdUnitName:(NSString *)adUnitName;
- (instancetype)initWithAdUnitName:(NSString *)adUnitName viewController:(UIViewController *)viewController;
- (void)initAdCondig:(NSString *)adUnitName;

- (void)loadAd;
- (void)loadAdWithPlacement:(NSString *)placement;

- (void)destoryAd;

@end

NS_ASSUME_NONNULL_END
