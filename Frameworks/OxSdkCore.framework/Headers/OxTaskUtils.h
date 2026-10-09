//
//  OxTaskUtils.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class OxRunnableTask;

NS_ASSUME_NONNULL_BEGIN

@interface OxTaskUtils : NSObject

+ (NSArray<NSArray<OxRunnableTask *> *> *)stagesGroupedByWeight:(NSArray<OxRunnableTask *> *)tasks;

@end

NS_ASSUME_NONNULL_END
