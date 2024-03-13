//
//  OxadUnit.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/5/31.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxAdUnit : NSObject

@property (nonatomic, copy) NSString* adUnitName;
@property (nonatomic, assign) Platform mediation; // 弃用
@property (nonatomic, copy) NSString* maxAdUnitId;
@property (nonatomic, copy) NSString* admobAdUnitId;


+ (OxAdUnit *)OxAdUnitWithAdmobAdUnitId:(NSString *)admobAdUnitId maxAdUnitId:(NSString *)maxAdUnitId adUnitName:(NSString *)adUnitName;

+ (OxAdUnit *)OxAdUnitWithAdmobAdUnitId:(NSString *)admobAdUnitId maxAdUnitId:(NSString *)maxAdUnitId adUnitName:(NSString *)adUnitName meidation:(Platform)mediation;

- (Platform)getTargetMediation;

@end

NS_ASSUME_NONNULL_END
