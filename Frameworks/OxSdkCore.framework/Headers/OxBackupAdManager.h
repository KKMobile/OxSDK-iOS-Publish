#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class OxAdManager, OxAd, OxNativeViewBinder;
@interface OxBackupAdManager : NSObject
+ (instancetype)sharedInstance;
- (void)loadAfterSdkInitialization;
- (void)loadFormat:(NSString *)format viewController:(UIViewController *)vc viewBinder:(OxNativeViewBinder *)binder timing:(NSString *)timing placement:(NSString *)placement;
- (NSArray<OxAd *> *)readyAdsForFormat:(NSString *)format viewController:(UIViewController *)vc viewBinder:(OxNativeViewBinder *)binder;
- (OxAdManager *)ownerOfAd:(OxAd *)ad format:(NSString *)format viewController:(UIViewController *)vc viewBinder:(OxNativeViewBinder *)binder;
@end
