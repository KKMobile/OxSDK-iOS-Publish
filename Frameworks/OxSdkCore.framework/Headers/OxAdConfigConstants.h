//
//  OxAdConfigConstants.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdConfigConstants : NSObject

// Cache
extern NSString * const OxAdConfigSPName;
extern NSString * const OxAdConfigKeyConfigJSON;
extern NSString * const OxAdConfigKeyConfigVersion;
extern NSString * const OxAdConfigKeyDynamicConfigJSON;
extern NSString * const OxAdConfigKeyDynamicConfigVersion;
extern NSString * const OxAdConfigMemoryCacheKey;
extern NSInteger const OxAdConfigCurrentVersion;
extern NSString * const OxAdConfigAssetsFileName;
extern NSString * const OxAdConfigAssetsReviewFileName;

// Config source
extern NSString * const OxAdConfigSourceMemory;
extern NSString * const OxAdConfigSourceMemoryReview;
extern NSString * const OxAdConfigSourceRemote;
extern NSString * const OxAdConfigSourceSP;
extern NSString * const OxAdConfigSourceAssets;
extern NSString * const OxAdConfigSourceAssetsReview;

// JSON keys
extern NSString * const OxAdConfigKeyDefault;
extern NSString * const OxAdConfigKeySegments;
extern NSString * const OxAdConfigKeyRules;
extern NSString * const OxAdConfigKeyAppVersion;
extern NSString * const OxAdConfigKeyInstallDay;
extern NSString * const OxAdConfigKeyInstallHour;
extern NSString * const OxAdConfigKeySession;
extern NSString * const OxAdConfigKeyGameCore;
extern NSString * const OxAdConfigKeyMemoryControl;
extern NSString * const OxAdConfigKeyDeviceModule;
extern NSString * const OxAdConfigKeyCustom;
extern NSString * const OxAdConfigKeyPriority;
extern NSString * const OxAdConfigKeyRule;
extern NSString * const OxAdConfigKeyBegin;
extern NSString * const OxAdConfigKeyEnd;
extern NSString * const OxAdConfigKeyRam;
extern NSString * const OxAdConfigKeyRom;
extern NSString * const OxAdConfigKeyPassLevels;
extern NSString * const OxAdConfigKeyPlayMinutes;
extern NSString * const OxAdConfigKeyPayCounts;
extern NSString * const OxAdConfigKeyEnable;
extern NSString * const OxAdConfigKeyIdEnable;
extern NSString * const OxAdConfigKeyHighThreshold;
extern NSString * const OxAdConfigKeyLowThreshold;
extern NSString * const OxAdConfigKeyAdapter;
extern NSString * const OxAdConfigKeyApp;
extern NSString * const OxAdConfigKeyDiscovery;
extern NSString * const OxAdConfigKeyAdmob;
extern NSString * const OxAdConfigKeyMax;
extern NSString * const OxAdConfigKeyAppId;
extern NSString * const OxAdConfigKeyApsAppId;
extern NSString * const OxAdConfigKeyPackageName;
extern NSString * const OxAdConfigKeyVersion;
extern NSString * const OxAdConfigKeyMediation;
extern NSString * const OxAdConfigKeyUserValue;
extern NSString * const OxAdConfigKeyOrder;
extern NSString * const OxAdConfigKeyFunction;
extern NSString * const OxAdConfigKeyDuration;
extern NSString * const OxAdConfigKeyQuantity;
extern NSString * const OxAdConfigKeySummary;
extern NSString * const OxAdConfigKeyFactor;
extern NSString * const OxAdConfigKeyGeoConsent;
extern NSString * const OxAdConfigKeyDaysOfNewUser;
extern NSString * const OxAdConfigKeyDepthUserLevel;
extern NSString * const OxAdConfigKeyEventLevel;
extern NSString * const OxAdConfigKeyExtraParameters;
extern NSString * const OxAdConfigKeyParallelCount;
extern NSString * const OxAdConfigKeyCacheModel;
extern NSString * const OxAdConfigKeyIsCloseReload;
extern NSString * const OxAdConfigKeyIsFailReload;
extern NSString * const OxAdConfigKeyCacheSize;
extern NSString * const OxAdConfigKeyReloadSquare;
extern NSString * const OxAdConfigKeyTimeout;
extern NSString * const OxAdConfigKeyIds;
extern NSString * const OxAdConfigKeyMemoryLimit;
extern NSString * const OxAdConfigKeyShowCountHour;
extern NSString * const OxAdConfigKeyShowCountDaily;
extern NSString * const OxAdConfigKeyShowStartLevelDaily;
extern NSString * const OxAdConfigKeyShowInterval;
extern NSString * const OxAdConfigKeyExpirationTimeSeconds;
extern NSString * const OxAdConfigKeyGlobalShowInterval;
extern NSString * const OxAdConfigKeyIntervalTime;
extern NSString * const OxAdConfigKeyIntervalType;
extern NSString * const OxAdConfigKeyIntervalGroup;
extern NSString * const OxAdConfigKeyAdType;
extern NSString * const OxAdConfigKeyApsType;
extern NSString * const OxAdConfigKeyWeight;
extern NSString * const OxAdConfigKeyTimeOut;
extern NSString * const OxAdConfigKeyIsOpenUserValue;
extern NSString * const OxAdConfigKeyDisabledCache;
extern NSString * const OxAdConfigKeyDisabledRetry;
extern NSString * const OxAdConfigKeySegment;
extern NSString * const OxAdConfigKeyDynamic;
extern NSString * const OxAdConfigKeyMaxApsId;
extern NSString * const OxAdConfigKeyId;
extern NSString * const OxAdConfigKeyDefaultSegment;
extern NSString * const OxAdConfigKeyWaterfallValue;
extern NSString * const OxAdConfigKeySegmentValue;
extern NSString * const OxAdConfigKeyAdjustTokens;
extern NSString * const OxAdConfigKeyAdjust;
extern NSString * const OxAdConfigKeyFacebook;
extern NSString * const OxAdConfigKeyFirebase;
extern NSString * const OxAdConfigKeyTA;
extern NSString * const OxAdConfigKeyUA;
extern NSString * const OxAdConfigKeyEventName;
extern NSString * const OxAdConfigKeyToken;
extern NSString * const OxAdConfigKeyDDL;
extern NSString * const OxAdConfigKeyAirDiscount;
extern NSString * const OxAdConfigKeyName;
extern NSString * const OxAdConfigKeyType;
extern NSString * const OxAdConfigKeyValue;
extern NSString * const OxAdConfigKeyChannel;
extern NSString * const OxAdConfigKeyOxAll;
extern NSString * const OxAdConfigKeyCampaign;
extern NSString * const OxAdConfigKeyBI;
extern NSString * const OxAdConfigKeyPercent;

// Default values
extern NSInteger const OxAdConfigDefaultParallelCount;
extern BOOL const OxAdConfigDefaultCloseReload;
extern BOOL const OxAdConfigDefaultFailReload;
extern NSInteger const OxAdConfigDefaultCacheSize;
extern NSInteger const OxAdConfigDefaultReloadTime;
extern NSInteger const OxAdConfigDefaultTimeout;
extern NSInteger const OxAdConfigDefaultMemoryLimit;
extern NSInteger const OxAdConfigDefaultWeight;
extern NSInteger const OxAdConfigDefaultInvalidTimeout;
extern BOOL const OxAdConfigDefaultIdEnable;
extern BOOL const OxAdConfigDefaultDisabledCache;
extern BOOL const OxAdConfigDefaultDisabledRetry;
extern double const OxAdConfigDefaultDynamic;
extern NSInteger const OxAdConfigDefaultApsType;
extern NSInteger const OxAdConfigDefaultFactor;
extern NSInteger const OxAdConfigDefaultDepthUserLevel;
extern NSInteger const OxAdConfigDefaultShowStartLevelDaily;

+ (NSString *)normalizeAdFormat:(NSString *)adFormat;

@end

NS_ASSUME_NONNULL_END
