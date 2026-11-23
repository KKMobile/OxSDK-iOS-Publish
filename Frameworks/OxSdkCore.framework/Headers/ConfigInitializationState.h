#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ConfigInitializationStateValue) {
    ConfigInitializationStateNotStarted,
    ConfigInitializationStateLoading,
    ConfigInitializationStateReady,
    ConfigInitializationStateFailed,
};

/// Android ConfigInitializationState.Request；Objective-C 无嵌套类型。
@interface ConfigInitializationRequest : NSObject
@property (nonatomic, readonly) NSUInteger generation;
@property (nonatomic, readonly) BOOL startLoad;
@property (nonatomic, readonly) BOOL ready;
@end

/// 配置初始化轮次与等待者。复合操作由调用方持有本对象的锁。
@interface ConfigInitializationState : NSObject
- (ConfigInitializationRequest *)request:(nullable id)listener;
- (nullable NSArray *)complete:(NSUInteger)expectedGeneration success:(BOOL)success;
- (BOOL)isLoading:(NSUInteger)expectedGeneration;
- (ConfigInitializationStateValue)getState;
- (BOOL)isReleased;
/// Android release；避免与 NSObject 的手动引用计数 selector 冲突。
- (void)releaseState;
@end

NS_ASSUME_NONNULL_END
