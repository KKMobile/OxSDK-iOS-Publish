//
//  OxSaveLogTool.h
//  OxDebugLib
//
//  Created by Mavl_2023_100272 on 2024/7/25.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OxSaveLogTool : NSObject
/// 保存日志文件
+ (void)redirectNSLogToDocumentFolder;

+ (NSString *)readFromLogFile;

+(void)removeLogFile;

//+(void)freOpenLogToConsole;
@end
