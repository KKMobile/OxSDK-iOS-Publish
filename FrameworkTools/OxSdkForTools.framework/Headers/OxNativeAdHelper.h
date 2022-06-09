//
//  OxNativeAdHelper.h
//  SwithMediationDemo
//
//  Created by Rober on 2022/4/12.
//

#import "OxAdHelper.h"
#import "INativeViewAd.h"
#import "NativeAdDelegate.h"
#import "NativeInternalAdDelegate.h"
NS_ASSUME_NONNULL_BEGIN

@interface OxNativeAdHelper : OxAdHelper<INativeViewAd>
@property(nonatomic, weak) id<NativeInternalAdDelegate> mInternalAddelegate;
@property (nonatomic, weak)id<NativeAdDelegate> mAddelegate;

@property (nonatomic, strong) UIView   *resultNativeV;
@property (nonatomic, assign) bool   mIsReady;
@property (nonatomic, strong) NSString *loadPlacement;

- (void)createAd;

@end

NS_ASSUME_NONNULL_END
