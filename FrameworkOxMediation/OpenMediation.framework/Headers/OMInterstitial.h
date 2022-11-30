// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OMInterstitialDelegate.h"
#import "OMInterstitialAd.h"


NS_ASSUME_NONNULL_BEGIN

@interface OMInterstitial : NSObject <InterstitialDelegate>

@property (nonatomic, weak) id<OMInterstitialDelegate> delegate;
@property (nonatomic, strong) NSMutableDictionary<NSString*,id> *extraParameters;
@property (nonatomic, strong) OMInterstitialAd *interstitialAd;

- (instancetype)initWithPlacementId:(NSString *)placementId;

- (void)setExtraParameterForKey:(NSString *)key value:(nullable NSString *)value;

- (void)loadAd;

- (BOOL)isReady;

- (void)showWithViewController:(UIViewController *)viewController;


@end

NS_ASSUME_NONNULL_END
