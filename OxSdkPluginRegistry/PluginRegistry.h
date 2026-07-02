//
//  PluginRegistry.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

#import "ConfigProvider.h"
#import "AdjustService.h"
#import "FacebookEventService.h"
#import "ThinkingAnalyticsService.h"
#import "FirebaseAnalyticsService.h"
#import "DiscoveryService.h"

NS_ASSUME_NONNULL_BEGIN

@interface PluginRegistry : NSObject

+ (void)registerConfigProvider:(nullable id<ConfigProvider>)provider;
+ (void)registerAdjustService:(nullable id<AdjustService>)service;
+ (void)registerFacebookEventService:(nullable id<FacebookEventService>)service;
+ (void)registerThinkingAnalyticsService:(nullable id<ThinkingAnalyticsService>)service;
+ (void)registerFirebaseAnalyticsService:(nullable id<FirebaseAnalyticsService>)service;
+ (void)registerDiscoveryService:(nullable id<DiscoveryService>)service;

+ (id<ConfigProvider>)configProvider;
+ (id<AdjustService>)adjustService;
+ (id<FacebookEventService>)facebookEventService;
+ (id<ThinkingAnalyticsService>)thinkingAnalyticsService;
+ (id<FirebaseAnalyticsService>)firebaseAnalyticsService;
+ (id<DiscoveryService>)discoveryService;

@end

NS_ASSUME_NONNULL_END
