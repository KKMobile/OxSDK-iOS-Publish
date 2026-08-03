//
//  IAdLoadCallback.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IAdLoadCallback <NSObject>

- (NSString *)getAdUnitName;
- (BOOL)isReady;

@end

NS_ASSUME_NONNULL_END
