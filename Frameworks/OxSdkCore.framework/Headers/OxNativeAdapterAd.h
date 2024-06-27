//
//  OxNativeAd.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2024/6/18.
//  Copyright © 2024 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxNativeAdapterAd : NSObject

@property(nonatomic, strong) id nativeLoader;
@property(nonatomic, strong) id nativeAd;

@end

NS_ASSUME_NONNULL_END
