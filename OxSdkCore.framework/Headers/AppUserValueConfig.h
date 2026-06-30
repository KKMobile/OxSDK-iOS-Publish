//
//  AppUserValueConfig.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppUserValueConfig : NSObject

@property (nonatomic, copy) NSString * order;
@property (nonatomic, copy) NSString * version;
@property (nonatomic, copy) NSString * function;
@property (nonatomic, copy) NSString * duration;
@property (nonatomic, copy) NSString * quantity;
@property (nonatomic, assign) double summary;
@property (nonatomic, assign) NSInteger factor;

@end

NS_ASSUME_NONNULL_END
