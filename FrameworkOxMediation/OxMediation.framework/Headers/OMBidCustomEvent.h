// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#ifndef OMBidCustomEvent_h
#define OMBidCustomEvent_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OMCustomEventDelegate.h"
#import "OMInstanceContainer.h"


NS_ASSUME_NONNULL_BEGIN

@protocol OMBidCustomEventDelegate <OMCustomEventDelegate>

@optional
- (void)bidReseponse:(NSObject*)bidAdapter bid:(nullable NSDictionary*)bidInfo error:(nullable NSError*)error;

@end

@class OMBidNetworkItem;

@protocol OMBidCustomEvent <NSObject>

@optional

+ (void)bidWithNetworkItem:(OMBidNetworkItem*)networkItem adFormat:(NSString*)format adSize:(CGSize)size instanceContainer:(OMInstanceContainer *)instanceContainer localExtraParameter:(NSDictionary<NSString *,id> *)localExtraParameter responseCallback:(void(^)(NSDictionary *bidResponseData))callback;
+ (NSString*)bidderToken;
@end

NS_ASSUME_NONNULL_END

#endif /* OMBidCustomEvent_h */
