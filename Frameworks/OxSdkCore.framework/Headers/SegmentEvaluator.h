//
//  SegmentEvaluator.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>
@class ConfigSegment;

NS_ASSUME_NONNULL_BEGIN

@interface SegmentEvaluator : NSObject
- (nullable ConfigSegment *)findFirstMatchedSegment:(NSArray<ConfigSegment *> *)segments;
- (NSSet<NSString *> *)collectVariableRuleTypes:(NSArray<ConfigSegment *> *)segments;
@end

NS_ASSUME_NONNULL_END
