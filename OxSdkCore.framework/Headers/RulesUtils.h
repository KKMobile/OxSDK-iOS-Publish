//
//  RulesUtils.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RulesUtils : NSObject

+ (NSString *)getVersionName;
+ (NSString *)getChannel;
+ (NSString *)getCampaign;
+ (NSInteger)getInstallDays;
+ (NSInteger)getInstallHours;
+ (NSString *)getDeviceModel;
+ (NSString *)getCustomValue;
+ (NSInteger)getPassLevels;
+ (double)getPlayMinutes;
+ (double)getPayCounts;
+ (double)getRam;
+ (double)getRom;
+ (NSString *)getGameCoreValue;
+ (NSString *)getMemoryControlValue;

@end

NS_ASSUME_NONNULL_END
