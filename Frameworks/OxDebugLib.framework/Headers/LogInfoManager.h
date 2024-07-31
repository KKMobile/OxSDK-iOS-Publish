//
//  LogInfoManager.h
//  ilopTest
//  OxDebugLib
//
//  Created by Mavl_2023_100272 on 2024/7/25.
//  Copyright © 2024 耿志向. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define OxDebugLib_SDK_VERSION    @"1.0.1-202407311500"

@class LogViewController;
@interface LogInfoManager : NSObject

+(instancetype)shareInstance;

-(void)start;
    
+(UIImage *)getImageWithName:(NSString *)name;
@end
