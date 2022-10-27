//
//  OxResBundleUtil.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/8/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface OxResBundleUtil : NSObject

+ (UIImage *)getImage:(NSString *)name;
+ (NSString *)localizedString:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
