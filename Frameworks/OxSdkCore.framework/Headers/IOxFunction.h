//
//  IOxFunction.h
//  Pods
//
//  Created by Mavl_2023_100272 on 2025/1/21.
//
#import <Foundation/Foundation.h>

@protocol IOxFunction <NSObject>

- (void)handleEcpm:(float)ecpm
          adUnitId:(NSString *)adUnitId
          isPeriod:(BOOL)isPeriod
          newCount:(int)newCount
           newEcpm:(float)newEcpm;

@end
