#import <Foundation/Foundation.h>
@class IdConfig;
FOUNDATION_EXPORT NSString * const OxBackupInitSDK;
FOUNDATION_EXPORT NSString * const OxBackupLoadFail;
FOUNDATION_EXPORT NSString * const OxBackupShowFail;
@interface BackupAdLoadTiming : NSObject
+ (NSString *)resolve:(IdConfig *)config;
+ (BOOL)matches:(IdConfig *)config timing:(NSString *)timing placement:(NSString *)placement;
+ (BOOL)isBackupAdUnitName:(NSString *)name;
@end
