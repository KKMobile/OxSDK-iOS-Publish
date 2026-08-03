//
//  BaseTaskController.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

@class OxAd;

NS_ASSUME_NONNULL_BEGIN

@interface OxRunnableTask : NSObject

- (instancetype)initWithAd:(OxAd *)ad;

@property (nonatomic, strong, readonly) OxAd *ad;
@property (nonatomic, assign, readonly) NSTimeInterval timeoutMillis;
@property (nonatomic, assign, readonly) NSInteger weight;

@end

@protocol OxTaskCallback <NSObject>
- (void)onSuccess:(OxAd *)ad;
- (void)onFailure:(OxAd *)ad error:(nullable NSString *)error;
- (void)onAllTasksFinished:(nullable OxAd *)ad msg:(NSString *)msg;
@end

@interface BaseTaskController : NSObject

- (instancetype)initWithMaxConcurrent:(NSInteger)maxConcurrent;
- (void)executeTasks:(NSArray<OxRunnableTask *> *)tasks callback:(id<OxTaskCallback>)callback;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
