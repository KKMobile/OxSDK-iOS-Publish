//
//  ISSmaatoAdapter.h
//  ISSmaatoAdapter
//
//  Created by Hadar Pur on 04/11/2020.
//

#import <Foundation/Foundation.h>
#import "IronSource/ISBaseAdapter+Internal.h"

static NSString * const SmaatoAdapterVersion = @"4.3.9";
static NSString * GitHash = @"b750b5efc";

//System Frameworks For Smaato Adapter

@import AdSupport;
@import AVFoundation;
@import CoreMedia;
@import CoreTelephony;
@import StoreKit;
@import SafariServices;
@import SystemConfiguration;
@import WebKit;

@interface ISSmaatoAdapter : ISBaseAdapter

@end

