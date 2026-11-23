#import <Foundation/Foundation.h>
@interface FacebookAnBidSession : NSObject
@property (nonatomic, copy, readonly) NSString *creative;
- (instancetype)initWithPlacement:(NSString *)placement format:(NSString *)format timeout:(NSTimeInterval)timeout floorCPM:(double)floor;
- (NSString *)getAuctionId;
- (void)bid:(void (^)(double revenue, NSString *error))completion;
- (void)notifyWin:(double)clearingRevenue;
- (void)notifyLoss:(double)winningRevenue;
- (void)cancel;
@end
