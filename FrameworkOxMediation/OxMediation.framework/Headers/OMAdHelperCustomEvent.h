//
//  OMAdHelper.h
//  OxMediation
//
//  Created by 耿志向 on 2023/3/27.
//  Copyright © 2023 AdTiming. All rights reserved.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol OMAdHelperCustomEvent <NSObject>

- (void)setLocalExtraParameter:(id)object key:(NSString *)key;
- (NSString *)getNetworkName;

@end

NS_ASSUME_NONNULL_END
