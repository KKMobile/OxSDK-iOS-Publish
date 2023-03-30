// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMNativeDelegate.h"
#import "OMAdHelperCustomEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMNativeManager : NSObject <OMNativeDelegate,OMAdHelperCustomEvent>

@property (nonatomic, weak) id<OMNativeDelegate> delegate;
@property (nonatomic, strong) OMNative *native;

- (instancetype)initWithPlacementId:(NSString *)placementId;
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
