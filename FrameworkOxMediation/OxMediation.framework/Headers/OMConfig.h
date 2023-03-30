// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMUnit.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, OMInitState) {
    OMInitStateDefault = 0,
    OMInitStateInitializing = 1,
    OMInitStateInitialized = 2,
    OMInitStateReinitialize = 3,
};

@interface OMConfig : NSObject

@property (nonatomic, strong) NSDictionary *adFormats;
@property (nonatomic, assign) OMInitState initState;
@property (nonatomic, assign) BOOL initSuccess;

@property (nonatomic, copy) NSString *baseHost;
@property (nonatomic, copy) NSString *appKey;

@property (nonatomic, assign) BOOL openDebug;
@property (nonatomic, assign) NSInteger reinitInterval;
@property (nonatomic, copy) NSString *wfUrl;
@property (nonatomic, copy) NSString *lrUrl;
@property (nonatomic, copy) NSString *icUrl;
@property (nonatomic, copy) NSString *iapUrl;
@property (nonatomic, copy) NSString *erUrl;
@property (nonatomic, copy) NSString *cdUrl;
@property (nonatomic, copy) NSString *hbUrl;
@property (nonatomic, copy) NSString *clUrl;
@property (nonatomic, copy) NSString *plUrl;
@property (nonatomic, copy) NSString *apsUrl;

@property (nonatomic, strong) NSMutableDictionary *adnNameMap;
@property (nonatomic, strong) NSMutableDictionary *adnNickName;
@property (nonatomic, strong) NSMutableDictionary *adnAppkeyMap;
@property (nonatomic, strong) NSDictionary *adnSDKName;
@property (nonatomic, strong) NSMutableDictionary *adnExpiredTime;
@property (nonatomic, strong) NSMutableDictionary *adnSignature;
@property (nonatomic, strong) NSMutableDictionary *adnPublisherMap;

@property (nonatomic, strong) NSMutableArray *adUnitList;
@property (nonatomic, strong) NSMutableDictionary *adUnitMap;
@property (nonatomic, strong) NSDictionary *cachedUnitMap;
@property (nonatomic, strong) NSMutableDictionary *instanceMap;
@property (nonatomic, strong) NSMutableDictionary *adnPlacementMap;
@property (nonatomic, strong) NSMutableDictionary *conversionData;
@property (nonatomic, strong) NSMutableDictionary *apsDict;
@property (nonatomic, assign) BOOL clickOpenAppStore;
@property (nonatomic, assign) BOOL impressionDataCallBack;
@property (nonatomic, assign) OxMediationAdFormat useCacheAdFormat;
@property (nonatomic, assign) BOOL autoCache;
@property (nonatomic, strong) NSArray<NSString *> *keywords;

+ (instancetype)sharedInstance;

- (NSString *)adFormatName:(OxMediationAdFormat)adFormat;

- (void)loadCongifData:(NSDictionary *)configData;

- (void)loadApi:(NSDictionary*)apiDic;

- (void)loadMediation:(NSArray *)mediationData;

- (NSString *)adnName:(OMAdNetwork)adnID;

- (NSString *)adnNickName:(OMAdNetwork)adnID;

- (NSString *)adnAppKey:(OMAdNetwork)adnID;

- (NSInteger)adnExpiredTime:(OMAdNetwork)adnID;

- (NSString *)adnSignatureID:(OMAdNetwork)adnID;

//MARK: - keyWords

- (NSString *)getKeywordParam;

//MARK: - AdUinit
- (void)loadAdUnits:(NSArray *)adUnits;

- (BOOL)configContainAdUnit:(NSString*)unitID;

- (NSArray*)adFormatUnits:(OxMediationAdFormat)adFormat;

- (NSString*)defaultUnitIDForAdFormat:(OxMediationAdFormat)adFormat;

- (OxMediationAdFormat)adUnitFormat:(NSString*)unitID;

- (BOOL)isValidAdUnitId:(NSString*)unitID forAdFormat:(OxMediationAdFormat)adFormat;

//MARK: - Instance
- (OMAdNetwork)getInstanceAdNetwork:(NSString*)instanceID;
- (OMInstance *)getInstanceByinstanceID:(NSString*)instanceID;

//MARK: - Scene
- (OMScene *)getSceneWithSceneID:(NSString*)sceneID inAdUnit:(NSString*)unitID;

- (OMScene *)getSceneWithSceneName:(NSString*)sceneName inAdUnit:(NSString*)unitID;

- (NSString *)getSceneIDWithSceneName:(NSString*)sceneName inAdUnit:(NSString*)unitID;


//MARK: - AdNetwork Placements
- (NSArray *)adnPlacements:(OMAdNetwork)adnID;

- (void)saveConfigData:(NSDictionary*)configData appKey:(NSString*)appKey version:(NSString*)version;

- (NSDictionary*)configCacheData:(NSString*)appKey version:(NSString*)version;

- (void)saveWaterfallData:(NSDictionary*)waterfallData placementID:(NSString*)pid version:(NSString*)version;

- (NSDictionary*)waterfallCacheData:(NSString*)pid version:(NSString*)version;

- (void)saveApsFileHashData:(NSArray *)hashData fileHash:(NSString *)fileHash placementID:(NSString*)pid;
- (NSArray *)apsFileHashCacheData:(NSString*)pid fileHash:(NSString *)fileHash;

@end

NS_ASSUME_NONNULL_END
