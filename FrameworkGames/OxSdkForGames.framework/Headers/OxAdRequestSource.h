//
//  OxAdRequestSource.h
//  OxSDK-Game
//
//  Created by 耿志向 on 2023/4/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxAdRequestSource : NSObject

extern NSString* const APP_LOAD;
extern NSString* const APP_LOAD_HAS_CACHE;
extern NSString* const APP_LOAD_NO_CACHE;
extern NSString* const AD_SHOWING;
extern NSString* const ON_AD_FAILED_TO_LOAD;
extern NSString* const ON_AD_FAILED_TO_SHOW;
extern NSString* const WHEN_NETWORK_IS_AVAILABLE;

@end

NS_ASSUME_NONNULL_END
