//
//  OxRewardedPrivate.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2025/2/12.
//

#import <Foundation/Foundation.h>

@interface OxRewardedAdHelper()

@property (nonatomic, assign) NSInteger retryAttempt;
@property (nonatomic, assign) BOOL mReload;
@property (nonatomic, assign) BOOL mIsReloadingInLoadFailed;
@property (nonatomic, assign) BOOL mIsReloadingInDisplayFailed;
@property (nonatomic, strong) NSArray<NSString *> *mAdunitIds;  // 存储多个广告位ID
@property (nonatomic, assign) NSInteger currentAdUnitIndex;  // 当前请求的广告位ID索引

@end
