// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OMRewardedVideoDelegate.h"

NS_ASSUME_NONNULL_BEGIN
@interface OMRewardedVideo : NSObject

@property (nonatomic, weak)id<OMRewardedVideoDelegate> delegate;
@property (nonatomic, strong) NSMutableDictionary<NSString*,id> *extraParameters;

- (instancetype)initWithPlacementId:(NSString *)placementId;

- (void)setExtraParameterForKey:(NSString *)key value:(nullable NSString *)value;

- (void)loadAd;

- (BOOL)isReady;

- (void)showWithViewController:(UIViewController *)viewController;


@end

NS_ASSUME_NONNULL_END
