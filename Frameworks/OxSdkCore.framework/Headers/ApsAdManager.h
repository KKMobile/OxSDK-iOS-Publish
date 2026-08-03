//
//  ApsAdManager.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/20.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"
NS_ASSUME_NONNULL_BEGIN

@interface ApsAdManager : NSObject

@property(nonatomic, assign, readonly) BOOL isReady;

+ (nonnull instancetype)sharedInstance;

- (void)initApsSdk;

- (void)enableApsDebug:(BOOL)enable;

- (NSString *)getApsAppId;

@end

NS_ASSUME_NONNULL_END
