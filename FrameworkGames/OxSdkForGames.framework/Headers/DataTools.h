//
//  DataTools.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/21.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@interface DataTools : NSObject

+(nonnull instancetype)utilShareInstance;

- (void)saveMediationPlatform:(Platform)platform;

- (Platform)getMediationPlatform;

@end

NS_ASSUME_NONNULL_END
