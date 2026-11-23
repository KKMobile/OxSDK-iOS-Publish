//
//  PostBiddingTaskController.h
//  OxSdkCore
//

#import "BaseTaskController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 这个类负责安排：先请求哪层广告、后请求哪层广告、下一层参考多少钱。

 weight 大的层先请求。每层看完价格，把目前最高的参考价传给下一层。
 有的广告先报价，再真正加载广告。报价赢了，就可以先把价格传下去，广告继续加载。
 同层怎么比价、谁赢了去加载，由 BidAwareStageResolver 处理；这里负责一层接一层地往下走。
 */
@interface PostBiddingTaskController : BaseTaskController
@end

NS_ASSUME_NONNULL_END
