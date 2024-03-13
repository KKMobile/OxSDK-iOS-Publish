//
//  ConsentDialogListener.h
//  Pods
//
//  Created by Mavl_2023_100272 on 2023/5/31.
//

#import <Foundation/Foundation.h>

@protocol OxConsentDialogDelegate <NSObject>

- (void)onConsentDialogResult:(BOOL)shouldShow;

@end

