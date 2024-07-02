//
//  OxRemoteConfig.h
//  Adjust
//
//  Created by Mavl_2023_100272 on 2024/7/2.
//

#import <Foundation/Foundation.h>
#import "IRemoteConfig.h"

typedef enum : NSUInteger {
    OxRemoteConfigTypeFirebase,
    OxRemoteConfigTypeUrl
} OxRemoteConfigType;

NS_ASSUME_NONNULL_BEGIN

@interface OxRemoteConfig : NSObject <IRemoteConfig>

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
