// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#ifndef OMAppLovinClass_h
#define OMAppLovinClass_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@class ALAd;
@class ALAdService;
@class ALSdkConfiguration;
@class ALUserSegment;
@class ALTargetingData;
@class ALEventService;
@class MAMediatedNetworkInfo;
@class ALVariableService;
@class MAAdWaterfallInfo;
@class MAAdFormat;
@class MANativeAd;

/**
 * This enum contains various error codes that the SDK can return when a MAX ad fails to load or display.
 */
typedef NS_ENUM(NSInteger, MAErrorCode)
{
    /**
     * This error code represents an error that could not be categorized into one of the other defined errors. See the message field in the error object for more details.
     */
    MAErrorCodeUnspecified = -1,
    
    /**
     * This error code indicates that MAX returned no eligible ads from any mediated networks for this app/device.
     */
    MAErrorCodeNoFill = 204,
    
    /**
     * This error code indicates that MAX returned eligible ads from mediated networks, but all ads failed to load. See the adLoadFailureInfo field in the error object for more details.
     */
    MAErrorCodeAdLoadFailed = -5001,
    
    /**
     * This error code indicates that the ad request failed due to a generic network error. See the message field in the error object for more details.
     */
    MAErrorCodeNetworkError = -1000,
    
    /**
     * This error code indicates that the ad request timed out due to a slow internet connection.
     */
    MAErrorCodeNetworkTimeout = -1001,
    
    /**
     * This error code indicates that the ad request failed because the device is not connected to the internet.
     */
    MAErrorCodeNoNetwork = -1009,
    
    /**
     * This error code indicates that you attempted to show a fullscreen ad while another fullscreen ad is still showing.
     */
    MAErrorCodeFullscreenAdAlreadyShowing = -23,
    
    /**
     * This error code indicates you are attempting to show a fullscreen ad before the one has been loaded.
     */
    MAErrorCodeFullscreenAdNotReady = -24
};

/**
 * This class encapsulates various data for MAX load and display errors.
 */
@interface MAError : NSObject

/**
 * The error code for the error. Will be one of the codes listed under the @c MAErrorCode enum.
 */
@property (nonatomic, assign, readonly) MAErrorCode code;

/**
 * The error message for the error.
 */
@property (nonatomic, copy, readonly) NSString *message;

/**
 * The mediated network's error code for the error. Available for errors returned in @c -[MAAdDelegate didFailToDisplayAd:withError:] only.
 */
@property (nonatomic, assign, readonly) NSInteger mediatedNetworkErrorCode;

/**
 * The mediated network's error message for the error. Defaults to an empty string. Available for errors returned in @c -[MAAdDelegate didFailToDisplayAd:withError:] only.
 */
@property (nonatomic, copy, readonly) NSString *mediatedNetworkErrorMessage;

/**
 * The underlying waterfall of ad responses.
 */
@property (nonatomic, strong, readonly, nullable) MAAdWaterfallInfo *waterfall;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

@interface MAError(ALDeprecated)
@property (nonatomic, assign, readonly) NSInteger errorCode __deprecated_msg("This property is deprecated and removed in a future SDK version. Please use `-[MAError code]` instead.");
@property (nonatomic, copy, readonly) NSString *errorMessage __deprecated_msg("This property is deprecated and removed in a future SDK version. Please use `-[MAError message]` instead.");
@property (nonatomic, copy, readonly, nullable) NSString *adLoadFailureInfo __deprecated_msg("The ad load failure info string is deprecated and removed in a future SDK version. Please use `-[MAError waterfall]` instead.");
@end


/**
 * This class represents an ad that has been served by AppLovin MAX.
 */
@interface MAAd : NSObject

/**
 * The format of this ad.
 */
@property (nonatomic, strong, readonly) MAAdFormat *format;

/**
 * The size of the AdView format ad, or @c CGSizeZero otherwise.
 */
@property (nonatomic, assign, readonly) CGSize size;

/**
 * The ad unit ID for which this ad was loaded.
 */
@property (nonatomic, copy, readonly) NSString *adUnitIdentifier;

/**
 * The ad network from which this ad was loaded.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/testing-networks/creative-debugger#network-name">MAX Integration Guide ⇒ iOS ⇒ Testing Networks ⇒ Creative Debugger ⇒ Network Name</a>
 */
@property (nonatomic, copy, readonly) NSString *networkName;

/**
 * The ad network placement for which this ad was loaded.
 */
@property (nonatomic, copy, readonly) NSString *networkPlacement;

/**
 * The creative id tied to the ad, if any. You can report creative issues to the corresponding ad network using this id.
 *
 * It may not be available until @c -[MAAdDelegate didDisplayAd:] is called.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/testing-networks/creative-debugger#creative-id">MAX Integration Guide ⇒ iOS ⇒ Testing Networks ⇒ Creative Debugger ⇒ Creative ID</a>
 *
 * @since 6.15.0
 */
@property (nonatomic, copy, readonly, nullable) NSString *creativeIdentifier;

/**
 * The Ad Review creative id tied to the ad, if any. You can report creative issues to our Ad review team using this id.
 *
 * It may not be available until @c -[MAAdDelegate didDisplayAd:] is called.
 *
 * @since 11.3.0
 */
@property (nonatomic, copy, readonly, nullable) NSString *adReviewCreativeIdentifier;

/**
 * The ad’s revenue amount, or 0 if no revenue amount exists.
 */
@property (nonatomic, assign, readonly) double revenue;

/**
 * The precision of the revenue value for this ad.
 *
 * Possible values are:
 * - "publisher_defined" - If the revenue is the price assigned to the line item by the publisher.
 * - "exact" - If the revenue is the resulting price of a real-time auction.
 * - "estimated" - If the revenue is the price obtained by auto-CPM.
 * - "undefined" - If we do not have permission from the ad network to share impression-level data.
 */
@property (nonatomic, copy, readonly) NSString *revenuePrecision;

/**
 * The placement name that you assign when you integrate each ad format, for granular reporting in postbacks (e.g. "Rewarded_Store", "Rewarded_LevelEnd").
 */
@property (atomic, copy, readonly, nullable) NSString *placement;

/**
 * The underlying waterfall of ad responses.
 */
@property (nonatomic, strong, readonly) MAAdWaterfallInfo *waterfall;

/**
 * For Native ads only. Get an instance of the @c MANativeAd containing the assets used to render the native ad view.
 */
@property (nonatomic, strong, readonly, nullable) MANativeAd *nativeAd;

/**
 * The DSP network that provided the loaded ad when the ad is served through AppLovin Exchange.
 */
@property (nonatomic, copy, readonly, nullable) NSString *DSPName;

/**
 * The DSP id network that provided the loaded ad when the ad is served through AppLovin Exchange.
 */
@property (nonatomic, copy, readonly, nullable) NSString *DSPIdentifier;

/**
 * Gets the ad value for a given key.
 *
 * @param key The key for the value you want to retrieve.
 *
 * @return The ad value corresponding to @c key, or @c nil if no value for that key exists.
 */
- (nullable NSString *)adValueForKey:(NSString *)key;

/**
 * Gets the ad value for a given key.
 *
 * @param key                     The key for the value you want to retrieve.
 * @param defaultValue The default value to return if the value for @c key does not exist or is @c nil.
 *
 * @return The ad value corresponding to @c key, or the default value if no value for that key exists.
 */
- (nullable NSString *)adValueForKey:(NSString *)key defaultValue:(nullable NSString *)defaultValue;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

@interface ALSdkSettings : NSObject

@property (nonatomic, assign) BOOL isVerboseLogging;

@end

@protocol ALAdLoadDelegate <NSObject>

/**
 * This method is invoked when an ad is loaded by the AdService.
 *
 * This method is invoked on the main UI thread.
 *
 * @param adService AdService which loaded the ad. Will not be nil.
 * @param ad        Ad that was loaded. Will not be nil.
 */
- (void)adService:(ALAdService *)adService didLoadAd:(ALAd *)ad;

/**
 * This method is invoked when an ad load fails.
 *
 * This method is invoked on the main UI thread.
 *
 * @param adService AdService which failed to load an ad. Will not be nil.
 * @param code      An error code corresponding with a constant defined in <code>ALErrorCodes.h</code>.
 */
- (void)adService:(ALAdService *)adService didFailToLoadAdWithError:(int)code;

@end

/**
 * This protocol defines a listener for ad display events.
 */
@protocol ALAdDisplayDelegate <NSObject>

/**
 * This method is invoked when the ad is displayed in the view.
 *
 * This method is invoked on the main UI thread.
 *
 * @param ad     Ad that was just displayed. Will not be nil.
 * @param view   Ad view in which the ad was displayed. Will not be nil.
 */
- (void)ad:(ALAd *)ad wasDisplayedIn:(UIView *)view;

/**
 * This method is invoked when the ad is hidden from in the view.
 * This occurs when the user "X's" out of an interstitial.
 *
 * This method is invoked on the main UI thread.
 *
 * @param ad     Ad that was just hidden. Will not be nil.
 * @param view   Ad view in which the ad was hidden. Will not be nil.
 */
- (void)ad:(ALAd *)ad wasHiddenIn:(UIView *)view;

/**
 * This method is invoked when the ad is clicked from in the view.
 *
 * This method is invoked on the main UI thread.
 *
 * @param ad     Ad that was just clicked. Will not be nil.
 * @param view   Ad view in which the ad was hidden. Will not be nil.
 */
- (void)ad:(ALAd *)ad wasClickedIn:(UIView *)view;

@end


@protocol ALAdVideoPlaybackDelegate <NSObject>

/**
 * This method is invoked when a video starts playing in an ad.
 *
 * This method is invoked on the main UI thread.
 *
 * @param ad Ad in which video playback began.
 */
- (void)videoPlaybackBeganInAd:(ALAd *)ad;

/**
 * This method is invoked when a video stops playing in an ad.
 *
 * This method is invoked on the main UI thread.
 *
 * @param ad                Ad in which video playback ended.
 * @param percentPlayed     How much of the video was watched, as a percent.
 * @param wasFullyWatched   Whether or not the video was watched to, or very near to, completion.
 */
- (void)videoPlaybackEndedInAd:(ALAd *)ad atPlaybackPercent:(NSNumber *)percentPlayed fullyWatched:(BOOL)wasFullyWatched;

@end

@interface ALPrivacySettings : NSObject

/**
* Set whether or not user has provided consent for information sharing with AppLovin.
*
* @param hasUserConsent 'YES' if the user has provided consent for information sharing with AppLovin. 'false' by default.
*/
+ (void)setHasUserConsent:(BOOL)hasUserConsent;

/**
 * Set whether or not user has opted out of the sale of their personal information.
 *
 * @param doNotSell 'YES' if the user has opted out of the sale of their personal information.
 */
+ (void)setDoNotSell:(BOOL)doNotSell;

+ (void)setIsAgeRestrictedUser:(BOOL)isAgeRestrictedUser;

@end

/**
 * This is a base class for the AppLovin iOS SDK.
 */
@interface ALSdk : NSObject


#pragma mark - High Level SDK Properties

/**
 * The current version of the SDK. The value is in the format of "<var>Major</var>.<var>Minor</var>.<var>Revision</var>".
 */
@property (class, nonatomic, copy, readonly) NSString *version;

/**
 * The current version of the SDK in numeric format.
 */
@property (class, nonatomic, assign, readonly) NSUInteger versionCode;

/**
 * This SDK’s SDK key.
 */
@property (nonatomic, copy, readonly) NSString *sdkKey;

/**
 * This SDK’s SDK settings.
 */
@property (nonatomic, strong, readonly) ALSdkSettings *settings;

/**
 * The SDK configuration object that the SDK creates when you initialize the SDK.
 */
@property (nonatomic, strong, readonly) ALSdkConfiguration *configuration;

/**
 * Sets the plugin version for the mediation adapter or plugin.
 *
 * @param pluginVersion Some descriptive string that identifies the plugin.
 */
- (void)setPluginVersion:(NSString *)pluginVersion;

/**
 * An identifier for the current user. This identifier will be tied to SDK events and AppLovin’s optional S2S postbacks.
 *
 * If you use reward validation, you can optionally set an identifier that AppLovin will include with its currency validation postbacks (for example, a username
 * or email address). AppLovin will include this in the postback when AppLovin pings your currency endpoint from our server.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/s2s-rewarded-callback-api#setting-an-internal-user-id">MAX Integration Guide ⇒ MAX S2S Rewarded Callback API ⇒ Setting an Internal User ID</a>
 */
@property (nonatomic, copy, nullable) NSString *userIdentifier;

/**
 * A user segment allows AppLovin to serve ads by using custom-defined rules that are based on which segment the user is in. The user segment is a custom string
 * of 32 alphanumeric characters or less.
 */
@property (nonatomic, strong, readonly) ALUserSegment *userSegment;

/**
 * A class which allows you to send any demographic or interest-based targeting data.
 */
@property (nonatomic, strong, readonly) ALTargetingData *targetingData;

#pragma mark - SDK Services

/**
 * The ad service, which loads and displays ads from AppLovin servers.
 */
@property (nonatomic, strong, readonly) ALAdService *adService;

/**
 * The AppLovin event service, which tracks post-install user events.
 *
 * @return Event service. Guaranteed not to be @c NULL.
 */
@property (nonatomic, strong, readonly) ALEventService *eventService;

/**
 * Get an instance of the AppLovin variable service. This service is used to perform various A/B tests that you have set up on your AppLovin dashboard on your
 * users.
 *
 * @return Variable service. Guaranteed not to be @c NULL.
 */
@property (nonatomic, strong, readonly) ALVariableService *variableService;

#pragma mark - MAX

/**
 * The mediation provider. Set this either by using one of the provided strings in ALMediationProvider.h, or your own string if you do not find an
 * applicable one there.
 */
@property (nonatomic, copy, nullable) NSString *mediationProvider;

/**
 * The list of available mediation networks, as an array of @c MAMediatedNetworkInfo objects.
 */
@property (nonatomic, strong, readonly) NSArray<MAMediatedNetworkInfo *> *availableMediatedNetworks;

/**
 * Present the mediation debugger UI.
 * This debugger tool provides the status of your integration for each third-party ad network.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/testing-networks/mediation-debugger">MAX Integration Guide ⇒ iOS ⇒ Testing Networks ⇒ Mediation Debugger</a>
 */
- (void)showMediationDebugger;

#pragma mark - SDK Initialization

/**
 * The sort of callback that the SDK calls when it finishes initializing.
 */
typedef void (^ALSdkInitializationCompletionHandler)(ALSdkConfiguration *configuration);

/**
 * Whether the SDK has fully been initialized without errors and the completion callback called.
 */
@property (nonatomic, assign, readonly, getter=isInitialized) BOOL initialized;

/**
 * Initializes the SDK.
 */
- (void)initializeSdk;

/**
 * Initializes the SDK with a given completion block.
 *
 * The SDK invokes the callback on the main thread.
 *
 * @param completionHandler The callback that the SDK will call when the SDK finishes initializing.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/integration#initialize-the-sdk">MAX Integration Guide ⇒ iOS ⇒ Integration ⇒ Initialize the SDK</a>
 */
- (void)initializeSdkWithCompletionHandler:(nullable ALSdkInitializationCompletionHandler)completionHandler;

/**
 * Initializes the default instance of AppLovin SDK.
 *
 * @warning Make sure your SDK key is set in the application’s @code Info.plist @endcode under the property @c AppLovinSdkKey.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/integration#initialize-the-sdk">MAX Integration Guide ⇒ iOS ⇒ Integration ⇒ Initialize the SDK</a>
 */
+ (void)initializeSdk;

/**
 * Initializes the default instance of AppLovin SDK.
 *
 * @warning Make sure your SDK key is set in the application’s @code Info.plist @endcode under the property @c AppLovinSdkKey.
 *
 * @param completionHandler The callback that the SDK will run on the main queue when the SDK finishes initializing.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/integration#initialize-the-sdk">MAX Integration Guide ⇒ iOS ⇒ Integration ⇒ Initialize the SDK</a>
 */
+ (void)initializeSdkWithCompletionHandler:(nullable ALSdkInitializationCompletionHandler)completionHandler;

/**
 * Gets a shared instance of AppLovin SDK.
 *
 * @warning Make sure your SDK key is set in the application’s @code Info.plist @endcode under the property @c AppLovinSdkKey.
 *
 * @return The shared instance of AppLovin’s SDK, or @c nil (indicating an error) if the SDK key is not set in the application’s @code Info.plist @endcode.
 */
+ (nullable ALSdk *)shared;

/**
 * Gets a shared instance of AppLovin SDK.
 *
 * @warning Make sure your SDK key is set in the application’s @code Info.plist @endcode under the property @c AppLovinSdkKey.
 *
 * @param settings An SDK settings object.
 *
 * @return The shared instance of AppLovin’s SDK, or @c nil (indicating an error) if the SDK key is not set in the application’s @code Info.plist @endcode.
 */
+ (nullable ALSdk *)sharedWithSettings:(ALSdkSettings *)settings;

/**
 * Gets an instance of AppLovin SDK by using an SDK key.
 *
 * @param key SDK key to use for the instance of the AppLovin SDK.
 *
 * @return An instance of AppLovin’s SDK, or @c nil (indicating an error) if @c key is not set.
 */
+ (nullable ALSdk *)sharedWithKey:(NSString *)key;

/**
 * Gets an instance of AppLovin SDK by using an SDK key and providing SDK settings.
 *
 * @param key       SDK key to use for the instance of the AppLovin SDK.
 * @param settings  An SDK settings object.
 *
 * @return An instance of AppLovin’s SDK, or @c nil (indicating an error) if @c key is not set.
 */
+ (nullable ALSdk *)sharedWithKey:(NSString *)key settings:(ALSdkSettings *)settings;

- (instancetype)init __attribute__((unavailable("Use +[ALSdk shared], +[ALSdk sharedWithKey:], or +[ALSdk sharedWithKey:settings:].")));
+ (instancetype)new NS_UNAVAILABLE;

@end


NS_ASSUME_NONNULL_END

#endif /* OMAppLovinClass_h */
