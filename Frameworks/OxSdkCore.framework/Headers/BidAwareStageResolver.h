#import "BaseTaskController.h"

NS_ASSUME_NONNULL_BEGIN
/** 这一层的比价和加载结果。这里的价格都是单次收入，乘 1000 才是 CPM。 */
@interface StageResult : NSObject
/// 有没有报价真正赢了。赢了只表示接下来可以加载它，不表示广告已经能展示。
@property (nonatomic, readonly) BOOL hasBidWinner;
/// 赢了的那个报价；没有报价赢时保持默认值 0。
@property (nonatomic, readonly) double winningBidRevenue;
/// 这一层普通广告加载成功后，拿到的最高价格。
@property (nonatomic, readonly) double highestOrdinaryRevenue;
/// 这一层新加载成功的广告中，最高的价格；赢了报价的广告加载成功后也会计入。
@property (nonatomic, readonly) double highestLoadedRevenue;
/// 这一层有没有新加载成功的广告，不包含调用方单独保留的旧缓存。
@property (nonatomic, readonly) BOOL hasLoadedAd;
/// 报价需要超过的价格：传进来的参考价，与这一层普通广告最高价，取更高的。
/// 有报价赢时，这个价格也会传给 notifyBidWin；它不是赢家自己的报价。
@property (nonatomic, readonly) double clearingRevenue;
/// 下面四个方法分别读取上面对应的价格，方便其他调用方式使用。
- (double)getWinningBidRevenue;
- (double)getHighestOrdinaryRevenue;
- (double)getHighestLoadedRevenue;
- (double)getClearingRevenue;
@end

/// 调用方提供的“真正发起广告加载”的方法：传入任务，加载结果交给 callback。
typedef void (^TaskExecutor)(NSArray<OxRunnableTask *> *, id<OxTaskCallback>);

@interface BidAwareStageResolver : NSObject
/**
 tasks：这一层需要处理的任务。
 floorRevenue：调用方传入的参考价，通常已经比较过前层价格和本层缓存价格。
 executor：需要真正加载广告时，调用它。
 callback：把各路广告的成功或失败告诉外面。
 isValid：外面告诉我们这一轮还要不要继续；取消或销毁后就忽略旧结果。
 settled / finished：分别表示“比完价格”和“这一层全部处理完”。
 */
+ (void)execute:(NSArray<OxRunnableTask *> *)tasks
  floorRevenue:(double)floorRevenue
      executor:(TaskExecutor)executor
      callback:(id<OxTaskCallback>)callback
       isValid:(BOOL (^)(void))isValid
onStageSettled:(void (^)(StageResult *))settled
onStageFinished:(void (^)(StageResult *))finished;
@end
NS_ASSUME_NONNULL_END
