//
//  OxDynamicIDConfig.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2026/1/22.
//  Copyright © 2026 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxDynamicIDConfig : NSObject

@property (nonatomic, copy) NSString *mId;
@property (nonatomic, assign) float ratio;

- (instancetype)initWithId:(NSString *)mId ratio:(float)ratio;
- (NSString *)description;

@end

NS_ASSUME_NONNULL_END
