//
//  AdEventDelegate.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/6/24.
//

#ifndef AdEventDelegate_h
#define AdEventDelegate_h
#import "OxAdjustTokens.h"

@protocol AdEventDelegate<NSObject>

- (OxAdjustTokens *)getAdjustTokens;

- (NSArray *)getTopValuesConfig;

@optional

- (int)getEventLevel;

- (int)getDeepUserLevel;

- (int)getAllowedKeywordType;

- (double)getAdLtvMedium;

- (double)getAdLtvHigh;

@end

#endif /* AdEventDelegate_h */
