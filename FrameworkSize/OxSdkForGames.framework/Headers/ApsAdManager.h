//
//  ApsAdManager.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/20.
//

#import <Foundation/Foundation.h>
#import <DTBiOSSDK/DTBiOSSDK.h>
#import <AppLovinSDK/AppLovinSDK.h>
#import "AdEvents.h"
NS_ASSUME_NONNULL_BEGIN

@interface ApsAdManager : NSObject

+ (nonnull instancetype)sharedInstance;

- (void)initApsSdk;

- (NSString *)getApsAppId;

- (void)setApsTestMode:(BOOL)mode;

@end

NS_ASSUME_NONNULL_END
