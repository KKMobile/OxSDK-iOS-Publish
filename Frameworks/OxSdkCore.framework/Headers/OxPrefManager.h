//
//  OxPrefManager.h
//  OxSDK-Game
//
//  Created by Mavl_2023_100272 on 2023/6/5.
//

#import <Foundation/Foundation.h>
#import "AdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@interface OxPrefManager : NSObject

+ (nonnull instancetype)sharedInstance;

// 1 Google UMP  2 SFBX
@property (nonatomic,assign) NSInteger gdprTool;
@property (nonatomic,assign) NSInteger core_level;
@property (nonatomic,assign) BOOL isUnityAdsGdprSet;
@property (nonatomic,assign) BOOL isPrefMigrated;
@property (nonatomic,assign) OxSdkMediationType mediationType;
@property (nonatomic,assign) long last_load_timestamp;
@property (nonatomic,copy) NSString *keywords_json;
@property (nonatomic,assign) float lifetime_ad_ltv;

- (void)addEventCount:(NSString *)eventName;
- (NSInteger)getEventCount:(NSString *)eventName;


@end

NS_ASSUME_NONNULL_END
