//
//  IntervalConfig.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IntervalConfig : NSObject

@property (nonatomic, assign) NSInteger intervalTime;
@property (nonatomic, assign) NSInteger intervalType;
@property (nonatomic, assign) NSInteger group;

@end

NS_ASSUME_NONNULL_END
