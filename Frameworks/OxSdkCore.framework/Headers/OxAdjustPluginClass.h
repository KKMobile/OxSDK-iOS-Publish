//
//  OxAdjustPluginClass.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2023/6/12.
//  Copyright © 2023 耿志向. All rights reserved.
//

#ifndef OxAdjustPluginClass_h
#define OxAdjustPluginClass_h

NS_ASSUME_NONNULL_BEGIN

@protocol OxAdjustDelegate <NSObject>

- (NSDictionary<NSString *,NSString *> *)getAdjustTokens;

@end

@interface OxAdjust : NSObject

- (void)setAdjustDelegate:(id<OxAdjustDelegate>)delegate;

+ (nonnull instancetype)sharedInstance;

- (void)trackEvent:(NSString *)eventName params:(nullable NSDictionary *)params;
- (void)trackDMA:(BOOL)isSubjectToGDPR granted:(BOOL)granted;

@end

NS_ASSUME_NONNULL_END


#endif /* OxAdjustPluginClass_h */
