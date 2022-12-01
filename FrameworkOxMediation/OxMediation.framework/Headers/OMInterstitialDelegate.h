// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class OMInterstitial;

@protocol OMInterstitialDelegate <NSObject>

@optional
- (void)omInterstitialDidLoad:(OMInterstitial *)interstitial;

- (void)omInterstitialFailToLoad:(OMInterstitial *)interstitial withError:(NSError *)error;

/// Sent immediately when a interstitial video is opened.
- (void)omInterstitialDidOpen:(OMInterstitial *)interstitial;

/// Sent immediately when a interstitial video starts to play.
- (void)omInterstitialDidShow:(OMInterstitial *)interstitial;

/// Sent after a interstitial video has been clicked.
- (void)omInterstitialDidClick:(OMInterstitial *)interstitial;

/// Sent after a interstitial video has been closed.
- (void)omInterstitialDidClose:(OMInterstitial *)interstitial;

/// Sent after a interstitial video has failed to play.
- (void)omInterstitialDidFailToShow:(OMInterstitial *)interstitial withError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
