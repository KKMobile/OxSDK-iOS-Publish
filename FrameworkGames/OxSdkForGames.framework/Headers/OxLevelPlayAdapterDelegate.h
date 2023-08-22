//
//  OxLevelPlayAdapterDelegate.h
//  OxSdkForGames
//
//  Created by Mavl_2023_100272 on 2023/8/18.
//

#import <Foundation/Foundation.h>

@import IronSource;

@protocol OxLevelPlayAdapterDelegate <NSObject>

- (void)OxLevelPlayDidload:(ISAdInfo *)adInfo;
- (void)OxLevelPlayDidFailToLoad:(NSError*)error;
- (void)OxLevelPlayDidShow:(ISAdInfo *)adInfo;
- (void)OxLevelPlayDidClick:(ISAdInfo *)adInfo;
- (void)OxLevelPlayDidClose:(ISAdInfo *)adInfo;
- (void)OxLevelPlayDidFailToShow:(NSError *)error andAdInfo:(ISAdInfo *)adInfo;

@optional
- (void)OxLevelPlayDidReceiveReward:(ISPlacementInfo *)placementInfo withAdInfo:(ISAdInfo *)adInfo;

@end


@protocol OxLevelPlayBannerAdapterDelegate <NSObject>

- (void)OxLevelPlayBannerDidload:(ISBannerView *)bannerView andAdInfo:(ISAdInfo *)adInfo;
- (void)OxLevelPlayDidFailToLoad:(NSError*)error;
- (void)OxLevelPlayDidShow:(ISAdInfo *)adInfo;
- (void)OxLevelPlayDidClick:(ISAdInfo *)adInfo;

@end
