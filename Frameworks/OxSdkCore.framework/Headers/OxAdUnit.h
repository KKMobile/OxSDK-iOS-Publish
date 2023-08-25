//
//  OxAdUnitIds.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/5/31.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdUnit : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) OxSdkAdFormat adFormat;
@property (nonatomic,assign) OxSdkMediationType mediationType;
@property (nonatomic, strong) NSArray<NSString *> *maxAdUnitIds;
@property (nonatomic, strong) NSArray<NSString *> *admobAdUnitIds;
@property (nonatomic, strong) NSArray<NSString *> *omAdUnitIds;

- (NSString *)getTargetAdUnitId:(OxSdkMediationType)mediationType;
- (OxSdkMediationType)getTargetMediation;

@end


NS_ASSUME_NONNULL_END
