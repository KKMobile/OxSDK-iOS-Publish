//
//  OxAdUnitIds.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/5/31.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@class OxAdUnitIds;

@interface OxAdUnit : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) OxSdkAdFormat adFormat;
@property (nonatomic,assign) OxSdkMediationType mediationType;
@property (nonatomic, strong) OxAdUnitIds *adUnitIds;

- (NSString *)getTargetAdUnitId:(OxSdkMediationType)mediationType;
- (OxSdkMediationType)getTargetMediation;

@end

@interface  OxAdUnitIds : NSObject

@property (nonatomic, copy) NSString *max;
@property (nonatomic, copy) NSString *admob;

@end


NS_ASSUME_NONNULL_END
