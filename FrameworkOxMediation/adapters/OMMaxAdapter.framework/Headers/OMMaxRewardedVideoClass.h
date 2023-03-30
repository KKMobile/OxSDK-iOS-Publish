//
//  OMMaxRewardedVideoClass.h
//  OMMaxAdapter
//
//  Created by 耿志向 on 2022/11/13.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#ifndef OMMaxRewardedVideoClass_h
#define OMMaxRewardedVideoClass_h

#import "OMMaxBannerClass.h"

NS_ASSUME_NONNULL_BEGIN

@class MAReward;

@protocol MARewardedAdDelegate<MAAdDelegate>

/**
 * The SDK invokes this method when rewarded video has started.
 */
- (void)didStartRewardedVideoForAd:(MAAd *)ad;

/**
 * The SDK invokes this method when rewarded video has completed.
 */
- (void)didCompleteRewardedVideoForAd:(MAAd *)ad;

/**
 * The SDK invokes this method when a user should be granted a reward.
 *
 * @param ad     Ad for which the reward ad was rewarded.
 * @param reward The reward to be granted to the user.
 */
- (void)didRewardUserForAd:(MAAd *)ad withReward:(MAReward *)reward;

@end

@interface MARewardedAd : NSObject

/**
 * Gets an instance of a MAX rewarded ad.
 *
 * @param adUnitIdentifier Ad unit ID for which to get the ad instance.
 *
 * @return An instance of a rewarded ad tied to the specified ad unit ID.
 */
+ (instancetype)sharedWithAdUnitIdentifier:(NSString *)adUnitIdentifier;

/**
 * Get an instance of a MAX rewarded ad.
 *
 * @param adUnitIdentifier Ad unit ID for which to get the ad instance.
 * @param sdk              SDK to use.
 *
 * @return An instance of a rewarded ad tied to the specified ad unit ID.
 */
+ (instancetype)sharedWithAdUnitIdentifier:(NSString *)adUnitIdentifier sdk:(ALSdk *)sdk;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * A delegate that will be notified about ad events.
 */
@property (nonatomic, weak, nullable) id<MARewardedAdDelegate> delegate;

/**
 * A delegate that will be notified about ad revenue events.
 */
@property (nonatomic, weak, nullable) id<MAAdRevenueDelegate> revenueDelegate;

/**
 * A delegate that will be notified about Ad Review events.
 */
@property (nonatomic, weak, nullable) id<MAAdReviewDelegate> adReviewDelegate;

/**
 * Load the current rewarded ad. Use @code [MARewardedAd delegate] @endcode to assign a delegate that should be notified about ad load state.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/rewarded-ads#loading-a-rewarded-ad">MAX Integration Guide ⇒ iOS ⇒ Rewarded Ads ⇒ Loading a Rewarded Ad</a>
 */
- (void)loadAd;

/**
 * Show the loaded rewarded ad.
 * <ul>
 * <li>Use @code [MARewardedAd delegate] @endcode to assign a delegate that should be notified about display events.</li>
 * <li>Use @code [MARewardedAd ready] @endcode to check if an ad was successfully loaded.</li>
 * </ul>
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/rewarded-ads#showing-a-rewarded-ad">MAX Integration Guide ⇒ iOS ⇒ Rewarded Ads ⇒ Showing a Rewarded Ad</a>
 */
- (void)showAd;

/**
 * Show the loaded rewarded ad for a given placement to tie ad events to.
 * <ul>
 * <li>Use @code [MARewardedAd delegate] @endcode to assign a delegate that should be notified about display events.</li>
 * <li>Use @code [MARewardedAd ready] @endcode to check if an ad was successfully loaded.</li>
 * </ul>
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/rewarded-ads#showing-a-rewarded-ad">MAX Integration Guide ⇒ iOS ⇒ Rewarded Ads ⇒ Showing a Rewarded Ad</a>
 *
 * @param placement The placement to tie the showing ad’s events to.
 */
- (void)showAdForPlacement:(nullable NSString *)placement;

/**
 * Show the loaded rewarded ad for a given placement and custom data to tie ad events to.
 * <ul>
 * <li>Use @code [MARewardedAd delegate] @endcode to assign a delegate that should be notified about display events.</li>
 * <li>Use @code [MARewardedAd ready] @endcode to check if an ad was successfully loaded.</li>
 * </ul>
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/rewarded-ads#showing-a-rewarded-ad">MAX Integration Guide ⇒ iOS ⇒ Rewarded Ads ⇒ Showing a Rewarded Ad</a>
 *
 * @param placement The placement to tie the showing ad’s events to.
 * @param customData The custom data to tie the showing ad’s events to. Maximum size is 8KB.
 */
- (void)showAdForPlacement:(nullable NSString *)placement customData:(nullable NSString *)customData;

/**
 * Show the loaded rewarded ad for a given placement and custom data to tie ad events to, and a view controller to present the ad from.
 * <ul>
 * <li>Use @code [MARewardedAd delegate] @endcode to assign a delegate that should be notified about display events.</li>
 * <li>Use @code [MARewardedAd ready] @endcode to check if an ad was successfully loaded.</li>
 * </ul>
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/rewarded-ads#showing-a-rewarded-ad">MAX Integration Guide ⇒ iOS ⇒ Rewarded Ads ⇒ Showing a Rewarded Ad</a>
 *
 * @param placement The placement to tie the showing ad’s events to.
 * @param customData The custom data to tie the showing ad’s events to. Maximum size is 8KB.
 * @param viewController The view controller to display the ad from. If @c nil, will be inferred from the key window's root view controller.
 */
- (void)showAdForPlacement:(nullable NSString *)placement customData:(nullable NSString *)customData viewController:(nullable UIViewController *)viewController;

/**
 * The ad unit identifier this @c MARewardedAd was initialized with and is loading ads for.
 */
@property (nonatomic, copy, readonly) NSString *adUnitIdentifier;

/**
 * Whether or not this ad is ready to be shown.
 */
@property (nonatomic, assign, readonly, getter=isReady) BOOL ready;

/**
 * Set an extra key/value parameter for the ad.
 *
 * @param key   Parameter key.
 * @param value Parameter value.
 */
- (void)setExtraParameterForKey:(NSString *)key value:(nullable NSString *)value;

/**
 * Set a local extra parameter to pass to the adapter instances. Will not be available in the @code -[MAAdapter initializeWithParameters:withCompletionHandler:] @endcode method.
 *
 * @param key   Parameter key. Must not be null.
 * @param value Parameter value. May be null.
 */
- (void)setLocalExtraParameterForKey:(NSString *)key value:(nullable id)value;

@end

NS_ASSUME_NONNULL_END

#endif /* OMMaxRewardedVideoClass_h */
