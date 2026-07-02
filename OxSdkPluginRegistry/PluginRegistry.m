//
//  PluginRegistry.m
//  OxSdkPluginRegistry
//

#import "PluginRegistry.h"

static id<ConfigProvider> sConfigProvider;
static id<AdjustService> sAdjustService;
static id<FacebookEventService> sFacebookEventService;
static id<ThinkingAnalyticsService> sThinkingAnalyticsService;
static id<FirebaseAnalyticsService> sFirebaseAnalyticsService;
static id<DiscoveryService> sDiscoveryService;

@interface OxEmptyConfigProvider : NSObject <ConfigProvider>
@end
@implementation OxEmptyConfigProvider
- (NSInteger)getInt:(NSString *)key defaultValue:(NSInteger)defaultValue { return defaultValue; }
- (NSString *)getString:(NSString *)key fallback:(NSString *)fallback { return fallback; }
- (double)getDouble:(NSString *)key defaultValue:(double)defaultValue { return defaultValue; }
- (BOOL)getBool:(NSString *)key defaultValue:(BOOL)defaultValue { return defaultValue; }
@end

@interface OxEmptyAdjustService : NSObject <AdjustService>
@end
@implementation OxEmptyAdjustService
- (void)trackEvent:(NSString *)eventName params:(NSDictionary *)params {}
- (void)trackAdRevenue:(NSString *)mediation params:(NSDictionary *)params {}
- (NSString *)getNetworkByAttribution { return nil; }
- (NSString *)getCampaignByAttribution { return nil; }
- (NSString *)getAdidByAttribution { return nil; }
@end

@interface OxEmptyFacebookEventService : NSObject <FacebookEventService>
@end
@implementation OxEmptyFacebookEventService
- (void)trackEvent:(NSString *)eventName params:(NSDictionary *)params {}
@end

@interface OxEmptyThinkingAnalyticsService : NSObject <ThinkingAnalyticsService>
@end
@implementation OxEmptyThinkingAnalyticsService
- (void)trackEvent:(NSString *)eventName params:(NSDictionary *)params {}
@end

@interface OxEmptyFirebaseAnalyticsService : NSObject <FirebaseAnalyticsService>
@end
@implementation OxEmptyFirebaseAnalyticsService
- (void)trackEvent:(NSString *)eventName params:(NSDictionary *)params {}
- (void)setUserProperty:(NSString *)key value:(NSString *)value {}
- (void)logFirebaseAdImp:(NSDictionary *)params {}
- (NSString *)getFirebaseId { return @""; }
@end

@interface OxEmptyDiscoveryService : NSObject <DiscoveryService>
@end
@implementation OxEmptyDiscoveryService
- (void)logMaxImpressionRevenue:(NSDictionary *)params {}
- (void)logAdmobImpressionRevenue:(NSDictionary *)params {}
@end

static OxEmptyConfigProvider *kEmptyConfigProvider;
static OxEmptyAdjustService *kEmptyAdjustService;
static OxEmptyFacebookEventService *kEmptyFacebookEventService;
static OxEmptyThinkingAnalyticsService *kEmptyThinkingAnalyticsService;
static OxEmptyFirebaseAnalyticsService *kEmptyFirebaseAnalyticsService;
static OxEmptyDiscoveryService *kEmptyDiscoveryService;

@implementation PluginRegistry

+ (void)initialize {
    if (self == [PluginRegistry class]) {
        kEmptyConfigProvider = [[OxEmptyConfigProvider alloc] init];
        kEmptyAdjustService = [[OxEmptyAdjustService alloc] init];
        kEmptyFacebookEventService = [[OxEmptyFacebookEventService alloc] init];
        kEmptyThinkingAnalyticsService = [[OxEmptyThinkingAnalyticsService alloc] init];
        kEmptyFirebaseAnalyticsService = [[OxEmptyFirebaseAnalyticsService alloc] init];
        kEmptyDiscoveryService = [[OxEmptyDiscoveryService alloc] init];
        sConfigProvider = kEmptyConfigProvider;
        sAdjustService = kEmptyAdjustService;
        sFacebookEventService = kEmptyFacebookEventService;
        sThinkingAnalyticsService = kEmptyThinkingAnalyticsService;
        sFirebaseAnalyticsService = kEmptyFirebaseAnalyticsService;
        sDiscoveryService = kEmptyDiscoveryService;
    }
}

+ (void)registerConfigProvider:(id<ConfigProvider>)provider {
    sConfigProvider = provider ?: kEmptyConfigProvider;
}

+ (void)registerAdjustService:(id<AdjustService>)service {
    sAdjustService = service ?: kEmptyAdjustService;
}

+ (void)registerFacebookEventService:(id<FacebookEventService>)service {
    sFacebookEventService = service ?: kEmptyFacebookEventService;
}

+ (void)registerThinkingAnalyticsService:(id<ThinkingAnalyticsService>)service {
    sThinkingAnalyticsService = service ?: kEmptyThinkingAnalyticsService;
}

+ (void)registerFirebaseAnalyticsService:(id<FirebaseAnalyticsService>)service {
    sFirebaseAnalyticsService = service ?: kEmptyFirebaseAnalyticsService;
}

+ (void)registerDiscoveryService:(id<DiscoveryService>)service {
    sDiscoveryService = service ?: kEmptyDiscoveryService;
}

+ (id<ConfigProvider>)configProvider { return sConfigProvider; }
+ (id<AdjustService>)adjustService { return sAdjustService; }
+ (id<FacebookEventService>)facebookEventService { return sFacebookEventService; }
+ (id<ThinkingAnalyticsService>)thinkingAnalyticsService { return sThinkingAnalyticsService; }
+ (id<FirebaseAnalyticsService>)firebaseAnalyticsService { return sFirebaseAnalyticsService; }
+ (id<DiscoveryService>)discoveryService { return sDiscoveryService; }

@end
