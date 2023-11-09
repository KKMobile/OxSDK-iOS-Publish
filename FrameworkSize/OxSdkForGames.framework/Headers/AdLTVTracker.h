//
//  AdLTVTracker.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/7/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdLTVTracker : NSObject

+ (void)addAdValue:(double)value;

+ (double)getLtAdValue;


@end

NS_ASSUME_NONNULL_END
