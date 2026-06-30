//
//  OxUserValueModel.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2025/5/21.
//  Copyright © 2025 耿志向. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class OxUserValueRange;

@interface OxUserValueModel : NSObject

- (instancetype)initWithJson:(NSString *)jsonString;

@property (nonatomic, strong) NSArray<OxUserValueRange *> *mRanges;

@end

@interface OxUserValueRange : NSObject

@property (nonatomic, assign) float mWaterfallValue;
@property (nonatomic, strong) NSString *mSegmentValue;

@end


NS_ASSUME_NONNULL_END
