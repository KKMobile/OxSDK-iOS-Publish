// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>

#define MaxMultiCallTAG @"MaxMultiCall"

#define CURRENT_CLASS_NAME \
    ({ \
        NSString *file = [NSString stringWithUTF8String:__FILE__]; \
        [file stringByDeletingPathExtension].lastPathComponent; \
    })

//Verbose
#define OXLogV(...) [OXLogMoudle logLevel:OXLogLevelV tag:@"" className:CURRENT_CLASS_NAME logString:__VA_ARGS__]

//Debug
#define OXLogD(...) [OXLogMoudle logLevel:OXLogLevelD tag:@"" className:CURRENT_CLASS_NAME logString:__VA_ARGS__]

//Info
#define OXLogI(...) [OXLogMoudle logLevel:OXLogLevelI tag:@"" className:CURRENT_CLASS_NAME logString:__VA_ARGS__]

//Warning
#define OXLogW(...) [OXLogMoudle logLevel:OXLogLevelW tag:@"" className:CURRENT_CLASS_NAME logString:__VA_ARGS__]

//Error
#define OXLogE(...) [OXLogMoudle logLevel:OXLogLevelE tag:@"" className:CURRENT_CLASS_NAME logString:__VA_ARGS__]


//Verbose
#define OXLogTAGV(_tag, ...) [OXLogMoudle logLevel:OXLogLevelV tag:_tag className:CURRENT_CLASS_NAME logString:__VA_ARGS__]

//Debug
#define OXLogTAGD(_tag, ...) [OXLogMoudle logLevel:OXLogLevelD tag:_tag className:CURRENT_CLASS_NAME logString:__VA_ARGS__]

//Info
#define OXLogTAGI(_tag, ...) [OXLogMoudle logLevel:OXLogLevelI tag:_tag className:CURRENT_CLASS_NAME logString:__VA_ARGS__]

//Warning
#define OXLogTAGW(_tag, ...) [OXLogMoudle logLevel:OXLogLevelW tag:_tag className:CURRENT_CLASS_NAME logString:__VA_ARGS__]

//Error
#define OXLogTAGE(format, ...) [OXLogMoudle logLevel:OXLogLevelE tag:_tag className:CURRENT_CLASS_NAME logString:__VA_ARGS__]



NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, OXLogLevel) {
    OXLogLevelV = 0,    //Verbose
    OXLogLevelD = 1,    //Debug
    OXLogLevelI = 2,    //Info
    OXLogLevelW = 3,    //Warning
    OXLogLevelE = 4,    //Error
    OXLogLevelN = 5,    //close
};


@interface OXLogMoudle : NSObject

+ (void)openLog:(BOOL)open;
+ (void)setDebugMode;
+ (void)setVerboseMode;

+ (void)logLevel:(OXLogLevel)level tag:(NSString *)tag className:(NSString *)className logString:(NSString *)logString, ... NS_FORMAT_FUNCTION(4, 5);

@end

NS_ASSUME_NONNULL_END
