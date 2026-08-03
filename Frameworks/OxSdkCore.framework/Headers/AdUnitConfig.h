//
//  AdUnitConfig.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

#import "AdUnitBaseConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdUnitConfig : NSObject

@property (nonatomic, copy) NSString * unitName;
@property (nonatomic, strong) AdUnitBaseConfig * baseConfig;

- (instancetype)initWithUnitName:(NSString *)unitName baseConfig:(AdUnitBaseConfig *)baseConfig;

@end

NS_ASSUME_NONNULL_END
