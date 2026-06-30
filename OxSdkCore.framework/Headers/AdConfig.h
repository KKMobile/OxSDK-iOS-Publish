//
//  AdConfig.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

#import "AdapterConfig.h"
#import "AppConfig.h"
#import "AdUnitBaseConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdConfig : NSObject

@property (nonatomic, strong) AdapterConfig * adapter;
@property (nonatomic, strong) AppConfig * app;
@property (nonatomic, copy) NSDictionary<NSString *, AdUnitBaseConfig *> * banner;
@property (nonatomic, copy) NSDictionary<NSString *, AdUnitBaseConfig *> * nativeAd;
@property (nonatomic, copy) NSDictionary<NSString *, AdUnitBaseConfig *> * mrec;
@property (nonatomic, copy) NSDictionary<NSString *, AdUnitBaseConfig *> * interstitial;
@property (nonatomic, copy) NSDictionary<NSString *, AdUnitBaseConfig *> * rewarded;
@property (nonatomic, copy) NSDictionary<NSString *, AdUnitBaseConfig *> * openAds;

@end

NS_ASSUME_NONNULL_END
