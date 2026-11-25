//
//  IdConfig.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

#import "UserValueConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface IdConfig : NSObject

@property (nonatomic, copy) NSString *adType;
@property (nonatomic, assign) NSInteger weight;
@property (nonatomic, assign) NSInteger timeout;
@property (nonatomic, assign) BOOL enable;
@property (nonatomic, assign) BOOL disabledCache;
@property (nonatomic, assign) BOOL disabledRetry;
@property (nonatomic, assign) double dynamic;
@property (nonatomic, copy) NSString *maxApsId;
@property (nonatomic, assign) NSInteger apsType;
@property (nonatomic, copy) NSString *adId;
@property (nonatomic, copy) NSString *mediation;
@property (nonatomic, copy) NSString *extraParameters;
@property (nonatomic, strong, nullable) UserValueConfig *userValue;
@property (nonatomic, assign) BOOL fromSegment;

@property (nonatomic, assign) BOOL hasAdType;
@property (nonatomic, assign) BOOL hasWeight;
@property (nonatomic, assign) BOOL hasTimeout;
@property (nonatomic, assign) BOOL hasDisabledCache;
@property (nonatomic, assign) BOOL hasEnable;
@property (nonatomic, assign) BOOL hasDisabledRetry;
@property (nonatomic, assign) BOOL hasDynamic;
@property (nonatomic, assign) BOOL hasMaxApsId;
@property (nonatomic, assign) BOOL hasApsType;
@property (nonatomic, assign) BOOL hasId;
@property (nonatomic, assign) BOOL hasMediation;
@property (nonatomic, assign) BOOL hasExtraParameters;
@property (nonatomic, assign) BOOL hasUserValue;

- (NSTimeInterval)timeoutMillis;
- (NSString *)id;
- (void)setId:(NSString *)adId;

- (BOOL)hasUserValue;

@end

NS_ASSUME_NONNULL_END
