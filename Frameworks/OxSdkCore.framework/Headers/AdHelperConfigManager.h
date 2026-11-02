//
//  AdHelperConfigManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "IOnConfigChangedListener.h"

@class IdConfig, AdUnitBaseConfig, OxPlacementParams, OxStrategy;

NS_ASSUME_NONNULL_BEGIN

@interface AdHelperConfigManager : NSObject

- (instancetype)initWithViewController:(nullable UIViewController *)viewController
                            oxStrategy:(OxStrategy *)oxStrategy
                             adUnitIds:(nullable NSMutableArray<IdConfig *> *)adUnitIds
                          adUnitConfig:(nullable AdUnitBaseConfig *)adUnitConfig
                    oxPlacementParams:(OxPlacementParams *)oxPlacementParams
                        isByAdUnitName:(BOOL)isByAdUnitName;

- (void)initializeFromAdUnitConfig;
- (void)reinitialize;
- (void)releaseManager;

- (NSArray<IdConfig *> *)adUnitIds;
- (nullable NSString *)adUnitIdAtIndex:(NSInteger)index;
- (nullable AdUnitBaseConfig *)adUnitConfig;
- (OxPlacementParams *)oxPlacementParams;
- (nullable NSString *)floorID;
- (NSArray<NSString *> *)dynamicIDs;
- (NSString *)adUnitName;
- (NSString *)adFormat;
- (BOOL)isDynamicEnabled;

@property (nonatomic, weak, nullable) id<IOnConfigChangedListener> onConfigChangedListener;

@end

NS_ASSUME_NONNULL_END
