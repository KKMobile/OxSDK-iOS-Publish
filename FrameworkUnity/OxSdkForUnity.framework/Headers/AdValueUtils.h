//
//  AdValueUtils.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/16.
//

#import <Foundation/Foundation.h>
#import <GoogleMobileAds/GoogleMobileAds.h>
#import <AppLovinSDK/AppLovinSDK.h>
#import "OxAdSdkManager.h"
#import "AdEventUtil.h"
NS_ASSUME_NONNULL_BEGIN


@interface AdValueUtils : NSObject

@property (nonatomic, strong) NSArray     *firebaseConfigValues;

+ (instancetype)shared;

- (void)logMaxImpressionRevenue:(MAAd *)ad;

- (void)logAdmobImpressionRevenue:(NSString *)adUnitId adFormat:(NSString *)adFormat adNetwork:(NSString *)adNetwork advalue:(GADAdValue *)advalue;
@end

NS_ASSUME_NONNULL_END
