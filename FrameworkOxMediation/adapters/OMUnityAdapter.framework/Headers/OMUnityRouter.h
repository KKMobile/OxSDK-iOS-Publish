// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <UIKit/UIKit.h>

#import "OMMediationAdapter.h"
#import "OMUnityClass.h"

NS_ASSUME_NONNULL_BEGIN

@protocol OMUnityAdapterDelegate <NSObject>

- (void)omUnityDidload;
- (void)omUnityDidFailToLoad:(NSError*)error;
- (void)omUnityDidStart;
- (void)omUnityDidClick;
- (void)omUnityDidFinish:(BOOL)skipped;
- (void)omUnityFailToShow:(NSError *)error;
@optional
- (void)omUnityRewardedVideoEnd;

@end

@interface OMUnityRouter : NSObject<UnityAdsLoadDelegate,UnityAdsShowDelegate>
@property (nonatomic, strong) NSMapTable *placementDelegateMap;

+ (instancetype)sharedInstance;
- (void)registerPidDelegate:(NSString*)pid delegate:(id)delegate;
- (void)loadPlacmentID:(NSString *)pid;
- (void)showVideo:(NSString *)pid withVC:(UIViewController*)vc;
- (BOOL)isCanLoad:(id)adpter pid:(NSString *)pid;

@end

NS_ASSUME_NONNULL_END
