//
//  AdConfigChangeBus.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
@class AdConfig;
@class ConfigSegment;
@protocol OxAdConfigChangeListener;

NS_ASSUME_NONNULL_BEGIN

@interface AdConfigChangeBus : NSObject
- (instancetype)init;
- (void)addListener:(id<OxAdConfigChangeListener>)listener;
- (void)removeListener:(id<OxAdConfigChangeListener>)listener;
- (void)clearListeners;
- (void)dispatchWithMatchedSegment:(nullable ConfigSegment *)matchedSegment mergedConfig:(AdConfig *)mergedConfig;
@end

NS_ASSUME_NONNULL_END
