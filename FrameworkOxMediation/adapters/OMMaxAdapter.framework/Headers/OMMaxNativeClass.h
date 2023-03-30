//
//  OMMaxNativeClass.h
//  OMMaxAdapter
//
//  Created by 耿志向 on 2022/11/14.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#ifndef OMMaxNativeClass_h
#define OMMaxNativeClass_h

#import <UIKit/UIKit.h>

@class MANativeAdView;
@class MAError;
@class MAAd;
@class ALSdk;
@class MANativeAdViewBinder;
@class MANativeAd;
@class MAAdFormat;
@class MANativeAdImage;

@protocol MAAdRevenueDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * This protocol defines a listener to be notified about native ad events.
 */
@protocol MANativeAdDelegate<NSObject>

/**
 * The SDK invokes this method when a new native ad has been loaded.
 *
 * @param nativeAdView The native ad view that the SDK successfully loaded.
 *                     May be @c nil if a manual native ad is loaded without a view.
 *                     You can create and render the native ad view using @code -[MANativeAdLoader renderNativeAdView:withAd:] @endcode.
 * @param ad  The ad that was loaded.
 */
- (void)didLoadNativeAd:(nullable MANativeAdView *)nativeAdView forAd:(MAAd *)ad;

/**
 * The SDK invokes this method when a native ad could not be retrieved.
 *
 * <b>Common error codes:</b><table>
 * <tr><td>204</td><td>no ad is available</td></tr>
 * <tr><td>5xx</td><td>internal server error</td></tr>
 * <tr><td>negative number</td><td>internal errors</td></tr></table>
 *
 * @param adUnitIdentifier  The ad unit ID that the SDK failed to load an ad for.
 * @param error                          An object that encapsulates the failure info.
 */
- (void)didFailToLoadNativeAdForAdUnitIdentifier:(NSString *)adUnitIdentifier withError:(MAError *)error;

/**
 * The SDK invokes this method when the native ad is clicked.
 *
 * The SDK invokes this method on the main UI thread.
 *
 * @param ad  The ad that was clicked.
 */
- (void)didClickNativeAd:(MAAd *)ad;

@end


/**
 * This class represents a loader for native ads.
 */
@interface MANativeAdLoader : NSObject

/**
 * Creates a new MAX native ad loader.
 *
 * @param adUnitIdentifier Ad unit ID to load ads for.
 */
- (instancetype)initWithAdUnitIdentifier:(NSString *)adUnitIdentifier;

/**
 * Creates a new MAX native ad loader.
 *
 * @param adUnitIdentifier Ad unit ID to load ads for.
 * @param sdk              SDK to use. You can obtain an instance of the SDK by calling @code +[ALSdk shared] @endcode.
 */
- (instancetype)initWithAdUnitIdentifier:(NSString *)adUnitIdentifier sdk:(ALSdk *)sdk;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * A delegate that will be notified about native ad events.
 */
@property (nonatomic, weak, nullable) id<MANativeAdDelegate> nativeAdDelegate;

/**
 * A delegate that will be notified about ad revenue events.
 */
@property (nonatomic, weak, nullable) id<MAAdRevenueDelegate> revenueDelegate;

/**
 * Load a new MAX native ad. Set @code [MANativeAdLoader nativeAdDelegate] @endcode to assign a delegate that should be notified about ad load state.
 */
- (void)loadAd;

/**
 * Load a new MAX native ad into the given native ad view. Set @code [MANativeAdLoader nativeAdDelegate] @endcode to assign a delegate that should be notified about ad load state.
 *
 * @param adView a @c MANativeAdView into which the loaded native ad will be rendered.
 */
- (void)loadAdIntoAdView:(nullable MANativeAdView *)adView;

/**
 * Renders the given ad into the given ad view.
 *
 * Note: Make sure to only render the ad separately if the native ad view returned in our @code -[MANativeAdDelegate didLoadNativeAd:forAd:] @endcode is @c nil.
 *
 * @param adView The ad view into which to render the native ad.
 * @param ad     The ad to be rendered.
 *
 * @return @c YES if the ad view was rendered successfully.
 */
- (BOOL)renderNativeAdView:(MANativeAdView *)adView withAd:(MAAd *)ad;

/**
 * The placement name that you assign when you integrate each ad format, for granular reporting in ad events (e.g. "Rewarded_Store", "Rewarded_LevelEnd").
 */
@property (nonatomic, copy, nullable) NSString *placement;

/**
 * The ad unit identifier this @c MANativeAdLoader was initialized with and is loading ads for.
 */
@property (nonatomic, copy, readonly) NSString *adUnitIdentifier;

/**
 * Destroy the native ad and fully remove it from memory.
 */
- (void)destroyAd:(MAAd *)nativeAd;

/**
 * Sets an extra key/value parameter for the ad.
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

/**
 * Base view class containing native ad templates for banners, leaders, and mrecs.
 *
 *  NOTE: The IBOutlets binding doesn't work in interface builder once the SDK is distributed as xcframeworks. Use the -[MANativeAdView bindViewsWithAdViewBinder:] to bind the native ad views.
 *  Alternatively, you can manually import this header file into your project to use interface builder outlets to bind the views.
 */
@interface MANativeAdView : UIView

/**
 * The native ad title label.
 */
@property (nonatomic, weak) IBOutlet UILabel *titleLabel;

/**
 * The native ad advertiser label.
 */
@property (nonatomic, weak) IBOutlet UILabel *advertiserLabel;

/**
 * The native ad body label.
 */
@property (nonatomic, weak) IBOutlet UILabel *bodyLabel;

/**
 * The native ad icon ImageView.
 */
@property (nonatomic, weak) IBOutlet UIImageView *iconImageView;

/**
 * The native ad icon view.
 */
@property (nonatomic, weak) IBOutlet UIView *iconContentView __deprecated_msg("iconContentView is deprecated and will be removed in the future. Use iconImageView instead.");

/**
 * The native ad options view.
 */
@property (nonatomic, weak) IBOutlet UIView *optionsContentView;

/**
 * The native ad media view for holding an arbitrary content view provided by the 3rd-party SDK.
 */
@property (nonatomic, weak) IBOutlet UIView *mediaContentView;

/**
 * The native ad CTA button.
 */
@property (nonatomic, weak, nullable) IBOutlet UIButton *callToActionButton;

/**
 * Binds the native asset ad views to this native ad using view tags.
 */
- (void)bindViewsWithAdViewBinder:(MANativeAdViewBinder *)adViewBinder;

+ (instancetype)nativeAdViewFromAd:(MANativeAd *)ad;
+ (instancetype)nativeAdViewFromAd:(nullable MANativeAd *)ad withTemplate:(nullable NSString *)templateType;

@end


@class MANativeAdBuilder;
@class MANativeAdImage;

typedef void (^MANativeAdBuilderBlock) (MANativeAdBuilder *builder);

@interface MANativeAdBuilder : NSObject

@property (nonatomic, copy,   nullable) NSString *title;
@property (nonatomic, copy,   nullable) NSString *advertiser;
@property (nonatomic, copy,   nullable) NSString *body;
@property (nonatomic, copy,   nullable) NSString *callToAction;
@property (nonatomic, strong, nullable) MANativeAdImage *icon;
@property (nonatomic, strong, nullable) MANativeAdImage *mainImage;
@property (nonatomic, strong, nullable) UIView *iconView;
@property (nonatomic, strong, nullable) UIView *optionsView;
@property (nonatomic, strong, nullable) UIView *mediaView;
@property (nonatomic, assign) CGFloat mediaContentAspectRatio;

@end

@interface MANativeAdImage : NSObject

/**
 * The native ad image.
 */
@property (nonatomic, strong, readonly, nullable) UIImage *image;

/**
 * The native ad image URL.
 */
@property (nonatomic, copy, readonly, nullable) NSURL *URL;

- (instancetype)initWithImage:(UIImage *)image;
- (instancetype)initWithURL:(NSURL *)URL;
- (instancetype)init NS_UNAVAILABLE;

@end

@interface MANativeAd : NSObject

/**
 * The native ad format.
 */
@property (nonatomic, weak, readonly) MAAdFormat *format;

/**
 * The native ad title text.
 */
@property (nonatomic, copy, readonly, nullable) NSString *title;

/**
 * The native ad advertiser text.
 */
@property (nonatomic, copy, readonly, nullable) NSString *advertiser;

/**
 * The native ad body text.
 */
@property (nonatomic, copy, readonly, nullable) NSString *body;

/**
 * The native ad CTA button text.
 */
@property (nonatomic, copy, readonly, nullable) NSString *callToAction;

/**
 * The native ad icon image.
 */
@property (nonatomic, strong, readonly, nullable) MANativeAdImage *icon;

/**
 * The native ad icon image view.
 * Note: This is only used for banners using native APIs. Native ads must provide a `MANativeAdImage` instead.
 */
@property (nonatomic, strong, readonly, nullable) UIView *iconView;

/**
 * The native ad options view.
 */
@property (nonatomic, strong, readonly, nullable) UIView *optionsView;

/**
 * The native ad media view.
 */
@property (nonatomic, strong, readonly, nullable) UIView *mediaView;

/**
 * The native ad main image (cover image). May or may not be a locally cached file:// resource file.
 *
 * Please make sure you continue to render your native ad using @c MANativeAdLoader so impression tracking is not affected.
 */
@property (nonatomic, strong, readonly, nullable) MANativeAdImage *mainImage;

/**
 * The aspect ratio for the media view if provided by the network. Otherwise returns 0.0f.
 */
@property (nonatomic, assign, readonly) CGFloat mediaContentAspectRatio;

/**
 * For internal use only.
 */
- (void)performClick;

/**
 * This method is called before the ad view is returned to the publisher.
 * The adapters should override this method to register the rendered native ad view and make sure that the view is interactable.
 *
 * @param nativeAdView a rendered native ad view.
 */
- (void)prepareViewForInteraction:(MANativeAdView *)nativeAdView;

- (instancetype)initWithFormat:(MAAdFormat *)format builderBlock:(NS_NOESCAPE MANativeAdBuilderBlock)builderBlock;
- (instancetype)init NS_UNAVAILABLE;

@end

@class MANativeAdViewBinderBuilder;

typedef void (^MANativeAdViewBinderBuilderBlock) (MANativeAdViewBinderBuilder *builder);

@interface MANativeAdViewBinderBuilder : NSObject

@property (nonatomic, assign) NSInteger titleLabelTag;
@property (nonatomic, assign) NSInteger advertiserLabelTag;
@property (nonatomic, assign) NSInteger bodyLabelTag;
@property (nonatomic, assign) NSInteger iconImageViewTag;
@property (nonatomic, assign) NSInteger optionsContentViewTag;
@property (nonatomic, assign) NSInteger mediaContentViewTag;
@property (nonatomic, assign) NSInteger callToActionButtonTag;

@end

@interface MANativeAdViewBinder : NSObject

/**
 * A non-zero tag for the title label view to be rendered. The maximum length will be 50 characters.
 */
@property (nonatomic, assign, readonly) NSInteger titleLabelTag;

/**
 * A non-zero tag for advertiser label view to be rendered. The maximum length will be 25 characters.
 */
@property (nonatomic, assign, readonly) NSInteger advertiserLabelTag;

/**
 * A non-zero tag for body label view to be rendered. The maximum length will be 150 characters.
 */
@property (nonatomic, assign, readonly) NSInteger bodyLabelTag;

/**
 * A non-zero tag for icon image view to be rendered.
 */
@property (nonatomic, assign, readonly) NSInteger iconImageViewTag;

/**
 * A non-zero tag for options content view to be rendered.
 */
@property (nonatomic, assign, readonly) NSInteger optionsContentViewTag;

/**
 * A non-zero tag for media content view to be rendered.
 */
@property (nonatomic, assign, readonly) NSInteger mediaContentViewTag;

/**
 * A non-zero tag for call to action button view to be rendered. The maximum length will be 15 characters.
 */
@property (nonatomic, assign, readonly) NSInteger callToActionButtonTag;

/**
 * Instantiates a @c MANativeAdViewBinder from a builder.
 */
- (instancetype)initWithBuilderBlock:(MANativeAdViewBinderBuilderBlock)builder;
- (instancetype)init NS_UNAVAILABLE;

@end



NS_ASSUME_NONNULL_END


#endif /* OMMaxNativeClass_h */
