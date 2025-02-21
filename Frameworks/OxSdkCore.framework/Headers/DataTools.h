//
//  DataTools.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DataTools : NSObject

+(nonnull instancetype)utilShareInstance;

- (void)saveMediationPlatform:(NSInteger)platform;

- (NSInteger)getMediationPlatform;

@end

NS_ASSUME_NONNULL_END
