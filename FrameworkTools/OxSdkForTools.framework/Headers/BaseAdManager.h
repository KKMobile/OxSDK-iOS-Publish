//
//  BaseAdManager.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/21.
//

#import <Foundation/Foundation.h>
#import <AppLovinSDK/AppLovinSDK.h>
#import <GoogleMobileAds/GoogleMobileAds.h>
#import <FBAudienceNetwork/FBAudienceNetwork.h>
#import "AdEvents.h"
#import "ApsAdManager.h"
NS_ASSUME_NONNULL_BEGIN

typedef void (^OnSdkInitComplete)(void);

@interface BaseAdManager : NSObject

/// 广告初始化
/// @param successBlock 初始化成功回调
/// 当取到firebase的值后，先调用updateMediationType，然后需要调用该方法，监测是否需要初始化另外一个广告平台，
- (void)initialize:(OnSdkInitComplete)successBlock;

- (BOOL)isSdkInitialed;

- (void)enableDebug:(BOOL)enable;

- (void)showMediationDebugger;

- (void)setHasUserConsent:(BOOL)hasUserConsent;

- (void)setMute:(BOOL)mute;

- (NSString*)getSdkVersion;

- (ALSdkConfiguration*)getSdkConfiguration;

- (void)setCoreLevel:(int)level;

/**
* Note that the user ID is neither the user’s IDFA nor the device ID; it is your own proprietary user identifier.
*/
- (void)setUserId:(NSString *)userIdentifier;

@end

NS_ASSUME_NONNULL_END

