//
//  OxCustomUnityAdsAdapter.m
//  AppLovinSDK
//
//  Created by Santosh Bagadi on 9/2/18.
//  Copyright © 2022 AppLovin Corporation. All rights reserved.
//

#import "OxCustomUnityAdsAdapter.h"
#import <UnityAds/UnityAds.h>

#define ADAPTER_VERSION @"4.9.2.0"

@interface OxCustomUnityAdsInitializationDelegate : NSObject <UnityAdsInitializationDelegate>
@property (nonatomic, weak) OxCustomUnityAdsAdapter *parentAdapter;
@property (nonatomic, copy, nullable) void(^completionHandler)(MAAdapterInitializationStatus, NSString *_Nullable);
- (instancetype)initWithParentAdapter:(OxCustomUnityAdsAdapter *)parentAdapter andCompletionHandler:(void (^)(MAAdapterInitializationStatus, NSString *_Nullable))completionHandler;
@end

@interface OxCustomUnityAdsInterstitialDelegate : NSObject <UnityAdsLoadDelegate, UnityAdsShowDelegate>
@property (nonatomic,   weak) OxCustomUnityAdsAdapter *parentAdapter;
@property (nonatomic, strong) id<MAInterstitialAdapterDelegate> delegate;
- (instancetype)initWithParentAdapter:(OxCustomUnityAdsAdapter *)parentAdapter andNotify:(id<MAInterstitialAdapterDelegate>)delegate;
@end

@interface OxCustomUnityAdsRewardedDelegate : NSObject <UnityAdsLoadDelegate, UnityAdsShowDelegate>
@property (nonatomic,   weak) OxCustomUnityAdsAdapter *parentAdapter;
@property (nonatomic, strong) id<MARewardedAdapterDelegate> delegate;
- (instancetype)initWithParentAdapter:(OxCustomUnityAdsAdapter *)parentAdapter andNotify:(id<MARewardedAdapterDelegate>)delegate;
@end

@interface OxCustomUnityAdsAdViewDelegate : NSObject <UADSBannerViewDelegate>
@property (nonatomic,   weak) OxCustomUnityAdsAdapter *parentAdapter;
@property (nonatomic, strong) id<MAAdViewAdapterDelegate> delegate;
- (instancetype)initWithParentAdapter:(OxCustomUnityAdsAdapter *)parentAdapter andNotify:(id<MAAdViewAdapterDelegate>)delegate;
@end

@interface OxCustomUnityAdsAdapter ()
@property (nonatomic, copy) NSString *biddingAdIdentifier;
@property (nonatomic, strong) UADSBannerView *bannerAdView;
@property (nonatomic, strong) OxCustomUnityAdsInterstitialDelegate *interstitialDelegate;
@property (nonatomic, strong) OxCustomUnityAdsRewardedDelegate *rewardedDelegate;
@property (nonatomic, strong) OxCustomUnityAdsAdViewDelegate *adViewDelegate;
@end

@implementation OxCustomUnityAdsAdapter
static ALAtomicBoolean *OxCustomUnityAdsInitialized;
static MAAdapterInitializationStatus OxCustomUnityAdsInitializationStatus = NSIntegerMin;

+ (void)initialize
{
    [super initialize];
    OxCustomUnityAdsInitialized = [[ALAtomicBoolean alloc] init];
}

#pragma mark - MAAdapter Methods

- (void)initializeWithParameters:(id<MAAdapterInitializationParameters>)parameters completionHandler:(void (^)(MAAdapterInitializationStatus, NSString *_Nullable))completionHandler
{
    [self updatePrivacyConsent: parameters];
    
    if ( [OxCustomUnityAdsInitialized compareAndSet: NO update: YES] )
    {
        NSDictionary<NSString *, id> *serverParameters = parameters.serverParameters;
        NSString *gameId = [serverParameters al_stringForKey: @"app_id"];
        [self log: @"Initializing UnityAds SDK with game id: %@...", gameId];
        
        UADSMediationMetaData *mediationMetaData = [[UADSMediationMetaData alloc] init];
        [mediationMetaData setName: @"MAX"];
        [mediationMetaData setVersion: [ALSdk version]];
        [mediationMetaData set: @"adapter_version" value: ADAPTER_VERSION];
        [mediationMetaData commit];
        
        [UnityAds setDebugMode: [parameters isTesting]];
        
        OxCustomUnityAdsInitializationDelegate *initializationDelegate = [[OxCustomUnityAdsInitializationDelegate alloc] initWithParentAdapter: self andCompletionHandler: completionHandler];
        OxCustomUnityAdsInitializationStatus = MAAdapterInitializationStatusInitializing;
        
        [UnityAds initialize: gameId
                    testMode: [parameters isTesting]
      initializationDelegate: initializationDelegate];
    }
    else
    {
        [self log: @"UnityAds SDK already initialized"];
        completionHandler(OxCustomUnityAdsInitializationStatus, nil);
    }
}

- (NSString *)SDKVersion
{
    return [UnityAds getVersion];
}

- (NSString *)adapterVersion
{
    return ADAPTER_VERSION;
}

- (void)destroy
{
    if ( self.bannerAdView )
    {
        self.bannerAdView.delegate = nil;
        self.bannerAdView = nil;
        self.adViewDelegate.delegate = nil;
        self.adViewDelegate = nil;
    }
    
    self.interstitialDelegate.delegate = nil;
    self.rewardedDelegate.delegate = nil;
    self.interstitialDelegate = nil;
    self.rewardedDelegate = nil;
}

#pragma mark - MASignalProvider Methods

- (void)collectSignalWithParameters:(id<MASignalCollectionParameters>)parameters andNotify:(id<MASignalCollectionDelegate>)delegate
{
    [self log: @"Collecting signal..."];
    
    [self updatePrivacyConsent: parameters];
    
    [UnityAds getToken:^(NSString *signal) {
        [self log: @"Signal collected"];
        [delegate didCollectSignal: signal];
    }];
}

#pragma mark - MAInterstitialAdapter Methods

- (void)loadInterstitialAdForParameters:(id<MAAdapterResponseParameters>)parameters andNotify:(id<MAInterstitialAdapterDelegate>)delegate
{
    NSString *placementIdentifier = parameters.thirdPartyAdPlacementIdentifier;
    [self log: @"Loading %@interstitial ad for placement \"%@\"...", ( [parameters.bidResponse al_isValidString] ? @"bidding " : @"" ), placementIdentifier];
    
    [self updatePrivacyConsent: parameters];
    
    self.interstitialDelegate = [[OxCustomUnityAdsInterstitialDelegate alloc] initWithParentAdapter: self andNotify: delegate];
    
    // Every ad needs a random ID associated with each load and show
    self.biddingAdIdentifier = [NSUUID UUID].UUIDString;
    
    [UnityAds load: placementIdentifier
           options: [self createAdLoadOptionsForParameters: parameters]
      loadDelegate: self.interstitialDelegate];
}

- (void)showInterstitialAdForParameters:(id<MAAdapterResponseParameters>)parameters andNotify:(id<MAInterstitialAdapterDelegate>)delegate
{
    NSString *placementIdentifier = parameters.thirdPartyAdPlacementIdentifier;
    [self log: @"Showing interstitial ad for placement \"%@\"...", placementIdentifier];
    
    // Paranoia check
    if ( !self.interstitialDelegate )
    {
        self.interstitialDelegate = [[OxCustomUnityAdsInterstitialDelegate alloc] initWithParentAdapter: self andNotify: delegate];
    }
    
    UIViewController *presentingViewController;
    if ( ALSdk.versionCode >= 11020199 )
    {
        presentingViewController = parameters.presentingViewController ?: [ALUtils topViewControllerFromKeyWindow];
    }
    else
    {
        presentingViewController = [ALUtils topViewControllerFromKeyWindow];
    }
    
    [UnityAds show: presentingViewController
       placementId: placementIdentifier
           options: [self createAdShowOptions]
      showDelegate: self.interstitialDelegate];
}

#pragma mark - MARewardedAdapter Methods

- (void)loadRewardedAdForParameters:(id<MAAdapterResponseParameters>)parameters andNotify:(id<MARewardedAdapterDelegate>)delegate
{
    NSString *placementIdentifier = parameters.thirdPartyAdPlacementIdentifier;
    [self log: @"Loading %@rewarded ad for placement \"%@\"...", ( [parameters.bidResponse al_isValidString] ? @"bidding " : @"" ), placementIdentifier];
    
    [self updatePrivacyConsent: parameters];
    
    self.rewardedDelegate = [[OxCustomUnityAdsRewardedDelegate alloc] initWithParentAdapter: self andNotify: delegate];
    
    // Every ad needs a random ID associated with each load and show
    self.biddingAdIdentifier = [NSUUID UUID].UUIDString;
    
    [UnityAds load: placementIdentifier
           options: [self createAdLoadOptionsForParameters: parameters]
      loadDelegate: self.rewardedDelegate];
}

- (void)showRewardedAdForParameters:(id<MAAdapterResponseParameters>)parameters andNotify:(id<MARewardedAdapterDelegate>)delegate
{
    NSString *placementIdentifier = parameters.thirdPartyAdPlacementIdentifier;
    [self log: @"Showing rewarded ad for placement \"%@\"...", placementIdentifier];
    
    // Paranoia check
    if ( !self.rewardedDelegate )
    {
        self.rewardedDelegate = [[OxCustomUnityAdsRewardedDelegate alloc] initWithParentAdapter: self andNotify: delegate];
    }
    
    // Configure reward from server.
    [self configureRewardForParameters: parameters];
    
    UIViewController *presentingViewController;
    if ( ALSdk.versionCode >= 11020199 )
    {
        presentingViewController = parameters.presentingViewController ?: [ALUtils topViewControllerFromKeyWindow];
    }
    else
    {
        presentingViewController = [ALUtils topViewControllerFromKeyWindow];
    }
    
    [UnityAds show: presentingViewController
       placementId: placementIdentifier
           options: [self createAdShowOptions]
      showDelegate: self.rewardedDelegate];
}

#pragma mark - MAAdViewAdapter Methods

- (void)loadAdViewAdForParameters:(id<MAAdapterResponseParameters>)parameters
                         adFormat:(MAAdFormat *)adFormat
                        andNotify:(id<MAAdViewAdapterDelegate>)delegate
{
    NSString *placementIdentifier = parameters.thirdPartyAdPlacementIdentifier;
    [self log: @"Loading banner ad for placement \"%@\"...", placementIdentifier];
    
    [self updatePrivacyConsent: parameters];
    
    self.adViewDelegate = [[OxCustomUnityAdsAdViewDelegate alloc] initWithParentAdapter: self andNotify: delegate];
    self.bannerAdView = [[UADSBannerView alloc] initWithPlacementId: placementIdentifier size: [self bannerSizeFromAdFormat: adFormat]];
    self.bannerAdView.delegate = self.adViewDelegate;
    [self.bannerAdView load];
}

#pragma mark - Shared Methods

- (UADSLoadOptions *)createAdLoadOptionsForParameters:(id<MAAdapterResponseParameters>)parameters
{
    UADSLoadOptions *options = [[UADSLoadOptions alloc] init];
    
    NSString *bidResponse = parameters.bidResponse;
    if ( [bidResponse al_isValidString] )
    {
        options.adMarkup = bidResponse;
    }
    
    if ( [self.biddingAdIdentifier al_isValidString] )
    {
        options.objectId = self.biddingAdIdentifier;
    }
    
    return options;
}

- (UADSShowOptions *)createAdShowOptions
{
    UADSShowOptions *options = [[UADSShowOptions alloc] init];
    if ( [self.biddingAdIdentifier al_isValidString] )
    {
        options.objectId = self.biddingAdIdentifier;
    }
    
    return options;
}

- (CGSize)bannerSizeFromAdFormat:(MAAdFormat *)adFormat
{
    if ( adFormat == MAAdFormat.banner )
    {
        return CGSizeMake(320, 50);
    }
    else if ( adFormat == MAAdFormat.leader )
    {
        return CGSizeMake(728, 90);
    }
    else
    {
        [NSException raise: NSInvalidArgumentException format: @"Unsupported ad format: %@", adFormat];
        return CGSizeMake(320, 50);
    }
}

+ (MAAdapterError *)toMaxError:(UADSBannerError *)unityAdsBannerError
{
    UADSBannerErrorCode unityAdsBannerErrorCode = unityAdsBannerError.code;
    MAAdapterError *adapterError = MAAdapterError.unspecified;
    switch ( unityAdsBannerErrorCode )
    {
        case UADSBannerErrorCodeUnknown:
            adapterError = MAAdapterError.unspecified;
            break;
        case UADSBannerErrorCodeNativeError:
            adapterError = MAAdapterError.internalError;
            break;
        case UADSBannerErrorCodeWebViewError:
            adapterError = MAAdapterError.webViewError;
            break;
        case UADSBannerErrorCodeNoFillError:
            adapterError = MAAdapterError.noFill;
            break;
        case UADSBannerErrorInitializeFailed:
            adapterError = MAAdapterError.notInitialized;
            break;
        case UADSBannerErrorInvalidArgument:
            adapterError = MAAdapterError.invalidConfiguration;
    }
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    return [MAAdapterError errorWithCode: adapterError.errorCode
                             errorString: adapterError.errorMessage
                  thirdPartySdkErrorCode: unityAdsBannerErrorCode
               thirdPartySdkErrorMessage: @""];
#pragma clang diagnostic pop
}

+ (MAAdapterError *)toMaxErrorWithLoadError:(UnityAdsLoadError)unityAdsLoadError withMessage:(NSString *)message
{
    MAAdapterError *adapterError = MAAdapterError.unspecified;
    switch ( unityAdsLoadError )
    {
        case kUnityAdsLoadErrorInitializeFailed:
            adapterError = MAAdapterError.notInitialized;
            break;
        case kUnityAdsLoadErrorInternal:
            adapterError = MAAdapterError.internalError;
            break;
        case kUnityAdsLoadErrorInvalidArgument:
            adapterError = MAAdapterError.invalidConfiguration;
            break;
        case kUnityAdsLoadErrorNoFill:
            adapterError = MAAdapterError.noFill;
            break;
        case kUnityAdsLoadErrorTimeout:
            adapterError = MAAdapterError.timeout;
            break;
    }
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    return [MAAdapterError errorWithCode: adapterError.errorCode
                             errorString: adapterError.errorMessage
                  thirdPartySdkErrorCode: unityAdsLoadError
               thirdPartySdkErrorMessage: message];
#pragma clang diagnostic pop
}

+ (MAAdapterError *)toMaxErrorWithShowError:(UnityAdsShowError)unityAdsShowError withMessage:(NSString *)message
{
    MAAdapterError *adapterError = MAAdapterError.unspecified;
    switch ( unityAdsShowError )
    {
        case kUnityShowErrorNotInitialized:
            adapterError = MAAdapterError.notInitialized;
            break;
        case kUnityShowErrorNotReady:
            adapterError = MAAdapterError.adNotReady;
            break;
        case kUnityShowErrorVideoPlayerError:
            adapterError = MAAdapterError.webViewError;
            break;
        case kUnityShowErrorInvalidArgument:
            adapterError = MAAdapterError.invalidConfiguration;
            break;
        case kUnityShowErrorNoConnection:
            adapterError = MAAdapterError.noConnection;
            break;
        case kUnityShowErrorAlreadyShowing:
            adapterError = MAAdapterError.invalidLoadState;
            break;
        case kUnityShowErrorInternalError:
            adapterError = MAAdapterError.internalError;
            break;
        case kUnityShowErrorTimeout:
            adapterError = MAAdapterError.timeout;
    }
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    return [MAAdapterError errorWithCode: adapterError.errorCode
                             errorString: adapterError.errorMessage
                  thirdPartySdkErrorCode: unityAdsShowError
               thirdPartySdkErrorMessage: message];
#pragma clang diagnostic pop
}

#pragma mark - GDPR

- (void)updatePrivacyConsent:(id<MAAdapterParameters>)parameters
{
    UADSMetaData *privacyConsentMetaData = [[UADSMetaData alloc] init];
    NSNumber *hasUserConsent = [parameters hasUserConsent];
    if ( hasUserConsent != nil )
    {
        [privacyConsentMetaData set: @"gdpr.consent" value: @(hasUserConsent.boolValue)];
        [privacyConsentMetaData commit];
    }
    
    // CCPA compliance - https://unityads.unity3d.com/help/legal/gdpr
    NSNumber *isDoNotSell = [parameters isDoNotSell];
    if ( isDoNotSell != nil )
    {
        [privacyConsentMetaData set: @"privacy.consent" value: @(!isDoNotSell.boolValue)]; // isDoNotSell means user has opted out and is equivalent to NO.
        [privacyConsentMetaData commit];
    }
    
    [privacyConsentMetaData set: @"privacy.mode" value: @"mixed"];
    [privacyConsentMetaData commit];
    
    NSNumber *isAgeRestrictedUser = [parameters isAgeRestrictedUser];
    if ( isAgeRestrictedUser != nil )
    {
        [privacyConsentMetaData set: @"user.nonbehavioral" value: @(isAgeRestrictedUser.boolValue)];
        [privacyConsentMetaData commit];
    }
}

@end

@implementation OxCustomUnityAdsInterstitialDelegate

- (instancetype)initWithParentAdapter:(OxCustomUnityAdsAdapter *)parentAdapter andNotify:(id<MAInterstitialAdapterDelegate>)delegate
{
    self = [super init];
    if ( self )
    {
        self.parentAdapter = parentAdapter;
        self.delegate = delegate;
    }
    return self;
}

#pragma mark - UnityAdsLoadDelegate Methods

- (void)unityAdsAdLoaded:(NSString *)placementId
{
    [self.parentAdapter log: @"Interstitial placement \"%@\" loaded", placementId];
    [self.delegate didLoadInterstitialAd];
}

- (void)unityAdsAdFailedToLoad:(NSString *)placementId withError:(UnityAdsLoadError)error withMessage:(NSString *)message
{
    [self.parentAdapter log: @"Interstitial placement \"%@\" failed to load with error: %ld: %@", placementId, error, message];
    
    MAAdapterError *adapterError = [OxCustomUnityAdsAdapter toMaxErrorWithLoadError: error withMessage: message];
    [self.delegate didFailToLoadInterstitialAdWithError: adapterError];
}

#pragma mark - UnityAdsShowDelegate Methods

- (void)unityAdsShowStart:(NSString *)placementId
{
    [self.parentAdapter log: @"Interstitial placement \"%@\" displayed", placementId];
    [self.delegate didDisplayInterstitialAd];
}

- (void)unityAdsShowClick:(NSString *)placementId
{
    [self.parentAdapter log: @"Interstitial placement \"%@\" clicked", placementId];
    [self.delegate didClickInterstitialAd];
}

- (void)unityAdsShowComplete:(NSString *)placementId withFinishState:(UnityAdsShowCompletionState)state
{
    [self.parentAdapter log: @"Interstitial placement \"%@\" hidden with completion state: %ld", placementId, state];
    [self.delegate didHideInterstitialAd];
}

- (void)unityAdsShowFailed:(NSString *)placementId withError:(UnityAdsShowError)error withMessage:(NSString *)message
{
    [self.parentAdapter log: @"Interstitial placement \"%@\" failed to display with error: %ld: %@", placementId, error, message];
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    MAAdapterError *adapterError = [MAAdapterError errorWithCode: -4205
                                                     errorString: @"Ad Display Failed"
                                          thirdPartySdkErrorCode: error
                                       thirdPartySdkErrorMessage: message];
#pragma clang diagnostic pop
    [self.delegate didFailToDisplayInterstitialAdWithError: adapterError];
}

@end

@implementation OxCustomUnityAdsRewardedDelegate

- (instancetype)initWithParentAdapter:(OxCustomUnityAdsAdapter *)parentAdapter andNotify:(id<MARewardedAdapterDelegate>)delegate
{
    self = [super init];
    if ( self )
    {
        self.parentAdapter = parentAdapter;
        self.delegate = delegate;
    }
    return self;
}

#pragma mark - UnityAdsLoadDelegate Methods

- (void)unityAdsAdLoaded:(NSString *)placementId
{
    [self.parentAdapter log: @"Rewarded ad placement \"%@\" loaded", placementId];
    [self.delegate didLoadRewardedAd];
}

- (void)unityAdsAdFailedToLoad:(NSString *)placementId withError:(UnityAdsLoadError)error withMessage:(NSString *)message
{
    [self.parentAdapter log: @"Rewarded ad placement \"%@\" failed to load with error: %ld: %@", placementId, error, message];
    
    MAAdapterError *adapterError = [OxCustomUnityAdsAdapter toMaxErrorWithLoadError: error withMessage: message];
    [self.delegate didFailToLoadRewardedAdWithError: adapterError];
}

#pragma mark - UnityAdsShowDelegate Methods

- (void)unityAdsShowStart:(NSString *)placementId
{
    [self.parentAdapter log: @"Rewarded ad placement \"%@\" displayed", placementId];
    [self.delegate didDisplayRewardedAd];
    [self.delegate didStartRewardedAdVideo];
}

- (void)unityAdsShowClick:(NSString *)placementId
{
    [self.parentAdapter log: @"Rewarded ad placement \"%@\" clicked", placementId];
    [self.delegate didClickRewardedAd];
}

- (void)unityAdsShowComplete:(NSString *)placementId withFinishState:(UnityAdsShowCompletionState)state
{
    [self.parentAdapter log: @"Rewarded ad placement \"%@\" hidden with completion state: %ld", placementId, state];
    [self.delegate didCompleteRewardedAdVideo];
    if ( state == kUnityShowCompletionStateCompleted || [self.parentAdapter shouldAlwaysRewardUser] )
    {
        [self.delegate didRewardUserWithReward: [self.parentAdapter reward]];
    }
    [self.delegate didHideRewardedAd];
}

- (void)unityAdsShowFailed:(NSString *)placementId withError:(UnityAdsShowError)error withMessage:(NSString *)message
{
    [self.parentAdapter log: @"Rewarded ad placement \"%@\" failed to display with error: %ld: %@", placementId, error, message];
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    MAAdapterError *adapterError = [MAAdapterError errorWithCode: -4205
                                                     errorString: @"Ad Display Failed"
                                          thirdPartySdkErrorCode: error
                                       thirdPartySdkErrorMessage: message];
#pragma clang diagnostic pop
    [self.delegate didFailToDisplayRewardedAdWithError: adapterError];
}

@end

@implementation OxCustomUnityAdsAdViewDelegate

- (instancetype)initWithParentAdapter:(OxCustomUnityAdsAdapter *)parentAdapter andNotify:(id<MAAdViewAdapterDelegate>)delegate
{
    self = [super init];
    if ( self )
    {
        self.parentAdapter = parentAdapter;
        self.delegate = delegate;
    }
    return self;
}

#pragma mark - UADSBannerDelegate Methods

- (void)bannerViewDidLoad:(UADSBannerView *)bannerView
{
    [self.parentAdapter log: @"Banner ad loaded"];
    [self.delegate didLoadAdForAdView: bannerView];
}

- (void)bannerViewDidError:(UADSBannerView *)bannerView error:(UADSBannerError *)error
{
    [self.parentAdapter log: @"Banner ad failed to load: %@", error];
    [self.delegate didFailToLoadAdViewAdWithError: [OxCustomUnityAdsAdapter toMaxError: error]];
}

- (void)bannerViewDidShow:(UADSBannerView *)bannerView
{
    [self.parentAdapter log: @"Banner shown"];
    [self.delegate didDisplayAdViewAd];
}

- (void)bannerViewDidClick:(UADSBannerView *)bannerView
{
    [self.parentAdapter log: @"Banner ad clicked"];
    [self.delegate didClickAdViewAd];
}

- (void)bannerViewDidLeaveApplication:(UADSBannerView *)bannerView
{
    [self.parentAdapter log: @"Banner ad left application"];
}

@end

@implementation OxCustomUnityAdsInitializationDelegate

- (instancetype)initWithParentAdapter:(OxCustomUnityAdsAdapter *)parentAdapter andCompletionHandler:(void (^)(MAAdapterInitializationStatus, NSString *_Nullable))completionHandler
{
    self = [super init];
    if ( self )
    {
        self.parentAdapter = parentAdapter;
        self.completionHandler = completionHandler;
    }
    return self;
}

#pragma mark - UnityAdsInitializationDelegate Methods

- (void)initializationComplete
{
    [self.parentAdapter log: @"UnityAds SDK initialized"];
    
    OxCustomUnityAdsInitializationStatus = MAAdapterInitializationStatusInitializedSuccess;
    
    if ( self.completionHandler )
    {
        self.completionHandler(OxCustomUnityAdsInitializationStatus, nil);
        self.completionHandler = nil;
    }
}

- (void)initializationFailed:(UnityAdsInitializationError)error withMessage:(NSString *)message
{
    [self.parentAdapter log: @"UnityAds SDK failed to initialize with error: %@", message];
    
    OxCustomUnityAdsInitializationStatus = MAAdapterInitializationStatusInitializedFailure;
    
    if ( self.completionHandler )
    {
        self.completionHandler(OxCustomUnityAdsInitializationStatus, message);
        self.completionHandler = nil;
    }
}

@end
