#import <Foundation/Foundation.h>
#import <PAGAdSDK/PAGAdSDK.h>
@interface PangleAdUtils : NSObject
+ (double)getRevenue:(id<PAGAdProtocol>)ad;
+ (void)notifyWin:(id<PAGAdClientBiddingProtocol>)ad revenue:(double)revenue;
+ (void)notifyLoss:(id<PAGAdClientBiddingProtocol>)ad revenue:(double)revenue dynamic:(double)dynamic;
@end
