//
//  OxFBEventUtil.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2024/3/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxFBEventUtil : NSObject

+ (void)trackEventFB:(NSString *)eventName params:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
