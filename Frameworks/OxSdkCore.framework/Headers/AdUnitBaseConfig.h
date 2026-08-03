//
//  AdUnitBaseConfig.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

#import "IdConfig.h"
#import "IntervalConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdUnitBaseConfig : NSObject

@property (nonatomic, copy) NSString *adUnitName;
@property (nonatomic, copy) NSString *extraParameters; // 参数多余？
@property (nonatomic, copy) NSString *cacheModel; // DashBoard 暂时未配
@property (nonatomic, assign) NSInteger parallelCount;
@property (nonatomic, assign) BOOL isCloseReload;
@property (nonatomic, assign) BOOL isFailReload;
@property (nonatomic, assign) BOOL isHasFailReloadKey;
@property (nonatomic, assign) BOOL isHasCloseReloadKey;
@property (nonatomic, assign) NSInteger cacheSize;
@property (nonatomic, assign) NSInteger reloadSquare;
@property (nonatomic, assign) NSInteger timeout; // DashBoard 暂时未配 ？ 但是是否再用？
@property (nonatomic, assign) NSInteger memoryLimit;// DashBoard 暂时未配
@property (nonatomic, assign) NSInteger showCountHour;
@property (nonatomic, assign) NSInteger showCountDaily;
@property (nonatomic, assign) NSInteger showStartLevelDaily;
@property (nonatomic, assign) NSInteger showInterval;
@property (nonatomic, assign) NSInteger expirationTimeSeconds;// DashBoard配置的名称叫 placementTimeOut
@property (nonatomic, strong, nullable) IntervalConfig *interval;
@property (nonatomic, strong) NSArray<IdConfig *> *ids;

@property (nonatomic, assign) BOOL hasExtraParameters;
@property (nonatomic, assign) BOOL hasParallelCount;
@property (nonatomic, assign) BOOL hasCacheModel;
@property (nonatomic, assign) BOOL hasCacheSize;
@property (nonatomic, assign) BOOL hasReloadSquare;
@property (nonatomic, assign) BOOL hasTimeout;
@property (nonatomic, assign) BOOL hasMemoryLimit;
@property (nonatomic, assign) BOOL hasShowCountHour;
@property (nonatomic, assign) BOOL hasShowCountDaily;
@property (nonatomic, assign) BOOL hasShowStartLevelDaily;
@property (nonatomic, assign) BOOL hasShowInterval;
@property (nonatomic, assign) BOOL hasExpirationTimeSeconds;
@property (nonatomic, assign) BOOL hasInterval;

- (NSInteger)parallelCountWithDefault:(NSInteger)defaultValue;

@end

NS_ASSUME_NONNULL_END
