//
//  OMApsRequest.h
//  OpenMediation
//
//  Created by 耿志向 on 2022/11/16.
//  Copyright © 2022 AdTiming. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OMApsRequest : NSObject

+ (void)postWithFileHash:(NSString *)fileHash pid:(NSString *)pid;


@end

NS_ASSUME_NONNULL_END
