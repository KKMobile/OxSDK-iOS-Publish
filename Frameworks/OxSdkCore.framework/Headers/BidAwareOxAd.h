#import <Foundation/Foundation.h>
/// Every load first bids; the weight group settles before loading its single winning creative.
/// Revenue is USD per impression, matching OxAd.getRevenue.
@protocol BidAwareOxAd <NSObject>
- (void)requestBidWithCompletion:(void (^)(double revenue, NSString *error))completion;
- (void)notifyBidWin:(double)clearingRevenue;
- (void)notifyBidLoss:(double)winningRevenue;
@end
