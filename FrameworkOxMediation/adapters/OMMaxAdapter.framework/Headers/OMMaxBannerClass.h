//
//  OMMaxBannerClass.h
//  OMMaxAdapter
//
//  Created by 耿志向 on 2022/11/13.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#ifndef OMMaxBannerClass_h
#define OMMaxBannerClass_h

#import "OMMaxClass.h"

@class MAAd;
@class MAAdDelegate;
@class MAError;
@class MAAdFormat;

NS_ASSUME_NONNULL_BEGIN
/**
 * This protocol defines a listener to be notified about ad events.
 */
@protocol MAAdDelegate<NSObject>

/**
 * The SDK invokes this method when a new ad has been loaded.
 *
 * @param ad  The ad that was loaded.
 */
- (void)didLoadAd:(MAAd *)ad;

/**
 * The SDK invokes this method when an ad could not be retrieved.
 *
 * <b>Common error codes:</b><table>
 * <tr><td>204</td><td>no ad is available</td></tr>
 * <tr><td>5xx</td><td>internal server error</td></tr>
 * <tr><td>negative number</td><td>internal errors</td></tr></table>
 *
 * @param adUnitIdentifier  The ad unit ID that the SDK failed to load an ad for.
 * @param error                          An object that encapsulates the failure info.
 */
- (void)didFailToLoadAdForAdUnitIdentifier:(NSString *)adUnitIdentifier withError:(MAError *)error;

/**
 * The SDK invokes this method when a full-screen ad is displayed.
 *
 * The SDK invokes this method on the main UI thread.
 *
 * @warning This method is deprecated for MRECs. It will only be called for full-screen ads.
 *
 * @param ad  The ad that was displayed.
 */
- (void)didDisplayAd:(MAAd *)ad;

/**
 * The SDK invokes this method when a full-screen ad is hidden.
 *
 * The SDK invokes this method on the main UI thread.
 *
 * @warning This method is deprecated for MRECs. It will only be called for full-screen ads.
 *
 * @param ad  The ad that was hidden.
 */
- (void)didHideAd:(MAAd *)ad;

/**
 * The SDK invokes this method when the ad is clicked.
 *
 * The SDK invokes this method on the main UI thread.
 *
 * @param ad  The ad that was clicked.
 */
- (void)didClickAd:(MAAd *)ad;

/**
 * The SDK invokes this method when the ad failed to display.
 *
 * The SDK invokes this method on the main UI thread.
 *
 * @param ad       The ad that the SDK failed to display for.
 * @param error An object that encapsulates the failure info.
 */
- (void)didFailToDisplayAd:(MAAd *)ad withError:(MAError *)error;

@end

@protocol MAAdViewAdDelegate<MAAdDelegate>

/**
 * The SDK invokes this method when the @c MAAdView has expanded to the full screen.
 *
 * @param ad An ad for which the ad view expanded.
 */
- (void)didExpandAd:(MAAd *)ad;

/**
 * The SDK invokes this method when the @c MAAdView has collapsed back to its original size.
 *
 * @param ad An ad for which the ad view collapsed.
 */
- (void)didCollapseAd:(MAAd *)ad;

@end

@protocol MAAdRevenueDelegate<NSObject>

/**
 * The SDK invokes this callback when it detects a revenue event for an ad.
 *
 * The SDK invokes this callback on the UI thread.
 *
 * @param ad The ad for which the revenue event was detected.
 */
- (void)didPayRevenueForAd:(MAAd *)ad;

@end

@protocol MAAdReviewDelegate<NSObject>

/**
 * The SDK invokes this callback when the Ad Review SDK successfully generates a creative id.
 *
 * The SDK invokes this callback on the UI thread.
 *
 * @param creativeIdentifier The Ad Review creative id tied to the ad, if any. You can report creative issues to our Ad review team using this id.
 * @param ad                                     The ad for which the ad review event was detected.
 */
- (void)didGenerateCreativeIdentifier:(NSString *)creativeIdentifier forAd:(MAAd *)ad;

@end

@interface MAAdView : UIView

/**
 * Creates a new ad view for a given ad unit ID.
 *
 * @param adUnitIdentifier Ad unit ID to load ads for.
 */
- (instancetype)initWithAdUnitIdentifier:(NSString *)adUnitIdentifier;

/**
 * Creates a new ad view for a given ad unit ID.
 *
 * @param adUnitIdentifier Ad unit ID to load ads for.
 * @param sdk              SDK to use. You can obtain an instance of the SDK by calling @code +[ALSdk shared] @endcode.
 */
- (instancetype)initWithAdUnitIdentifier:(NSString *)adUnitIdentifier sdk:(ALSdk *)sdk;

/**
 * Creates a new ad view for a given ad unit ID and ad format.
 *
 * @param adUnitIdentifier Ad unit ID to load ads for.
 * @param adFormat         Ad format to load ads for.
 */
- (instancetype)initWithAdUnitIdentifier:(NSString *)adUnitIdentifier adFormat:(MAAdFormat *)adFormat;

/**
 * Create a new ad view for a given ad unit ID, ad format, and SDK.
 *
 * @param adUnitIdentifier Ad unit id to load ads for.
 * @param adFormat         Ad format to load ads for.
 * @param sdk              SDK to use. You can obtain an instance of the SDK by calling @code +[ALSdk shared] @endcode.
 */
- (instancetype)initWithAdUnitIdentifier:(NSString *)adUnitIdentifier adFormat:(MAAdFormat *)adFormat sdk:(ALSdk *)sdk;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * A delegate that will be notified about ad events.
 */
@property (nonatomic, weak, nullable) IBOutlet id<MAAdViewAdDelegate> delegate;

/**
 * A delegate that will be notified about ad revenue events.
 */
@property (nonatomic, weak, nullable) IBOutlet id<MAAdRevenueDelegate> revenueDelegate;

/**
 * A delegate that will be notified about Ad Review events.
 */
@property (nonatomic, weak, nullable) IBOutlet id<MAAdReviewDelegate> adReviewDelegate;

/**
 * Loads the ad for the current ad view. Set @code [MAAdView delegate] @endcode to assign a delegate that should be notified about ad load state.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/banners#loading-a-banner">MAX Integration Guide ⇒ iOS ⇒ Banners ⇒ Loading a Banner</a>
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/mrecs#loading-an-mrec">MAX Integration Guide ⇒ iOS ⇒ MRECs ⇒ Loading an MREC</a>
 */
- (void)loadAd;

/**
 * Starts or resumes auto-refreshing of the banner.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/banners#showing-a-banner">MAX Integration Guide ⇒ iOS ⇒ Banners ⇒ Showing a Banner</a>
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/mrecs#hiding-and-showing-an-mrec">MAX Integration Guide ⇒ iOS ⇒ MRECs ⇒ Hiding and Showing an MREC</a>
 */
- (void)startAutoRefresh;

/**
 * Pauses auto-refreshing of the banner.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/banners#hiding-a-banner">MAX Integration Guide ⇒ iOS ⇒ Banners ⇒ Hiding a Banner</a>
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/mrecs#hiding-and-showing-an-mrec">MAX Integration Guide ⇒ iOS ⇒ MRECs ⇒ Hiding and Showing an MREC</a>
 */
- (void)stopAutoRefresh;

/**
 * The placement name that you assign when you integrate each ad format, for granular reporting in ad events (e.g. "Rewarded_Store", "Rewarded_LevelEnd").
 */
@property (nonatomic, copy, nullable) NSString *placement;

/**
 * The ad unit identifier this @c MAAdView was initialized with and is loading ads for.
 */
@property (nonatomic, copy, readonly) NSString *adUnitIdentifier;

/**
 * The format of the ad view.
 */
@property (nonatomic, weak, readonly) MAAdFormat *adFormat;

/**
 * Sets an extra parameter key/value pair for the ad.
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

/**
 * The custom data to tie the showing ad to, for ILRD and rewarded postbacks via the @c {CUSTOM_DATA}  macro. Maximum size is 8KB.
 */
@property (nonatomic, copy, nullable) NSString *customData;

@end

NS_ASSUME_NONNULL_END

#endif /* OMMaxBannerClass_h */
