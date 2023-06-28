//
//  OxDiscoveryPluginClass.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/6.
//

#import <Foundation/Foundation.h>
#import <AppLovinSDK/AppLovinSDK.h>
#import <GoogleMobileAds/GoogleMobileAds.h>

NS_ASSUME_NONNULL_BEGIN

@protocol OxDiscoveryDelegate <NSObject>

- (void)onBeforeTrackingEvent:(NSString *)eventName;
- (void)onEventTracked:(NSString *)eventName params:(NSDictionary *)params;
- (void)onDailyLevelChanged:(NSInteger)level;
- (double)getRcDouble:(NSString *)key defaultValue:(double)defaultValue;

@end


@interface OxDiscovery : NSObject

@property(nonatomic,weak) id<OxDiscoveryDelegate> delegate;
@property(nonatomic,strong) NSDictionary<NSString *,NSString *> *adjustTokenDic;
@property(nonatomic,strong) NSArray<NSString *> *firebaseEvents;
@property(nonatomic,strong) NSArray<NSString *> *adjustEvents;

+ (nonnull instancetype)sharedInstance;

- (void)logMaxImpressionRevenue:(MAAd *)ad placement:(NSString *)placement coreLevel:(NSInteger)coreLevel;
- (void)logAdmobImpressionRevenue:(NSString *)adUnitId adFormat:(NSString *)adFormat adNetwork:(NSString *)adNetwork advalue:(GADAdValue *)advalue placement:(NSString *)placement coreLevel:(NSInteger)coreLevel;

- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

- (void)onDailyLevelChanged:(NSInteger)level;
- (double)getRcDouble:(NSString *)key defaultValue:(double)defaultValue;

@end

NS_ASSUME_NONNULL_END
