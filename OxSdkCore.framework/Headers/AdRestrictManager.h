//
//  AdRestrictManager.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdRestrictManager : NSObject

+ (instancetype)sharedInstance;

- (void)initRestrict;
- (void)parseConfigByFirebase;

- (BOOL)getInitRestrict;
- (BOOL)getLoadRestrict:(NSString *)adFormat;
- (BOOL)getShowRestrict:(NSString *)adFormat;

@end

NS_ASSUME_NONNULL_END
