//
//  OxDiscoveryEventsTracker.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/6.
//

#import <Foundation/Foundation.h>
#import "OxDiscoveryPluginClass.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxDiscoveryEventsTracker : NSObject

+ (nonnull instancetype)sharedInstance;

- (void)logMaxImpressionRevenue:(MAAd *)ad placement:(NSString *)placement coreLevel:(NSInteger)coreLevel;
- (void)logAdmobImpressionRevenue:(NSString *)adUnitId adFormat:(NSString *)adFormat adNetwork:(NSString *)adNetwork advalue:(GADAdValue *)advalue placement:(NSString *)placement coreLevel:(NSInteger)coreLevel;

@end

NS_ASSUME_NONNULL_END
