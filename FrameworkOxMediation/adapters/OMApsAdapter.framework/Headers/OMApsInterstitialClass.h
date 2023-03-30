//
//  OMApsInterstitialClass.h
//  OxMediation
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#ifndef OMApsInterstitialClass_h
#define OMApsInterstitialClass_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "OMApsClass.h"
#import "OMApsBannerClass.h"

NS_ASSUME_NONNULL_BEGIN

@class DTBAdInterstitialDispatcher;
@protocol DTBAdInterstitialDispatcherDelegate;

@protocol DTBAdInterstitialDispatcherDelegate<NSObject>

/// Sent when an interstitial ad has loaded.
- (void)interstitialDidLoad:(DTBAdInterstitialDispatcher * _Nullable )interstitial;

/// Sent when banner ad has failed to load.
- (void)interstitial:(DTBAdInterstitialDispatcher * _Nullable )interstitial
    didFailToLoadAdWithErrorCode:(DTBAdErrorCode)errorCode;

/// Sent when an interstitial is about to be shown.
- (void)interstitialWillPresentScreen:(DTBAdInterstitialDispatcher * _Nullable )interstitial;

/// Sent when an interstitial is about to be shown.
- (void)interstitialDidPresentScreen:(DTBAdInterstitialDispatcher * _Nullable )interstitial;

/// Sent when an interstitial is about to be dismissed.
- (void)interstitialWillDismissScreen:(DTBAdInterstitialDispatcher * _Nullable )interstitial;

/// Sent when an interstitial has been dismissed.
- (void)interstitialDidDismissScreen:(DTBAdInterstitialDispatcher * _Nullable )interstitial;

/// Sent when an interstitial is clicked and an external application is launched.
- (void)interstitialWillLeaveApplication:(DTBAdInterstitialDispatcher * _Nullable )interstitial;

- (void)showFromRootViewController:(UIViewController *_Nonnull)controller ;

- (void)impressionFired;

@optional
- (void)videoPlaybackCompleted:(DTBAdInterstitialDispatcher *) interstitial;
- (void)adClicked;

@end


@interface DTBAdInterstitialDispatcher : DTBAdDispatcher

@property(nonatomic, weak) id<DTBAdInterstitialDispatcherDelegate> delegate;

@property(nonatomic, assign) BOOL interstitialLoaded;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithDelegate:(id<DTBAdInterstitialDispatcherDelegate>)delegate;
- (void)fetchAd:(NSString *)bidInfo;
- (void)fetchAdWithParameters:(NSDictionary *)params;
- (void)fetchAd:(NSString *)bidInfo params:(NSDictionary * _Nullable)params;
- (void)showFromController:(UIViewController *_Nonnull)controller ;

- (void)interstitialWillAppear;
- (void)interstitialDidAppear;
- (void)interstitialWillDisappear;
- (void)interstitialDidDisappear;


+ (void)showInterstitialFromController:(UIViewController * _Nonnull)controller;

@end

NS_ASSUME_NONNULL_END


#endif /* OMApsInterstitialClass_h */
