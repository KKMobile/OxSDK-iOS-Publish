// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>

//Verbose
#define OXLogV(format, ...) [OXLogMoudle logV:format,##__VA_ARGS__];

//Debug
#define OXLogD(format, ...) [OXLogMoudle logD:format,##__VA_ARGS__];

//Info
#define OXLogI(format, ...) [OXLogMoudle logI:format,##__VA_ARGS__];

//Warning
#define OXLogW(format, ...) [OXLogMoudle logW:format,##__VA_ARGS__];

//Error
#define OXLogE(format, ...) [OXLogMoudle logE:format,##__VA_ARGS__];

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
+ (void)logV:(NSString *)format, ...NS_FORMAT_FUNCTION(1,2);
+ (void)logD:(NSString *)format, ...NS_FORMAT_FUNCTION(1,2);
+ (void)logI:(NSString *)format, ...NS_FORMAT_FUNCTION(1,2);
+ (void)logW:(NSString *)format, ...NS_FORMAT_FUNCTION(1,2);
+ (void)logE:(NSString *)format, ...NS_FORMAT_FUNCTION(1,2);

@end

NS_ASSUME_NONNULL_END
