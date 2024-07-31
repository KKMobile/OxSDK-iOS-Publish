//
//  OxConfig.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/1.
//

#import <Foundation/Foundation.h>
#import "OxAdUnit.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxSdkConfig : NSObject

+ (nonnull instancetype)sharedInstance;

@property (nonatomic,strong)  NSDictionary<NSNumber *,NSString *> *mediationSDKName;

/// ad config
@property (nonatomic,strong) NSMutableDictionary<NSString *,OxAdUnit *> *adUnitMap;
@property (nonatomic,strong) NSMutableDictionary<NSString *,NSString *> *adjustTokenMap;
@property (nonatomic,strong) NSMutableDictionary<NSString *,id> *remoteConfigDefaultsMap;

/// 用于 max setInitializationAdUnitIdentifiers
@property (nonatomic,strong) NSMutableArray *maxAdUnitIds;

/// APS Config
@property (nonatomic,copy) NSString *apsAppId;
@property (nonatomic,copy) NSString *apsBannerId;
@property (nonatomic,copy) NSString *apsMRecId;
@property (nonatomic,copy) NSString *apsInterId;
@property (nonatomic,copy) NSString *apsRewardedId;
@property (nonatomic,assign) NSInteger apsInterType;

/// cache disable ids config
@property (nonatomic,copy) NSString *maxCacheDisabledIds;

// 默认 mediation
@property (nonatomic,assign) OxSdkMediationType defaultMediation;

/// 获取 RemoteConfig 默认值
/// - Parameter key: key
- (id)getRemoteConfigDefaultValue:(NSString *)key;
- (void)parseOxConfig:(void (^)(BOOL success))completion;


@end

NS_ASSUME_NONNULL_END
