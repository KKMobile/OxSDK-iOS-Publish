//
//  ConfigCopier.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class AdConfig;
@class AdapterConfig;
@class AdNetworkConfig;
@class AppConfig;
@class AppUserValueConfig;
@class AdUnitBaseConfig;
@class IdConfig;
@class UserValueConfig;
@class IntervalConfig;

NS_ASSUME_NONNULL_BEGIN

@interface ConfigCopier : NSObject

+ (AdConfig * _Nullable)copyAdConfig:(AdConfig * _Nullable)original;
+ (AdapterConfig * _Nullable)copyAdapterConfig:(AdapterConfig * _Nullable)original;
+ (AdNetworkConfig * _Nullable)copyAdNetworkConfig:(AdNetworkConfig * _Nullable)original;
+ (AppConfig * _Nullable)copyAppConfig:(AppConfig * _Nullable)original;
+ (AppUserValueConfig * _Nullable)copyAppUserValueConfig:(AppUserValueConfig * _Nullable)original;
+ (AdUnitBaseConfig * _Nullable)copyAdUnitBaseConfig:(AdUnitBaseConfig * _Nullable)original;
+ (IntervalConfig * _Nullable)copyIntervalConfig:(IntervalConfig * _Nullable)original;
+ (IdConfig * _Nullable)copyIdConfig:(IdConfig * _Nullable)original;
+ (UserValueConfig * _Nullable)copyUserValueConfig:(UserValueConfig * _Nullable)original;
+ (NSArray<IdConfig *> * _Nullable)copyIdConfigList:(NSArray<IdConfig *> * _Nullable)original;
+ (NSDictionary<NSString *, AdUnitBaseConfig *> * _Nullable)copyAdUnitMap:(NSDictionary<NSString *, AdUnitBaseConfig *> * _Nullable)original;

@end

NS_ASSUME_NONNULL_END
