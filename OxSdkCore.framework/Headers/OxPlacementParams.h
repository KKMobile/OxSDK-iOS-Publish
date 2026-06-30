//
//  OxPlacementParams.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class AdUnitBaseConfig;

NS_ASSUME_NONNULL_BEGIN

@interface OxPlacementParams : NSObject

@property (nonatomic, copy, readonly) NSString *mAdFormat;
@property (nonatomic, copy, readonly) NSString *mAdUnitName;

@property (nonatomic, assign) long long mRequestTag;
@property (nonatomic, assign) long long mRequestTimestamp;

@property (nonatomic, copy, nullable) NSString *mLoadError;
@property (nonatomic, assign) double mFloorRevenue;

@property (nonatomic, copy, nullable) NSString *mShowPlacement;
@property (nonatomic, copy, nullable) NSString *mPlacement;

@property (nonatomic, assign) long long mLastShowFailedTimestamp;
@property (nonatomic, assign) BOOL mIsReady;
@property (nonatomic, copy, nullable) NSString *mErrorCode;
@property (nonatomic, assign) BOOL mIsLoadFailRetry;

@property (nonatomic, assign) long long mShowingTimestamp;
@property (nonatomic, copy, nullable) NSString *mShowFailError;

@property (nonatomic, copy, nullable) NSString *mAdStatus;
@property (nonatomic, assign) BOOL mIsReload;
@property (nonatomic, strong, nullable) AdUnitBaseConfig *adUnitConfig;
@property (nonatomic, copy, nullable) NSString *mAdUserValueConfig;

- (instancetype)initWithAdFormat:(NSString *)adFormat adUnitName:(NSString *)adUnitName;

- (void)setLoadInfoWithReload:(BOOL)isReload;
- (void)setLoadedInfoWithErrorCode:(nullable NSString *)errorCode
                             error:(nullable NSString *)error
                          adStatus:(nullable NSString *)adStatus;
- (void)setAdDisplayInfo;
- (void)setAdShowInfoWithReady:(BOOL)ready loadFailRetry:(BOOL)loadFailRetry;

- (long long)getLastShowFailedDuration;
- (long long)getLoadFailedDuration;
- (long long)getShowingDuration;

@end

NS_ASSUME_NONNULL_END
