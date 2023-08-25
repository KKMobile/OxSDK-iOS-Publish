//
//  ChangePlatformViewController.h
//  OxSDK-Game_Example
//
//  Created by 耿志向 on 2022/11/21.
//  Copyright © 2022 耿志向. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ChangePlatformViewController : UITableViewController

@property(nonatomic, copy) void (^selectPlatform)(NSInteger platform);

@end

NS_ASSUME_NONNULL_END
