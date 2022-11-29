// Copyright 2020 ADTIMING TECHNOLOGY COMPANY LIMITED
// Licensed under the GNU Lesser General Public License Version 3

#import <Foundation/Foundation.h>
#import "OMAdSingletonInterface.h"
#import "OMNativeDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface OMNativeManager : OMAdSingletonInterface

@property (nonatomic, strong) NSMutableDictionary *nativeBuilderDic;

//+ (instancetype)sharedInstance;
- (instancetype)initWithPlacementID:(NSString *)placementID;

/// Add delegate
- (void)addDelegate:(id<OMNativeDelegate>)delegate;

/// Remove delegate
- (void)removeDelegate:(id<OMNativeDelegate>)delegate;

- (void)loadWithPlacementID:(NSString*)placementID;

@end

NS_ASSUME_NONNULL_END
