// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import "OMBaseCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@protocol OMNativeCustomEvent;

@protocol nativeCustomEventDelegate <OMCustomEventDelegate>
- (void)nativeCustomEventWillShow:(id)adObject;
- (void)nativeCustomEventDidClick:(id)adObject;

@end

@protocol OMNativeCustomEvent<OMBaseCustomEvent>

@property (nonatomic, weak) id<nativeCustomEventDelegate> delegate;
- (instancetype)initWithParameter:(NSDictionary*)adParameter rootVC:(UIViewController*)rootViewController;

@optional
// Max 专用
- (void)setViewBinder:(UIView *)view;
@end

NS_ASSUME_NONNULL_END
