//
//  OxNativeAdInfo.h
//  oxsdk_flutter
//
//  Created by Mavl_2023_100272 on 2025/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxNativeAdInfo : NSObject

@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *advertiser;
@property(nonatomic, strong) NSString *body;
@property(nonatomic, strong) NSString *callToAction;
@property(nonatomic, strong) NSString *store;
@property(nonatomic, strong) NSString *price;
@property(nonatomic, strong) NSNumber *starRating;

- (NSDictionary *)map;


@end

NS_ASSUME_NONNULL_END
