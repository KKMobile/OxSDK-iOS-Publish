//
//  IOxOrder.h
//  Pods
//
//  Created by Mavl_2023_100272 on 2025/1/21.
//

@protocol IOxOrder <NSObject>

- (void)setup;

- (float)getEcpm:(NSString *)adUnitId;

- (void)handleEcpm:(float)ecpm adUnitId:(NSString *)adUnitId;

@end
