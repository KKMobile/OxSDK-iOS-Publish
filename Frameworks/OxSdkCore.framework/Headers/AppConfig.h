//
//  AppConfig.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

#import "AppUserValueConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface AppConfig : NSObject

@property (nonatomic, copy) NSString * packageName;
@property (nonatomic, copy) NSString * version;
@property (nonatomic, copy) NSString * mediation;
@property (nonatomic, assign) NSInteger daysOfNewUser;
@property (nonatomic, assign) NSInteger depthUserLevel;
@property (nonatomic, assign) NSInteger eventLevel;
@property (nonatomic, assign) NSInteger geoConsent;
@property (nonatomic, strong) AppUserValueConfig * userValue;

@end

NS_ASSUME_NONNULL_END
