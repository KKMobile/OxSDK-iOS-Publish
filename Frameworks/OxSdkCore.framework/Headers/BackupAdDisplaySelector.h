#import <Foundation/Foundation.h>
@class OxAd;
@interface BackupAdSelection : NSObject
@property (nonatomic, strong) OxAd *ad;
@property (nonatomic) BOOL fromBackup;
@end
@interface BackupAdDisplaySelector : NSObject
+ (BackupAdSelection *)select:(NSString *)strategy mediation:(NSString *)mediation mainAds:(NSArray<OxAd *> *)mainAds backupAds:(NSArray<OxAd *> *)backupAds;
@end
