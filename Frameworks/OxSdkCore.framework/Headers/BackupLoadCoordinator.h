#import <Foundation/Foundation.h>
@class OxAdManager;

NS_ASSUME_NONNULL_BEGIN
/// Serializes loads and resumes only requests authorized by a matching backup trigger.
@interface BackupLoadCoordinator : NSObject
- (instancetype)initWithBackupAd:(OxAdManager *)backupAd;
- (BOOL)isFor:(OxAdManager *)backupAd;
- (void)requestLoad:(NSString *)loadTiming;
- (void)onNetworkChanged:(BOOL)connected;
@end
NS_ASSUME_NONNULL_END
