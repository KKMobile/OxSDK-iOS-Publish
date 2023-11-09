//
//  OxPrefManager.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/5.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxPrefManager : NSObject

+ (nonnull instancetype)sharedInstance;

// 1 Google UMP  0 Max
@property (nonatomic,assign) int gdprTool;

@end

NS_ASSUME_NONNULL_END
