//
//  IOnConfigChangedListener.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class AdUnitBaseConfig, IdConfig;

NS_ASSUME_NONNULL_BEGIN

@protocol IOnConfigChangedListener <NSObject>
- (void)onConfigChanged:(nullable AdUnitBaseConfig *)newAdUnitConfig idConfigs:(NSArray<IdConfig *> *)newIdConfigs;
@end

NS_ASSUME_NONNULL_END
