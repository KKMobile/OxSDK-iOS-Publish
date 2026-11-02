//
//  AdapterConfig.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

#import "AdNetworkConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdapterConfig : NSObject

@property (nonatomic, strong) AdNetworkConfig * admob;
@property (nonatomic, strong) AdNetworkConfig * max;

@end

NS_ASSUME_NONNULL_END
