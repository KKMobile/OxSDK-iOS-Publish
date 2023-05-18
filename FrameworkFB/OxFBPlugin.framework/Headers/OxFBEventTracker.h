//
//  OxFBEventTracker.h
//  OxFBPlugin
//
//  Created by 耿志向 on 2023/5/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxFBEventTracker : NSObject

+ (nonnull instancetype)sharedInstance;

- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
